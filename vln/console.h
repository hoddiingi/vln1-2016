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

private:
    Data _dat;
    Domain _dom;
};

#endif // CONSOLE_H
