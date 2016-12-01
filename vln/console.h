#ifndef CONSOLE_H
#define CONSOLE_H
#include "domain.h"
#include "data.h"
#include <iostream>
#include <vector>

using namespace std;

class Console
{
public:
    Console();
    //Default constructor
    bool validYear(string s);
    void getInfo();
    int getSort();
    void displaySort(int& sort);
    void display();
    void menu(string& command);
    void add(char& anotherOne);
    void addName(string& name);
    void addGender(char& gender);
    void addBirth(int& birth);
    void addDeath(int& death, int& birth);
    void addAnother(char& anotherOne);
    string searchName();

private:
    //Member variables
    Data _dat;
    Domain _dom;
    vector<Person> _pers;
};

#endif // CONSOLE_H
