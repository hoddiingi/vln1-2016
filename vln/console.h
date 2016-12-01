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

private:
    Data _dat;
    Domain _dom;
    vector<Person> _pers;
};

#endif // CONSOLE_H
