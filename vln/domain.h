#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include "person.h"

class Domain
{
public:
    Domain();
    vector<Person> readData();

    void writeData(Person p);
};

#endif // DOMAIN_H
