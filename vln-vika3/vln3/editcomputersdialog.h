#ifndef EDITCOMPUTERSDIALOG_H
#define EDITCOMPUTERSDIALOG_H
#include "data.h"
#include <QDialog>

namespace Ui {
class editcomputersdialog;
}

class editcomputersdialog : public QDialog
{
    Q_OBJECT

public:
    explicit editcomputersdialog(QWidget *parent = 0);
    ~editcomputersdialog();
    void prepareEdit(QString& id, QString& name, QString& year, QString& type, QString& built);

private slots:

    void on_editYes_clicked();

    void on_editNo_clicked();

    void on_buttonBox_accepted();

    bool validYear(QString n);

private:
    Ui::editcomputersdialog *ui;
    Data _dat;
    int currentID;
};

#endif // EDITCOMPUTERSDIALOG_H
