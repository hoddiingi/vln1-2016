#ifndef DATA_H
#define DATA_H
#include <vector>
#include <string>
#include <QtSql>
#include "person.h"
#include "computer.h"

class Data
{
public:
    Data();
    void writeData(Person p);
    vector<Person> readData();
    void writeCompData(Computer c);
    vector<Computer> readCompData();

private:
    vector<Person> _persons;
    vector<Computer> _computers;
};

#endif // DATA_H
