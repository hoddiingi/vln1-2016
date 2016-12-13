#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "person.h"
#include "data.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_input_filter_scientists_textChanged(const QString &arg1);
    //void on_pushBotton_clicked();

private:
    //void displayAllScientists();
    //void displayScientists(std::vector<Person> scientists);

    Person _persons;
    Data _data;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
