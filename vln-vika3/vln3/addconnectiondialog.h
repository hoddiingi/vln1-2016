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
    void on_buttonConnect_clicked();

    void on_buttonCancel_clicked();

    void displayScientists();

    void displayComputers();



private:
    Ui::addConnectionDialog *ui;
    Domain _dom;
    vector<Computer> _currentlyDisplayedComputer;
    vector<Person> _currentlyDisplayedScientist;
};

#endif // ADDCONNECTIONDIALOG_H
