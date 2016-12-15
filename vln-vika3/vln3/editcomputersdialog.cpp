#include "editcomputersdialog.h"
#include "ui_editcomputersdialog.h"

editcomputersdialog::editcomputersdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcomputersdialog)
{
    ui->setupUi(this);
}

editcomputersdialog::~editcomputersdialog()
{
    delete ui;
}


void editcomputersdialog::on_editYes_clicked()
{

}

void editcomputersdialog::on_editNo_clicked()
{

}

void editcomputersdialog::on_buttonBox_accepted()
{
    QString id = QString::number(currentID);
    QString name = ui->editName->text();
    QString year = ui->editYear->text();
    QString type = ui->editType->text();
    QString built;
    if(ui->editYes->isChecked())
       built = "Yes";
    else if(ui->editNo->isChecked())
       built = "No";

    bool success = _dom.updateComputers(id, name, year, type, built);

    if(success)
    {
       this->done(0);
    }
    else
    {
       this->done(-1);
       //error
    }
}

void editcomputersdialog::prepareEdit(QString& id, QString& name, QString& year, QString& type, QString& built)
{
     ui->editName->setText(name);
     ui->editYear->setText(year);
     ui->editType->setText(type);

     if(built == "Yes")
        ui->editYes->setChecked(true);
     else if(built == "No")
        ui->editNo->setChecked(true);

     currentID = id.toInt();
}
