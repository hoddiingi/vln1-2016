#ifndef ADDCONNECTIONDIALOG_H
#define ADDCONNECTIONDIALOG_H
#include "domain.h"
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class addConnectionDialog;
}

class addConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addConnectionDialog(QWidget *parent = 0);
    ~addConnectionDialog();

private slots:
    void on_buttonConnect_clicked();                    //Staðfestir valda tengingu
    void on_buttonCancel_clicked();                     //Hættir við valda tengingu
    void displayScientists();                           //Sýnir uppfærðan lista scientist eftir add
    void displayComputers();                            //Sýnir uppfærðan lista computer eftir add



private:
    Ui::addConnectionDialog *ui;
    Domain _dom;
    vector<Computer> _currentlyDisplayedComputer;
    vector<Person> _currentlyDisplayedScientist;
};

#endif // ADDCONNECTIONDIALOG_H
