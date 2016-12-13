#include "addscientist.h"
#include "ui_addscientist.h"


addScientist::addScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addScientist)
{
    ui->setupUi(this);
}

addScientist::~addScientist()
{
    delete ui;
}

void addScientist::on_nameAdd_textChanged(const QString &arg1)
{

}

bool addScientist::on_genderFemaleButton_clicked()
{
    ui->genderOtherText->setEnabled(false);
}

bool addScientist::on_genderMaleButton_clicked()
{
    ui->genderOtherText->setEnabled(false);
}

bool addScientist::on_genderOtherButton_clicked()
{
    ui->genderOtherText->setEnabled(true);
}

void addScientist::on_addBirth_textChanged(const QString &arg1)
{

}

void addScientist::on_deathYesButton_clicked()
{
    ui->addDeath->setEnabled(true);
}

void addScientist::on_deathNoButton_clicked()
{
    ui->addDeath->setEnabled(false);
}

void addScientist::on_addDeath_textChanged(const QString &arg1)
{

}

void addScientist::on_buttonAdd_accepted()
{
    QString name = ui->nameAdd->text();
    QString birth = ui->addBirth->text();
    QString death = ui->addDeath->text();
    QString gender;
    if(ui->genderMaleButton->isChecked())
        gender = "Male";
    else if(ui->genderFemaleButton->isChecked())
        gender = "Female";
    else if(ui->genderOtherButton->isChecked())
        gender = ui->genderOtherText->text();

    if(name.isEmpty())
    {
        //do nothing, show error
        //ui->label_error_scientist_name->text("Name cannot be empty");
        return;
    }
    bool success =_data.addPerson(Person(name.toStdString(), gender.toStdString(), birth.toInt(), death.toInt()));
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

void addScientist::on_buttonAdd_rejected()
{

}

void addScientist::on_genderOtherText_textChanged(const QString &arg1)
{

}
