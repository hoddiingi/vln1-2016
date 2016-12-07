#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include <QtSql>
#include "data.h"
#include "person.h"

class Domain
{
public:
    Domain();
    void ageSorting(vector<Person>& ageSort);
    void alphabeticSort(vector<Person>& alphaSort);
    void sortingAge(vector<Person>& ageSort);
    void maleFemaleSort(vector<Person>& mfsort);
    void deathSorting(vector<Person>& deathSort);
    //Sorting functions
    void search();
    vector<Person> search(vector<Person>& p, string name);
    int findAge(Person& sciAge) const;
    vector<Person> readData();
    bool addPerson(Person p);
    bool addComputer(Computer c);
    void open();
    void close();
    bool removeAllPersons();
    bool removeAllComputers();

private:
    friend bool operator < (const Person& lsh, const Person& rhs);
    friend bool operator < (const Person& lsh, const Person& rhs);
    friend bool operator < (const Person& lhs, const Person& rhs);
    friend bool operator < (const Person& lhs, const Person& rhs);
    Data _dat;
};

#endif // DOMAIN_H
