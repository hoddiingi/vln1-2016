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

    void on_genderFemaleButton_clicked();

    void on_genderMaleButton_clicked();

    void on_genderOtherButton_clicked();

    void on_buttonAdd_accepted();

    void on_buttonAdd_rejected();

    void on_deathYesButton_toggled(bool checked);

    bool validName(QString n);

    bool validYear(QString n);

private:
    Ui::addScientistDialog *ui;
    Person _persons;
    Domain _dom;
};

#endif // ADDSCIENTISTDIALOG_H
