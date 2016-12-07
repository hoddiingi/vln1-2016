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

bool agePerson (const Person& lsh, const Person& rhs) // sort by birthyear
{
    return (lsh.getBirth() < rhs.getBirth());
}

void Domain::ageSorting(vector<Person>& ageSort) //sort by birthyear
{
    std::sort(ageSort.begin(), ageSort.end(), agePerson);
}

bool nameAlpha(const Person& lhs, const Person& rhs)
{
    return (lhs.getName() < rhs.getName());
}

void Domain::alphabeticSort(vector<Person>& alphaSort)
{
    std::sort(alphaSort.begin(), alphaSort.end(), nameAlpha);
}

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
}

vector<Person> Domain::search(vector<Person>& p, string name)
{
    vector<Person> results;
//Search function, we search from out vector and then put the results in another vector so it shows us all results
    for(unsigned int i = 0; i < p.size(); i++)
    {
        string nameFind;
        char genderFind;
        int birthFind;
        int deathFind;
        nameFind = p[i].getName();
        std::size_t found = nameFind.find(name);

        if (found!=std::string::npos)
        {
            p[i].getName();
            genderFind = p[i].getGender();
            birthFind = p[i].getBirth();
            deathFind = p[i].getDeath();
            Person p2(nameFind, genderFind, birthFind, deathFind);
            results.push_back(p2);
        }
    }
    return results;
}

vector<Person> Domain::readData()
{
    return _dat.readData();
}
bool Domain::addPerson(Person p)
{
    return _dat.addPerson(p);
}
bool Domain::addComputer(Computer c)
{
    return _dat.addComputer(c);
}
