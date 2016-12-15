#ifndef EDITSCIENTISTSDIALOG_H
#define EDITSCIENTISTSDIALOG_H
#include "domain.h"
#include "mainwindow.h"
#include "person.h"
#include <QDialog>

namespace Ui {
class editscientistsdialog;
}

class editscientistsdialog : public QDialog
{
    Q_OBJECT

public:
    explicit editscientistsdialog(QWidget *parent = 0);
    ~editscientistsdialog();
    void prepareEdit(QString& id, QString& name, QString& gender, QString& birth, QString& death);

private slots:
    void on_buttonBox_accepted();                       //Edit innsláttur samþykktur
    void on_editFemale_clicked();                       //Female valið
    void on_editMale_clicked();                         //Male valið
    void on_editOther_clicked();                        //Annað kyn valið og boðið upp á innslátt
    void on_clickDeadYes_clicked(bool checked);         //Hvort að scientist sé dáinn
    bool validName(QString n);                          //Villutékk fyrir nafn
    bool validYear(QString n);                          //Villutékk fyrir ártal

private:
    vector<Computer> _currentlyDisplayedComputer;
    vector<Person> _currentlyDisplayedScientist;
    Person _persons;
    Domain _dom;
    Ui::editscientistsdialog *ui;
    int currentID;
};

#endif // EDITSCIENTISTSDIALOG_H
