#include "editcomputersdialog.h"
#include "ui_editcomputersdialog.h"
#include <QMessageBox>

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

    if(name.isEmpty())
    {
        QMessageBox::warning(this, "Error in name", "Invalid input, name can not be blank.");
        this->done(-1);
    }
    else if(!validYear(year) || year.isEmpty())
    {
        QMessageBox::warning(this, "Error in year", "Invalid input, year can not be blank and only include numbers");
        this->done(-1);
    }
    else if(type.isEmpty())
    {
        QMessageBox::warning(this, "Error in type", "Invalid input, type can not be empty.");
        this->done(-1);
    }
    else if(year > "2016")
    {
        QMessageBox::warning(this, "Error in year", "This year is in the future");
        this->done(-1);
    }
    else
    {
         _dom.updateComputers(id, name, year, type, built);
        this->done(0);
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

bool editcomputersdialog::validYear(QString n)
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
