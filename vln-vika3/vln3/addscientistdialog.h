#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H
#include "data.h"
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


    bool on_genderFemaleButton_clicked();

    bool on_genderMaleButton_clicked();

    bool on_genderOtherButton_clicked();

    void on_buttonAdd_accepted();

    void on_buttonAdd_rejected();

    void on_deathYesButton_toggled(bool checked);

    bool validName(QString n);

    bool validYear(QString n);

private:
    Ui::addScientistDialog *ui;
    Person _persons;
    Data _data;
};

#endif // ADDSCIENTISTDIALOG_H
