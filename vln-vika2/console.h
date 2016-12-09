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
    bool validName(string n);
    bool validComputerName(string n);
    bool validYear(string s);
    void validInput();
    void removeWhitespace(string& str);
    void getInfo();
    int getSort();
    void display();
    void menu(string& command);
    void add(char& anotherOne);
    //prints out the menu and ask the user for a choice
    void add(string &anotherOne);

    //adds a new scientist
    void addName(string& name);
    void addGender(string& gender);
    void addBirth(int& birth);
    void addDeath(int& death, int& birth);

    void deleteStuff();

    void addComputerName(string& computerName);
    void addYear(int& year);
    void addBuilt(string &built);
    void addType(string& type);

    void addAnother(char& anotherOne);
    //adds a new scientist's year of death if applicable
    void addAnother(string& anotherOne);
    //ask the user if he/she wants to add another scientist
    void search();
    string searchScientist();
    string searchComputer();
    void displaySearchScientist();
    void displaySearchComputer();
    void displayComputer();
    void printAllPersons();
    void displayCompIdName();
    void displaySciIdName();
    int sortBy();

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
