#ifndef CONSOLE_H
#define CONSOLE_H
#include "domain.h"
#include "data.h"
#include <iostream>
#include <vector>
#include "person.h"

using namespace std;

class Console
{
public:
    Console();
    //Default constructor
    bool validYear(string s);
    //checks every character of the year input to see if it is a digit
    void getInfo();
    //gets all the information
    int getSort();
    //ask the user how he/she want's to sort
    void displaySort(int& sort);
    //gets the sorting functions and displays a sorted list
    void display();
    //displays the scientists
    void menu(string& command);
    //prints out the menu and ask the user for a choice
    void add(string &anotherOne);
    //adds a new scientist
    void addName(string& name);
    //adds a new scientist's name
    void addGender(char& gender);
    //adds a new scientist's gender
    void addBirth(int& birth);
    //adds a new scientist's birth year
    void addDeath(int& death, int& birth);
    //adds a new scientist's year of death if applicable
    void addAnother(string& anotherOne);
    //ask the user if he/she wants to add another scientist
    string searchName();
    //ask the user for a name to search for in the file
    vector<Person> getVector();
    void displaySearch();

private:
    //Member variables
    Data _dat;
    Domain _dom;
    Person _p;
    vector<Person> _pers;
};

#endif // CONSOLE_H
