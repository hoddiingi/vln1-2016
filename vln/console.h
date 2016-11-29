#ifndef CONSOLE_H
#define CONSOLE_H
#include "domain.h"
#include <iostream>
#include <vector>

using namespace std;

class Console
{
public:
    Console();
    void getInfo();
    int getSort();
    Domain dom;
};

#endif // CONSOLE_H
