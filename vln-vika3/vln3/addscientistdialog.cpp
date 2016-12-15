#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"
#include <cctype>
#include <ctype.h>
#include <QMessageBox>


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

void addScientistDialog::on_genderFemaleButton_clicked()
{
    ui->genderOtherText->setEnabled(false);
}

void addScientistDialog::on_genderMaleButton_clicked()
{
    ui->genderOtherText->setEnabled(false);
}

void addScientistDialog::on_genderOtherButton_clicked()
{
    ui->genderOtherText->setEnabled(true);
}

void addScientistDialog::on_buttonAdd_accepted()
{
    QString name = ui->nameAdd->text();
    QString birth = ui->addBirth->text();
    QString deathInput = ui->addDeath->text();
    QString death = ui->addDeath->text();
    QString gender;
    if(ui->genderMaleButton->isChecked())
        gender = "Male";
    else if(ui->genderFemaleButton->isChecked())
        gender = "Female";
    else if(ui->genderOtherButton->isChecked())
        gender = ui->genderOtherText->text();
    if((!validName(name)) || name.isEmpty())
    {
        //do nothing, show error
        //ui->label_error_scientist_name->text("Name cannot be empty", );
        QMessageBox::warning(this, "Error in name", "Invalid input, name can not be blank or include numbers.");
        addScientistDialog retry;
        retry.exec();
    }
    else if(!validYear(birth) || birth.isEmpty())
    {
        QMessageBox::warning(this, "Error in birth year", "Invalid input, birth year can not be blank and only include numbers");
        addScientistDialog retry;
        retry.exec();
    }
    else if(!validYear(deathInput))
    {
        QMessageBox::warning(this, "Error in death year", "Invalid input, years can only include numbers");
        addScientistDialog retry;
        retry.exec();
    }
    else if(birth > "2016")
    {
        QMessageBox::warning(this, "Error in birth year", "Scientist not born yet");
        addScientistDialog retry;
        retry.exec();
    }
    else if(death > "2016")
    {
        QMessageBox::warning(this, "Error in death year", "Can you tell the future?");
        addScientistDialog retry;
        retry.exec();
    }
    else
    {
        _dom.addPerson(Person(name.toStdString(), gender.toStdString(), birth.toInt(), death.toInt()));
        this->done(0);
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
    for (int i = 0; i < n.size(); i++)
    {
        if (isdigit(number[i]))
        {
            return 0;
        }
    }
    return 1;
}

bool addScientistDialog::validYear(QString n)
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
