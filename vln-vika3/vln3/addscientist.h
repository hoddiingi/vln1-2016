#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H
#include "data.h"
#include "mainwindow.h"
#include "person.h"
#include <QDialog>

namespace Ui {
class addScientist;
}

class addScientist : public QDialog
{
    Q_OBJECT

public:
    explicit addScientist(QWidget *parent = 0);
    ~addScientist();

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

private:
    Ui::addScientist *ui;
    Person _persons;
    Data _data;
};

#endif // ADDSCIENTIST_H
