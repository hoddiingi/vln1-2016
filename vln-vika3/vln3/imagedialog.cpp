#include "imagedialog.h"
#include "ui_imagedialog.h"
#include <QFileDialog>
#include <QPixmap>
#include "domain.h"

imagedialog::imagedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::imagedialog)
{
    ui->setupUi(this);
}

imagedialog::~imagedialog()
{
    delete ui;
}

void imagedialog::on_imageBrowse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                    "Search for image",
                                    "",
                                    "Image files (* .png *.jpg)");

    if(filePath.length())
    {
        QPixmap pixmap(filePath);
        ui->imageLabel->setPixmap(pixmap);
        ui->imageLabel->setScaledContents(true);
    }
}

