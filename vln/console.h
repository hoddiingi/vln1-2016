#ifndef CONSOLE_H
#define CONSOLE_H
#include "domain.h"
#include "data.h"
#include "person.h"
#include <iostream>
#include <vector>

using namespace std;

class Console
{
public:
    Console();
    bool validName(string n);
    bool validYear(string s);
    void getInfo();
    int getSort();
    void displaySort(int& sort);
    void display();
    void menu(string& command);
    void add(char& anotherOne);
    //prints out the menu and ask the user for a choice
    void add(string &anotherOne);
    //adds a new scientist
    void addName(string& name);
    void addGender(char& gender);
    void addBirth(int& birth);
    void addDeath(int& death, int& birth);
    void addAnother(char& anotherOne);
    //adds a new scientist's year of death if applicable
    void addAnother(string& anotherOne);
    //ask the user if he/she wants to add another scientist
    string searchName();
    void displaySearch();

private:
    //Member variables
    Data _dat;
    Domain _dom;
    Person _p;
    vector<Person> _pers;
};

#endif // CONSOLE_H
