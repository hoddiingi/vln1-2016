#include "editscientistsdialog.h"
#include "ui_editscientistsdialog.h"
#include <QSqlQuery>
#include "QMessageBox"

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

    if((!validName(name)) || name.isEmpty())
    {
        //do nothing, show error
        //ui->label_error_scientist_name->text("Name cannot be empty", );
        QMessageBox::warning(this, "Error in name", "Invalid input, name can not be blank or include numbers.");
        this->done(-1);
    }
    else if(!validYear(birth) || birth.isEmpty())
    {
        QMessageBox::warning(this, "Error in birth year", "Invalid input, birth year can not be blank and only include numbers");
        this->done(-1);
    }
    else if(!validYear(death))
    {
        QMessageBox::warning(this, "Error in death year", "Invalid input, years can only include numbers");
        this->done(-1);
    }
    else
    {
        _dat.updateScientists(id,name,gender,birth,death);
        this->done(0);
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

bool editscientistsdialog::validName(QString n)
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

bool editscientistsdialog::validYear(QString n)
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



