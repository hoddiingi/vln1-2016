#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H
#include "data.h"
#include "domain.h"
#include "mainwindow.h"
#include "person.h"
#include <QDialog>
#include <QObject>

namespace Ui {
class addScientistDialog;
}

class addScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addScientistDialog(QWidget *parent = 0);
    ~addScientistDialog();

private slots:
    void on_genderFemaleButton_clicked();                   //Female valið
    void on_genderMaleButton_clicked();                     //Male valið
    void on_genderOtherButton_clicked();                    //Annað kyn valið og boðið upp á að slá inn nýtt
    void on_buttonAdd_accepted();                           //Samþykkir add innslátt
    void on_buttonAdd_rejected();                           //Hættir við add innslátt
    void on_deathYesButton_toggled(bool checked);           //Hvort að scientist er dáinn, ef já er valið þá biður hann um ártal
    bool validName(QString n);                              //Villutékk fyrir nafn
    bool validYear(QString n);                              //Villutékk fyrir ártal

private:
    Ui::addScientistDialog *ui;
    Person _persons;
    Domain _dom;
};

#endif // ADDSCIENTISTDIALOG_H
