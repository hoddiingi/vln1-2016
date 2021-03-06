#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "domain.h"
#include "mainwindow.h"

namespace Ui {
class addComputerDialog;
}

class addComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addComputerDialog(QWidget *parent = 0);
    ~addComputerDialog();

private slots:
    void on_buttonBox_accepted();                       //Virkni fyrir staðfestingatakka þegar bætt er við tölvu
    bool validYear(QString n);                          //Villutékkar innslátt fyrir add

private:
    Ui::addComputerDialog *ui;
    Domain _dom;
};

#endif // ADDCOMPUTERDIALOG_H
