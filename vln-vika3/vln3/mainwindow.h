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

    void on_table_computers_clicked(const QModelIndex &index);

private:
    //void displayAllScientists();
    //void displayScientists(std::vector<Person> scientists);
    void displayAllComputers();
    void displayComputers(std::vector<Computer> computers);

    Person _persons;
    Data _data;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
