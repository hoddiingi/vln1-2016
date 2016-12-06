#include <iostream>
#include "console.h"
#include <QtSql>

using namespace std;

int main()
{
    Console co;

    co.getInfo();

    co.printAllPersons();
    return 0;
}
