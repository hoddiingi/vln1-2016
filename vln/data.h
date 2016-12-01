#ifndef DATA_H
#define DATA_H
#include <vector>
#include <string>
#include "person.h"

class Data
{
public:
    Data();
    //Default constructor
    void writeData(Person p);
    //Write in file
    vector<Person> readData();
    //Open the file and write it out on the screen

private:
    //Member variables
    vector<Person> _persons;
};

#endif // DATA_H
