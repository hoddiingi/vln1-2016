#include "domain.h"
#include "person.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "data.h"
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
<<<<<<< HEAD

int Domain::findAge(Person& sciAge) const
{
    int x;
    int y;
    int resultDead;
    int resultAlive;
    const int currentYear = 2016;
    x = sciAge.getDeath();
    y = sciAge.getBirth();

    if(x == 0)
    {
        resultAlive = currentYear - y;
        return resultAlive;
    }
    else
    {
    resultDead = x - y;
    return resultDead;
    }
=======
int Domain::findAge(Person& lhs,Person& rhs) const
{
    int x;
    int y;
    int result;
    x = lhs.getDeath();
    y = rhs.getBirth();
    result = x - y;
    return result;
>>>>>>> 5f6554b81ccaec67d504e6be03a2d2a394f96023
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
