#ifndef CONSOLE_H
#define CONSOLE_H
#include "data.h"
#include "domain.h"
#include <iostream>
#include <vector>

using namespace std;

class Console
{
public:
    Console();
    void getInfo();
    void getSort();
    Data dat;

private:
};

#endif // CONSOLE_H
