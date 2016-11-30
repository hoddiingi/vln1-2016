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
    void readData(Person p);
    vector<string> dataVector();


private:

};

#endif // DATA_H
