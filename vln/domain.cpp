#include "domain.h"
#include "person.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "data.h"
#include "person.h"
#include "console.h"

using namespace std;

Domain::Domain()
{

}

bool agePerson (const Person& lsh, const Person& rhs)
{
    return (lsh.getBirth() < rhs.getBirth());
}

void Domain::ageSorting(vector<Person> &ageSort)
{
    std::sort(ageSort.begin(), ageSort.end(), agePerson);
}

bool nameAlpha (const Person& lhs, const Person& rhs)
{
    return (lhs.getName() < rhs.getName());
}

void Domain::alphabeticSort(vector<Person> &alphaSort)
{
    std::sort(alphaSort.begin(), alphaSort.end(), nameAlpha);
    Console c;
    c.display();
}

void Domain::search()
{
    Console c;
    for(unsigned int i = 0; i < _persSort.size(); i++)
    {
        if(c.searchName() == c.getInfo()[i])

    }
}
