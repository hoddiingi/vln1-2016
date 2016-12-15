#include "addconnectiondialog.h"
#include "ui_addconnectiondialog.h"

addConnectionDialog::addConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addConnectionDialog)
{
    ui->setupUi(this);

    displayScientists();
    displayComputers();
}

addConnectionDialog::~addConnectionDialog()
{
    delete ui;
}

void addConnectionDialog::on_buttonConnect_clicked()
{
    int currentSelectedScientistIndex = ui->tableConnectionScientist->currentIndex().row();
    Person currentSelectedScientist = _currentlyDisplayedScientist.at(currentSelectedScientistIndex);
    QString personID = QString::number(currentSelectedScientist.getId());

    int currentSelectedComputerIndex = ui->tableConnectionComputer->currentIndex().row();
    Computer currentSelectedComputer = _currentlyDisplayedComputer.at(currentSelectedComputerIndex);
    QString compID = QString::number(currentSelectedComputer.getId());

    bool success =_dom.addConnection(personID.toInt(), compID.toInt(), QSqlError());
    if(success)
    {
        this->done(0);
    }
    else
    {
        this->done(-1);
    }
}

void addConnectionDialog::displayScientists()
{
    vector<Person> scientists = _dom.readSciData(1);
    ui->tableConnectionScientist->clearContents();
    ui->tableConnectionScientist->setRowCount(scientists.size());

    for (unsigned int row = 0; row < scientists.size(); row++)
    {
        Person currentScientist = scientists[row];
        QString name = QString::fromStdString(currentScientist.getName());
        ui->tableConnectionScientist->setItem(row, 0, new QTableWidgetItem(name));
    }
    _currentlyDisplayedScientist = scientists;
}

void addConnectionDialog::displayComputers()
{
    vector<Computer> computers = _dom.readCompData(1);
    ui->tableConnectionComputer->clearContents();
    ui->tableConnectionComputer->setRowCount(computers.size());

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        Computer currentComputer = computers[i];
        QString id = QString::number(currentComputer.getId());
        QString name = QString::fromStdString(currentComputer.getName());
        ui->tableConnectionComputer->setItem(i, 0, new QTableWidgetItem(name));
    }
    _currentlyDisplayedComputer = computers;
}

void addConnectionDialog::on_buttonCancel_clicked()
{
    this->done(0);
}
