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
    void getInfo();
    int getSort();
    bool validYear(string s);
    void display();
<<<<<<< HEAD
    void displaySort(int& sort);
=======
    void addName(string& name);
    void addGender(char& gender);
    void addBirth(int& birth);
    void addDeath(int& death, int& birth);
    void addAnother(char& anotherOne);
    void add(char& anotherOne);
>>>>>>> e2c3dcb141946fdc315ab122bb149543bfaf3df2

private:
    Data _dat;
    Domain _dom;
    vector<Person> _pers;
};

#endif // CONSOLE_H
