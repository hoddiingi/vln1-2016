#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include "data.h"
#include "person.h"

class Domain
{
public:
    Domain();

    void ageSorting(vector<Person>& ageSort);
    void alphabeticSort(vector<Person>& alphaSort);
    void sortingAge(vector<Person>& ageSort);
    //Sorting functions
    void search();
    vector<Person> search(vector<Person>& p, string name);
    int findAge(Person& sciAge) const;

private:
    friend bool operator < (const Person& lsh, const Person& rhs);
    friend bool operator < (const Person& lsh, const Person& rhs);
};

#endif // DOMAIN_H
