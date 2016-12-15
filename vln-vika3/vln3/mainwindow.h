#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "person.h"
#include "computer.h"
#include "domain.h"
#include "data.h"
#include "editscientistsdialog.h"
#include "editcomputersdialog.h"
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
    void on_table_computers_clicked();              //For button edit and remove
    void on_table_scientists_clicked();             //For button edit and remove
    void on_button_add_scientist_clicked();                                 //For when we click to add a scientist
    void on_button_add_computer_clicked();                                  //For when we click to add a computer
    void on_input_filter_scientist_textChanged(const QString &arg1);        //For search a scientist
    void on_input_filter_computers_textChanged(const QString &arg1);        //For search a computer
    void on_button_edit_scientist_clicked();                                //For edit scientist
    void on_button_remove_computer_clicked();                               //For remove one computer
    void on_button_remove_scientist_clicked();                              //For remove one scientist
    void on_button_remove_connections_clicked();                            //For remove one connection
    void on_button_removeAll_computers_clicked();                           //For remove all computer
    void on_button_removeAll_scientists_clicked();                          //For remove all scientists
    void on_table_connections_clicked();            //For button edit and remove
    void on_button_add_connections_clicked();                               //For add a connections
    void on_button_edit_computer_clicked();                                 //For edit a computer
    void on_button_removeAll_connections_clicked();                         //For remove all connections

private:

    void displayAllComputers();                                     //Display all computers from SQLite
    void displayComputers(std::vector<Computer> computers);         //Gets computer from vector to display
    void displayAllScientists();                                    //Display all scientists from SQLite
    void displayScientists(std::vector<Person> scientists);         //Gets scientist from vector to display
    void displayAllConnections();                                   //Display all connections from SQLite
    void displayConnections(std::vector<Connection> connections);   //Gets connection from vector to display

    vector<Computer> _currentlyDisplayedComputer;                   //Private member variables
    vector<Person> _currentlyDisplayedScientist;
    vector<Connection> _currentlyDisplayedConnection;
    Person _persons;
    Domain _dom;
    Data _dat;
    //editscientistsdialog _editSci;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
