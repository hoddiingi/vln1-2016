#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include "data.h"



class Domain
{
public:
    Domain();
    void sorting(int sort);
    void alphabeticSort();
    void genderSort();
    void ageSort();
    void alphabeticSort(vector<Person> &alphaSort);

private:
    vector<Person> _persSort;
    friend bool operator < (const Person& lsh, const Person& rhs);
};

#endif // DOMAIN_H
