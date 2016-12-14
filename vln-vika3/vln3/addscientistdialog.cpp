#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"
#include <cctype>
#include <ctype.h>


addScientistDialog::addScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addScientistDialog)
{
    ui->setupUi(this);
}

addScientistDialog::~addScientistDialog()
{
    delete ui;
}

bool addScientistDialog::on_genderFemaleButton_clicked()
{
    ui->genderOtherText->setEnabled(false);
}

bool addScientistDialog::on_genderMaleButton_clicked()
{
    ui->genderOtherText->setEnabled(false);
}

bool addScientistDialog::on_genderOtherButton_clicked()
{
    ui->genderOtherText->setEnabled(true);
}

void addScientistDialog::on_buttonAdd_accepted()
{
    QString name = ui->nameAdd->text();
    if(!validName(name))
        qErrnoWarning("Name can't include letters", ui->nameAdd->text());
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
        //ui->label_error_scientist_name->text("Name cannot be empty", );
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

void addScientistDialog::on_buttonAdd_rejected()
{

}

void addScientistDialog::on_deathYesButton_toggled(bool checked)
{
    if(checked)
    {
        ui->whatYearDeadText->setEnabled(true);
        ui->addDeath->setEnabled(true);
    }
    else
    {
        ui->whatYearDeadText->setEnabled(false);
        ui->addDeath->setEnabled(false);
    }

}

bool addScientistDialog::validName(QString n)
{
    std::string number = n.toStdString();
    for (unsigned int i = 0; i < n.size(); i++)
    {
        if (isdigit(number[i]))
        {
            return 0;
        }
    }
    return 1;
}
