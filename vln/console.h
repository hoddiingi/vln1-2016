#ifndef CONSOLE_H
#define CONSOLE_H
#include "data.h"
#include <iostream>
#include <vector>

using namespace std;

class Console
{
public:
    Console();
    void getInfo();
    void getSort();
    bool validYear(string s);
    Data dat;
};

#endif // CONSOLE_H
