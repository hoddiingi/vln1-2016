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
}

void MainWindow::displayScientists(std::vector<Person> scientists)
{
    ui->listScientist->clear();

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        Person currentScientist = scientists[i];

        ui->listScientist->addItem(QString::fromStdString(currentScientist.getName()));
    }
}

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
