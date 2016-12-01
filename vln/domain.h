#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include "person.h"

class Domain
{
public:
    Domain();
    void sorting(int sort);
    void alphabeticSort();
    void genderSort();
    void ageSort();

private:
    vector<Person> _persSort;
};

#endif // DOMAIN_H
