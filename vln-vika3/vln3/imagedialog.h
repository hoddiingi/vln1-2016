#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H
#include <QFileDialog>
#include <QPixmap>
#include <QDialog>
#include "domain.h"

namespace Ui {
class imagedialog;
}

class imagedialog : public QDialog
{
    Q_OBJECT

public:
    explicit imagedialog(QWidget *parent = 0);
    ~imagedialog();

private slots:
    void on_imageBrowse_clicked();


private:
    Ui::imagedialog *ui;
    Domain _dom;
    int currentID;
};

#endif // IMAGEDIALOG_H
