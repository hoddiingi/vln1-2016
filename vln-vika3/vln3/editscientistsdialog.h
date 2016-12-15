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
    void on_buttonBox_accepted();

    bool on_editFemale_clicked();

    bool on_editMale_clicked();

    bool on_editOther_clicked();

    void on_clickDeadYes_clicked(bool checked);

    bool validName(QString n);

    bool validYear(QString n);

private:
    vector<Computer> _currentlyDisplayedComputer;
    vector<Person> _currentlyDisplayedScientist;
    Person _persons;
    Data _dat;
    Ui::editscientistsdialog *ui;
    int currentID;
};

#endif // EDITSCIENTISTSDIALOG_H
