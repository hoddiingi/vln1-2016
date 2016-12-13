#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

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
        //do nothing, show error
        //ui->label_error_scientist_name->text("Name cannot be empty");
        return;
    }
    bool success =_dom.addComputer(Computer(name.toStdString(), year.toInt(), type.toStdString(), built.toStdString()), QSqlError());
    if(success)
    {
        this->done(0);
        //MainWindow ui;
        //ui.displayAllScientists();

    }
    else
    {
        this->done(-1);
        //error
    }

}
