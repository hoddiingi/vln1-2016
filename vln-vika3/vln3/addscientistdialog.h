#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H
#include "data.h"
#include "mainwindow.h"
#include "person.h"
#include <QDialog>

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
    void on_nameAdd_textChanged(const QString &arg1);

    bool on_genderFemaleButton_clicked();

    bool on_genderMaleButton_clicked();

    bool on_genderOtherButton_clicked();

    void on_addBirth_textChanged(const QString &arg1);

    void on_deathYesButton_clicked();

    void on_deathNoButton_clicked();

    void on_addDeath_textChanged(const QString &arg1);

    void on_buttonAdd_accepted();

    void on_buttonAdd_rejected();

    void on_genderOtherText_textChanged(const QString &arg1);

    void on_deathYesButton_toggled(bool checked);

private:
    Ui::addScientistDialog *ui;
    Person _persons;
    Data _data;
};

#endif // ADDSCIENTISTDIALOG_H
