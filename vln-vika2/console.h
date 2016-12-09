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
    //Checks if inputs are valid
    bool validName(string n);
    bool validComputerName(string n);
    bool validYear(string s);
    void validInput();

    //Gets input for info
    void getInfo();    
    //Gets input for sort
    int getSort();
    //Display
    void display();

    void menu(string& command);
    void add(char& anotherOne);
    //Prints out the menu and ask the user for a choice
    void add(string &anotherOne);

    //Adds new info
    void addName(string& name);
    void addGender(string& gender);
    void addBirth(int& birth);
    void addDeath(int& death, int& birth);

    //Delete name or the entire table
    void deleteStuff();

    //Adds new info
    void addComputerName(string& computerName);
    void addYear(int& year);
    void addBuilt(string &built);
    void addType(string& type);
    void addAnother(char& anotherOne);//adds a new scientist's year of death if applicable
    void addAnother(string& anotherOne);//ask the user if he/she wants to add another scientist

    //Checks what the user wants to search for
    void search();
    string searchScientist();
    string searchComputer();

    //Displays
    void displaySearchScientist();
    void displaySearchComputer();
    void displayComputer();
    void printAllPersons();
    void displayCompIdName();
    void displaySciIdName();

    //Get input from user to sort
    int sortBy();

    //Ask user to add connections by ID
    int addPersConnection();
    int addCompConnection();


private:
    //Member variables
    Domain _dom;
    Person _p;
    Computer _c;
    vector<Person> _pers;
    vector<Computer> _comp;

};

#endif // CONSOLE_H
