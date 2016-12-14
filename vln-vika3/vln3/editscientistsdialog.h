#ifndef EDITSCIENTISTSDIALOG_H
#define EDITSCIENTISTSDIALOG_H
#include "data.h"
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

    void on_checkBox_clicked();

    void on_clickDeadYes_clicked(bool checked);

private:
    vector<Computer> _currentlyDisplayedComputer;
    vector<Person> _currentlyDisplayedScientist;
    Person _persons;
    Domain _dom;
    Ui::editscientistsdialog *ui;
    Data _data;
    int currentID;
};

#endif // EDITSCIENTISTSDIALOG_H
