#ifndef DATA_H
#define DATA_H
#include <vector>
#include <string>
#include "person.h"

class Data
{
public:
    Data();
    void writeData(Person p);
    vector<Person> readData();


private:
    vector<Person> _persons;
};

#endif // DATA_H
