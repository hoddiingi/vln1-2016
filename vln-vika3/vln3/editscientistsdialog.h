#ifndef EDITSCIENTISTSDIALOG_H
#define EDITSCIENTISTSDIALOG_H
#include "data.h"
#include "mainwindow.h"
#include "person.h"
#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class editscientistsdialog;
}

class editscientistsdialog : public QDialog
{
    Q_OBJECT

public:
    explicit editscientistsdialog(QWidget *parent = 0);
    ~editscientistsdialog();

private slots:
    void on_buttonBox_accepted();

    bool on_editFemale_clicked();

    bool on_editMale_clicked();

    bool on_editOther_clicked();

    void on_checkBox_clicked();

    void on_clickDeadYes_clicked();

private:
    Ui::editscientistsdialog *ui;
    Data _data;
};

#endif // EDITSCIENTISTSDIALOG_H
