#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"
#include <QMessageBox>

addComputerDialog::addComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerDialog)
{
    ui->setupUi(this);
}

addComputerDialog::~addComputerDialog()
{
    delete ui;
}

void addComputerDialog::on_buttonBox_accepted()
{
    QString name = ui->nameAdd->text();
    QString year = ui->addYear->text();
    QString type = ui->addType->text();
    QString built;
    if(ui->builtYesButton->isChecked())
        built = "Yes";
    else if(ui->builtNoButton->isChecked())
        built = "No";

    if(name.isEmpty())
    {
        QMessageBox::warning(this, "Error in name", "Invalid input, name can not be blank.");
        addComputerDialog retry;
        retry.exec();
    }
    else if(!validYear(year) || year.isEmpty())
    {
        QMessageBox::warning(this, "Error in year", "Invalid input, year can not be blank and only include numbers");
        addComputerDialog retry;
        retry.exec();
    }
    else if(type.isEmpty())
    {
        QMessageBox::warning(this, "Error in type", "Invalid input, type can not be empty.");
        addComputerDialog retry;
        retry.exec();
    }
    else if(year > "2016")
    {
        QMessageBox::warning(this, "Error in year", "This year is in the future");
        addComputerDialog retry;
        retry.exec();
    }
    else
    {
        _dom.addComputer(Computer(name.toStdString(), year.toInt(), type.toStdString(), built.toStdString()), QSqlError());
        this->done(0);
    }
}

bool addComputerDialog::validYear(QString n)
{
    std::string number = n.toStdString();
    for (int i = 0; i < n.size(); i++)
    {
        if (!isdigit(number[i]))
        {
            return 0;
        }
    }
    return 1;
}
