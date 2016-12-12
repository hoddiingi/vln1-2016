#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}



----------


#include <iostream>
#include "console.h"
#include <QtSql>

using namespace std;

int main()
{
    Console co;
    co.getInfo();


    return 0;
}
