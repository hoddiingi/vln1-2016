#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
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
