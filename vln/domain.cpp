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
}

int Domain::findAge(Person& lhs,Person& rhs) const
{
    int x;
    int y;
    int result;
    x = lhs.getDeath();
    y = rhs.getBirth();
    result = x - y;
    return result;
}

Person Domain::search(vector<Person>& p, string name)
{
    Person p1;

    for(unsigned int i = 0; i < p.size(); i++)
    {
        if(name == p[i].getName())
        {
            return p[i];
        }
    }
    return p1;
}
