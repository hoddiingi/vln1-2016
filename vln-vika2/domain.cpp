#include "domain.h"
#include "person.h"
//#include <iostream>
#include <algorithm>
#include <vector>
#include "data.h"
#include "console.h"

//using namespace std;

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

bool nameAlpha(const Person& lhs, const Person& rhs) //sort by name
{
    return (lhs.getName() < rhs.getName());
}

void Domain::alphabeticSort(vector<Person>& alphaSort) //sort by name
{
    std::sort(alphaSort.begin(), alphaSort.end(), nameAlpha);
}
bool maleFemale(const Person& lhs, const Person& rhs) //sort by f/m
{
    return (lhs.getGender() < rhs.getGender());
}

void Domain::maleFemaleSort(vector<Person>& mfsort) //sort by f/m
{
    std::sort(mfsort.begin(), mfsort.end(), maleFemale);
}
bool deathPerson(const Person& lhs, const Person& rhs) //sort by deathyear
{
    return (lhs.getDeath() < rhs.getDeath());
}

void Domain::deathSorting(vector<Person>& deathSort) //sort by deathyear
{
    std::sort(deathSort.begin(), deathSort.end(), deathPerson);
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
        string genderFind;
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
/* Search fyrir SQLite
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
        //std::size_t found = nameFind.find(name);
        QSqlQuery query;
        query.prepare("SELECT name FROM people WHERE name = (:name)");
        query.bindValue(":name", name);

        if (query.exec())
        {
           if (query.next())
           {
              // it exists
               p[i].getName();
               genderFind = p[i].getGender();
               birthFind = p[i].getBirth();
               deathFind = p[i].getDeath();
               Person p2(nameFind, genderFind, birthFind, deathFind);
               results.push_back(p2);
           }
    }
    return results;
}*/

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

void Domain::open()
{
    _dat.open();
}

void Domain::close()
{
    _dat.close();
}

bool Domain::removeAllPersons()
{
    return _dat.removeAllPersons();
}

bool Domain::removeAllComputers()
{
    return _dat.removeAllComputers();
}
