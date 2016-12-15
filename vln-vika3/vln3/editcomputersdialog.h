#ifndef EDITCOMPUTERSDIALOG_H
#define EDITCOMPUTERSDIALOG_H
#include "domain.h"
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
    void on_buttonBox_accepted();                   //Edit samþykkt
    bool validYear(QString n);                      //Villutékk á ártal

private:
    Ui::editcomputersdialog *ui;
    Domain _dom;
    int currentID;
};

#endif // EDITCOMPUTERSDIALOG_H
