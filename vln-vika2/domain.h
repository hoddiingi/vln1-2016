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
    //Sorting functions
    void search();
    vector<Person> search(vector<Person>& p, string name);
    int findAge(Person& sciAge) const;
<<<<<<< HEAD
    /*

      getWriteData


     */
=======
    vector<Person> readData();
    bool addPerson(Person p);
    bool addComputer(Computer c);
>>>>>>> 917080472a1459a9ef993348dba97ab4c67abe8f

private:
    friend bool operator < (const Person& lsh, const Person& rhs);
    friend bool operator < (const Person& lsh, const Person& rhs);
    Data _dat;
};

#endif // DOMAIN_H
