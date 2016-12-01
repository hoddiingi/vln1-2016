#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include "data.h"



class Domain
{
public:
    Domain();
    vector<Person> alphabeticSort();
    void genderSort();
    void ageSort();
    void alphabeticSort(vector<Person> &alphaSort);
    void ageSorting(vector<Person> &ageSort);
    void search();

private:
    vector<Person> _persSort;
    friend bool operator < (const Person& lsh, const Person& rhs);
    friend bool operator < (const Person& lsh, const Person& rhs);

};

#endif // DOMAIN_H
