#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include "data.h"



class Domain
{
public:
    Domain();
    void sorting(int sort);
    vector<Person> alphabeticSort();
    void genderSort();
    void ageSort();

private:
    vector<Person> _persSort;
};

#endif // DOMAIN_H
