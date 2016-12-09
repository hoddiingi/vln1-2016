#ifndef CONSOLE_H
#define CONSOLE_H
#include "domain.h"
#include "person.h"
#include "computer.h"
#include <QtSql>
#include <iostream>
#include <vector>

using namespace std;

class Console
{
public:
    Console();

    void menu(string& command);                 //Prints out the menu and ask the user for a choice

    void getInfo();                             //Gets input for info

    bool validName(string n);                   //Checks if inputs are valid
    bool validComputerName(string n);
    bool validYear(string s);
    void validInput();

    void add(string &anotherOne);               //Adds new info
    void addName(string& name);
    void addGender(string& gender);
    void addBirth(int& birth);
    void addDeath(int& death, int& birth);

    void addComputerName(string& computerName); //Adds new info
    void addYear(int& year);
    void addBuilt(string &built);
    void addType(string& type);
    void addAnother(char& anotherOne);          //Adds a new scientist's year of death if applicable
    void addAnother(string& anotherOne);        //Asks the user if he/she wants to add another scientist

    int addPersConnection();                    //Ask user to add connections by ID
    int addCompConnection();

    int getSort();                              //Gets input for sort
    int sortBy();                               //Gets input from user to sort

    void display();                             //Display

    void deleteStuff();                         //Delete name or the entire table

    void search();                              //Checks what the user wants to search for
    string searchScientist();
    string searchComputer();
    string searchConnection();
    vector<Person> searchSciId(int sciId);
    vector<Computer> searchCompId(int compId);

    void displaySearchScientist();              //Displays

    void displaySearchComputer();
    void displayComputer();
    void displayConnections();
    void printAllPersons();
    void displayCompIdName();
    void displaySciIdName();

    int updateBy();                             //Asks user if he wants to update scientists or computers

    string getUpdate();                         //Asks the user which scientist he/she wants to update
    string getUpdateName();                     //Asks the user for the new name
    string getUpdateGender();                   //Asks the user for the new gender
    string getUpdateBirth();                    //Asks the user for the new year of birth
    string getUpdateDeath();                    //Asks the user for the new year of death
    void update();                              //Updates scientist of choice
    string getComputerUpdate();                 //Asks the user which computer he/she wants to update
    string getUpdateComputerName();             //Asks the user for the new computer name
    string getUpdateComputerYear();             //Asks the user for the new year
    string getUpdateComputerType();             //Asks the user for the new type
    string getUpdateComputerBuilt();            //Asks the user if it was built
    void updateComputer();                      //Updates computer of choice

    void bord(char matrix[3][3]);
    void input(char& player, char matrix[3][3]);
    void changeplayer(char& player);
    char winner(char matrix[3][3]);
    int gameplay();

private:
    Domain _dom;                                //Private member variables
    Person _p;
    Computer _c;
    vector<Person> _pers;
    vector<Computer> _comp;

};

#endif // CONSOLE_H
