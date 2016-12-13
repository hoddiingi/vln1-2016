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

void editscientistsdialog::on_clickDeadYes_clicked()
{
    ui->clickDeadYes->setEnabled(true);
}

void editscientistsdialog::on_buttonBox_accepted()
{
    _data.open();
     QSqlQuery query;

    QString id = ui->editID->text();
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

    query.prepare("UPDATE People set ID='"+id+"', Name = '"+name+"', Gender = '"+gender+"', Birth = '"+birth+"', Death = '"+death+"' where ID = '"+id+"'");

    if(query.exec())
    {
        this->done(0);

    }
    //bool success =_data.addPerson(Person(name.toStdString(), gender.toStdString(), birth.toInt(), death.toInt()));
    //bool success =_data.updateScientists();//(Person(name.toStdString(), gender.toStdString(), birth.toInt(), death.toInt()));
    /*if(success)
    {
       this->done(0);
       //MainWindow ui;
       //ui.displayAllScientists();

    }
    else
    {
       this->done(-1);
       //error
    }*/
            _data.close();
}





