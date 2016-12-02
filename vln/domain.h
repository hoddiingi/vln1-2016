#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include "data.h"
#include "person.h"

class Domain
{
public:
    Domain();
<<<<<<< HEAD
    void ageSorting(vector<Person> &ageSort);
    void alphabeticSort(vector<Person> &alphaSort);
    void sortingAge(vector<Person> &ageSort);
    //Sort by name
=======
    void ageSorting(vector<Person>& ageSort);
    void alphabeticSort(vector<Person>& alphaSort);
    void sortingAge(vector<Person>& ageSort);
    //Sorting functions
>>>>>>> 67e20dc4f881e0301f12139181ee820013f2157d
    void search();
    vector<Person> search(vector<Person>& p, string name);
    int findAge(Person& sciAge) const;

private:
    friend bool operator < (const Person& lsh, const Person& rhs);
    friend bool operator < (const Person& lsh, const Person& rhs);
};

#endif // DOMAIN_H
