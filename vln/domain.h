#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include "data.h"
#include "person.h"

class Domain
{
public:
    Domain();
    //Default constructor
    void ageSorting(vector<Person> &ageSort);
    //Sort by age
    //vector<Person> &ageSort - go trough the vector and check age
    void alphabeticSort(vector<Person> &alphaSort);
    //Sort by name
    //vector<Person> &alphaSort - go trough the vector and check name
    void search();
    Person search(vector<Person>& p, string name);

private:
    //Member variables
    //vector<Person> _persSort;
    friend bool operator < (const Person& lsh, const Person& rhs);
    //Overload the operator < for ageSorting
    friend bool operator < (const Person& lsh, const Person& rhs);
    //Orverload the operator < for alphabeticSort
    int findAge(Person& lhs,Person& rhs) const;

};

#endif // DOMAIN_H
