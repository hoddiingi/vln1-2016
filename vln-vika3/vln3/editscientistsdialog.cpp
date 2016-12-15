#include "editscientistsdialog.h"
#include "ui_editscientistsdialog.h"
#include <QSqlQuery>

editscientistsdialog::editscientistsdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editscientistsdialog)
{
    ui->setupUi(this);
}

editscientistsdialog::~editscientistsdialog()
{
    delete ui;
}

bool editscientistsdialog::on_editFemale_clicked()
{
    ui->editGender->setEnabled(false);
}

bool editscientistsdialog::on_editMale_clicked()
{
    ui->editGender->setEnabled(false);
}

bool editscientistsdialog::on_editOther_clicked()
{
    ui->editGender->setEnabled(true);
}

void editscientistsdialog::on_clickDeadYes_clicked(bool checked)
{
    ui->clickDeadYes->setEnabled(true);

    if(checked)
    {
        ui->editDeath->setEnabled(true);
        //ui->addDeath->setEnabled(true);
    }
    else
    {
        ui->editDeath->setEnabled(false);
        //ui->addDeath->setEnabled(false);
    }
}

void editscientistsdialog::on_buttonBox_accepted()
{
    QString id = QString::number(currentID);
    QString name = ui->editName->text();
    QString birth = ui->editBorn->text();
    QString death = ui->editDeath->text();
    QString gender;
    if(ui->editMale->isChecked())
       gender = "Male";
    else if(ui->editFemale->isChecked())
       gender = "Female";
    else if(ui->editOther->isChecked())
       gender = ui->editGender->text();

    bool success = _dom.updateScientists(id,name,gender,birth,death);

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

void editscientistsdialog::prepareEdit(QString& id, QString& name, QString& gender, QString& birth, QString& death)
{
     //ui->editID->setText(id);

     ui->editName->setText(name);
     ui->editBorn->setText(birth);
     ui->editDeath->setText(death);

     if(gender == "Male")
        ui->editMale->setChecked(true);
     else if(gender == "Female")
        ui->editFemale->setChecked(true);
     else
     {
        ui->editOther->setChecked(true);
        ui->editGender->setText(gender);
     }
     currentID = id.toInt();
}





