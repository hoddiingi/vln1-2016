#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllComputers();
    displayAllScientists();
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
        QString name = QString::fromStdString(currentComputer.getName());
        QString year = QString::number(currentComputer.getYear());
        QString type = QString::fromStdString(currentComputer.getType());
        QString built = QString::fromStdString(currentComputer.getBuilt());

        ui->table_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_computers->setItem(i, 1, new QTableWidgetItem(year));
        ui->table_computers->setItem(i, 2, new QTableWidgetItem(type));
        ui->table_computers->setItem(i, 3, new QTableWidgetItem(built));
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
        QString name = QString::fromStdString(currentScientist.getName());
        QString gender = QString::fromStdString(currentScientist.getGender());
        QString yearBorn = QString::number(currentScientist.getBirth());
        QString death = QString::number(currentScientist.getDeath());

        ui->table_scientists->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_scientists->setItem(row, 1, new QTableWidgetItem(gender));
        ui->table_scientists->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->table_scientists->setItem(row, 3, new QTableWidgetItem(death));
    }
      //QTableView::resizeColumnsToContents();
        _currentlyDisplayedScientist = scientists;
}
/*
void MainWindow::on_input_filter_scientists_textChanged(const QString &arg1)
{
    QString userInput = ui->input_filter_scientists->text();

    vector<Person> scientists = _data.searchName(userInput);
    displayScientists(scientists);
}

void MainWindow::on_pushBotton_clicked()
{
    QString name = ui->input_scientist_name->text();
    QString gender = ui->input_scientist_gender->text();
    QString birth = ui->input_scientist_birth->text();
    QString death = ui->input_scientist_death->text();

    if(name.isEmpty())
    {
        //do nothing, show error
        //ui->label_error_scientist_name->text("Name cannot be empty");
        return;
    }
    if(gender.isEmpty())
    {
        //do nothing
        return;
    }
    bool success =_data.addPerson(Person(name.toStdString(), gender.toStdString(), birth.toInt(), death.toInt()));
    if(success)
    {
        ui->input_filter_scientists->setText("");
        displayAllScientists();

        ui->input_scientist_name->setText("");
        ui->input_scientist_gender->setText("");
        ui->input_scientist_birth->setText("");
        ui->input_scientist_death->setText("");
    }
    else
    {
        //error
    }
}*/

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
