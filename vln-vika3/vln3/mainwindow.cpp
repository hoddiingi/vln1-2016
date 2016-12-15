#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addscientistdialog.h"
#include "addcomputerdialog.h"
#include "editscientistsdialog.h"
#include "addconnectiondialog.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllComputers();
    displayAllScientists();
    displayAllConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllComputers()
{
    vector<Computer> computers = _dom.readCompData(1);
    displayComputers(computers);
}

void MainWindow::displayComputers(std::vector<Computer> computers)
{
    ui->table_computers->clearContents();
    ui->table_computers->setRowCount(computers.size());

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        Computer currentComputer = computers[i];
        QString id = QString::number(currentComputer.getId());
        QString name = QString::fromStdString(currentComputer.getName());
        QString year = QString::number(currentComputer.getYear());
        QString type = QString::fromStdString(currentComputer.getType());
        QString built = QString::fromStdString(currentComputer.getBuilt());

        ui->table_computers->setItem(i, 0, new QTableWidgetItem(id));
        ui->table_computers->setItem(i, 1, new QTableWidgetItem(name));
        ui->table_computers->setItem(i, 2, new QTableWidgetItem(year));
        ui->table_computers->setItem(i, 3, new QTableWidgetItem(type));
        ui->table_computers->setItem(i, 4, new QTableWidgetItem(built));
        ui->table_computers->resizeColumnsToContents();
    }

    _currentlyDisplayedComputer = computers;
}

void MainWindow::displayAllScientists()
{
    vector<Person> scientists = _dom.readSciData(1);
    displayScientists(scientists);
}

void MainWindow::displayScientists(std::vector<Person> scientists)
{
    ui->table_scientists->clearContents();
    ui->table_scientists->setRowCount(scientists.size());

    for (unsigned int row = 0; row < scientists.size(); row++)
    {
        Person currentScientist = scientists[row];
        QString id = QString::number(currentScientist.getId());
        QString name = QString::fromStdString(currentScientist.getName());
        QString gender = QString::fromStdString(currentScientist.getGender());
        QString yearBorn = QString::number(currentScientist.getBirth());
        QString death = QString::number(currentScientist.getDeath());

        ui->table_scientists->setItem(row, 0, new QTableWidgetItem(id));
        ui->table_scientists->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_scientists->setItem(row, 2, new QTableWidgetItem(gender));
        ui->table_scientists->setItem(row, 3, new QTableWidgetItem(yearBorn));
        ui->table_scientists->setItem(row, 4, new QTableWidgetItem(death));
        ui->table_scientists->resizeColumnsToContents();
    }
    _currentlyDisplayedScientist = scientists;
}

void MainWindow::displayAllConnections()
{
    vector<Connection> connections = _dom.readConData();
    displayConnections(connections);
}

void MainWindow::displayConnections(std::vector<Connection> connections)
{
    ui->table_connections->clearContents();
    ui->table_connections->setRowCount(connections.size());

    vector<Person> getScientists = _dom.readSciData(1);
    vector<Computer> getComputers = _dom.readCompData(1);

    for (unsigned int row = 0; row < connections.size(); row++)
    {
        Connection currentConnection = connections[row];
        int scientistId = currentConnection.getScientistId();
        int computerId  = currentConnection.getComputerId();

        for(unsigned int i = 0; i < getScientists.size(); i++)
        {
            if(scientistId == getScientists[i].getId())
            {
                Person p = getScientists[i];
                QString sciName  = QString::fromStdString(p.getName());
                ui->table_connections->setItem(row, 0, new QTableWidgetItem(sciName));
            }
        }
        for(unsigned int j = 0; j < getComputers.size(); j++)
        {
            if(computerId == getComputers[j].getId())
            {
                Computer c = getComputers[j];
                QString compName = QString::fromStdString(c.getName());
                ui->table_connections->setItem(row, 1, new QTableWidgetItem(compName));
            }
        }
        ui->table_connections->resizeColumnsToContents();
        _currentlyDisplayedConnection = connections;
    }
    /*
    ui->table_connections->clearContents();
    ui->table_connections->setRowCount(connections.size()/2);

    vector<Person> getScientists = _dom.readSciData(1);
    vector<Computer> getComputers = _dom.readCompData(1);

    int row = 0;
    for(unsigned int main = 0; main < connections.size(); main+=2) //Table that holds together
    {
        for(unsigned int sTable = 0; sTable < getScientists.size(); sTable++) //Goes through scientist vect and check if there is a hit
        {
            int hitS = connections[main];
            if(hitS == getScientists[sTable].getId())
                ui->table_connections->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(getScientists[sTable].getName())));
        }
        for (unsigned int cTable = 0; cTable < getComputers.size(); cTable++)//Goes through computer vect and check if there is a hit
        {
            int hitC = connections[main+1];
            if(hitC == getComputers[cTable].getId())
                ui->table_connections->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(getComputers[cTable].getName())));
        }
        row++;
    }*/

}

void MainWindow::on_table_computers_clicked(const QModelIndex &index)
{
    ui->button_remove_computer->setEnabled(true);
    ui->button_edit_computer->setEnabled(true);
}
void MainWindow::on_table_scientists_clicked(const QModelIndex &index)
{
    ui->button_remove_scientist->setEnabled(true);
    ui->button_edit_scientist->setEnabled(true);
}

void MainWindow::on_table_connections_clicked(const QModelIndex &index)
{
    ui->button_remove_connections->setEnabled(true);
    ui->button_edit_connections->setEnabled(true);
}

void MainWindow::on_button_add_scientist_clicked()
{
    addScientistDialog addNew;
    int addedScientist = addNew.exec();

    if(addedScientist == 0)
    {
        displayAllScientists();
    }
    else
    {

    }
}

void MainWindow::on_input_filter_scientist_textChanged(const QString &arg1)
{
    QString userInput = ui->input_filter_scientist->text();

    vector<Person> scientists = _dom.searchName(userInput);
    displayScientists(scientists);
}

void MainWindow::on_input_filter_computers_textChanged(const QString &arg1)
{
    QString userInput = ui->input_filter_computers->text();

    vector<Computer> computers = _dom.searchComputer(userInput);
    displayComputers(computers);
}

void MainWindow::on_button_edit_scientist_clicked()
{
    Person selectedScientist;

    int row = ui->table_scientists->currentIndex().row();
    int id = ui->table_scientists->model()->data(ui->table_scientists->model()->index(row,0)).toInt();

    for(unsigned int i = 0; i < _currentlyDisplayedScientist.size(); i++)
    {
        if(_currentlyDisplayedScientist[i].getId() == id)
        {
            selectedScientist = _currentlyDisplayedScientist[i];
            break;
        }
    }

    QString sciId = QString::number(selectedScientist.getId());
    QString name = QString::fromStdString(selectedScientist.getName());
    QString gender = QString::fromStdString(selectedScientist.getGender());
    QString birth = QString::number(selectedScientist.getBirth());
    QString death = QString::number(selectedScientist.getDeath());

    editscientistsdialog edit;
    edit.prepareEdit(sciId, name, gender, birth, death);

    int editScientists = edit.exec();

    if(editScientists == 0)
    {
        displayAllScientists();
    }
    else
    {

    }
}

void MainWindow::on_button_remove_computer_clicked()
{
    int currentSelectedComputerIndex = ui->table_computers->currentIndex().row();
    Computer currentSelectedComputer = _currentlyDisplayedComputer.at(currentSelectedComputerIndex);
    QString name = QString::fromStdString(currentSelectedComputer.getName());
    bool success = _dom.removeComputer(name);

    if(success)
    {
        ui->input_filter_computers->setText("");
        displayAllComputers();

        ui->button_remove_computer->setEnabled(false);
    }
    else
    {
        //display error
    }
}

void MainWindow::on_button_remove_scientist_clicked()
{
    int currentSelectedScientistIndex = ui->table_scientists->currentIndex().row();
    Person currentSelectedScientist = _currentlyDisplayedScientist.at(currentSelectedScientistIndex);
    QString name = QString::fromStdString(currentSelectedScientist.getName());
    bool success = _dom.removePerson(name);

    if(success)
    {
        ui->input_filter_scientist->setText("");
        displayAllScientists();

        ui->button_remove_scientist->setEnabled(false);
    }
    else
    {
        //display error
    }
}

void MainWindow::on_button_remove_connections_clicked()
{
    int currentSelectedConnectionIndex = ui->table_connections->currentIndex().row();
    Connection currentSelectedConnection = _currentlyDisplayedConnection.at(currentSelectedConnectionIndex);

    QString scientistId = QString::number(currentSelectedConnection.getScientistId());
    QString computerId  = QString::number(currentSelectedConnection.getComputerId());

    bool success = _dom.removeConnection(scientistId, computerId);

    if(success)
    {
        displayAllConnections();

        ui->button_remove_connections->setEnabled(false);
    }
    else
    {
        //display error
    }
}


void MainWindow::on_button_removeAll_computers_clicked()
{
    ui->table_computers->clearSelection();
    ui->table_computers->disconnect();
    ui->table_computers->clearContents();
    ui->table_computers->setRowCount(0);

    _dom.removeAllComputers();
}

void MainWindow::on_button_removeAll_scientists_clicked()
{
    ui->table_scientists->clearSelection();
    ui->table_scientists->disconnect();
    ui->table_scientists->clearContents();
    ui->table_scientists->setRowCount(0);

    _dom.removeAllPersons();
}

void MainWindow::on_button_removeAll_connections_clicked()
{
    ui->table_connections->clearSelection();
    ui->table_connections->disconnect();
    ui->table_connections->clearContents();
    ui->table_connections->setRowCount(0);

    _dom.removeAllConnections();
}

void MainWindow::on_button_add_computer_clicked()
{
    addComputerDialog addNewComp;
    int addedComputer = addNewComp.exec();

    if(addedComputer == 0)
    {
        displayAllComputers();
    }
    else
    {
        //error
    }
}

void MainWindow::on_button_add_connections_clicked()
{
    addConnectionDialog addNewConn;
    int addedConnection = addNewConn.exec();

    if(addedConnection == 0)
    {
        displayAllConnections();
    }
    else
    {
        //error
    }
}

void MainWindow::on_button_edit_computer_clicked()
{
    Computer selectedComputer;

    int row = ui->table_computers->currentIndex().row();
    int id = ui->table_computers->model()->data(ui->table_computers->model()->index(row,0)).toInt();

    for(unsigned int i = 0; i < _currentlyDisplayedComputer.size(); i++)
    {
        if(_currentlyDisplayedComputer[i].getId() == id)
        {
            selectedComputer = _currentlyDisplayedComputer[i];
            break;
        }
    }

    QString cpuId = QString::number(selectedComputer.getId());
    QString name = QString::fromStdString(selectedComputer.getName());
    QString year = QString::number(selectedComputer.getYear());
    QString type = QString::fromStdString(selectedComputer.getType());
    QString built = QString::fromStdString(selectedComputer.getBuilt());

    editcomputersdialog edit;

    edit.prepareEdit(cpuId, name, year, type, built);

    int editComputers = edit.exec();

    if(editComputers == 0)
    {
        displayAllComputers();
    }
    else
    {

    }
}

