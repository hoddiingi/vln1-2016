#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //displayAllScientists();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::displayAllScientists()
{
    vector<Person> scientists = _data.readSciData("name", true);
    displayScientists(scientists);
}*/
/*
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
}*/
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
