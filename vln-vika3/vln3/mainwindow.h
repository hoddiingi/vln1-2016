#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "person.h"
#include "domain.h"
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
    void on_table_scientists_clicked(const QModelIndex &index);
    void on_button_add_scientist_clicked();
    void on_button_add_computer_clicked();
    void on_input_filter_scientist_textChanged(const QString &arg1);
    void on_input_filter_computers_textChanged(const QString &arg1);
    void on_button_edit_scientist_clicked();
    void on_button_remove_computer_clicked();
    void on_button_remove_scientist_clicked();

    void on_button_remove_connections_clicked();

    void on_button_removeAll_computers_clicked();
    void on_button_removeAll_scientists_clicked();


    void on_table_connections_clicked(const QModelIndex &index);

private:

    void displayAllComputers();
    void displayComputers(std::vector<Computer> computers); 
    void displayAllScientists();
    void displayScientists(std::vector<Person> scientists);
    void displayAllConnections();
    void displayConnections(std::vector<int> connections);

    vector<Computer> _currentlyDisplayedComputer;
    vector<Person> _currentlyDisplayedScientist;
    Person _persons;
    Domain _dom;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
