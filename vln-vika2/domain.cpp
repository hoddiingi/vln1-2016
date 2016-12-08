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

vector<Person> Domain::searchName(QString &name)
{
    return _dat.searchName(name);
}

vector<Computer> Domain::searchComputer(QString &computerName)
{
    return _dat.searchComputer(computerName);
}

/*
vector<Person> Domain::readData()
{
    return _dat.readData();
}
*/

vector<Computer> Domain::readCompData(int sortedBy)
{
    if(sortedBy == 1)
        return _dat.readCompDataName();
    else if(sortedBy == 2)
        return _dat.readCompDataYear();
    else if(sortedBy == 3)
        return _dat.readCompDataType();
    else if(sortedBy == 4)
        return _dat.readCompDataBuilt();
}

vector<Person> Domain::readData(int sortedBy)
{
    if(sortedBy == 1)
        return _dat.readDataName();
    else if(sortedBy == 2)
        return _dat.readDataGender();
    else if(sortedBy == 3)
        return _dat.readDataBirth();
    else if(sortedBy == 4)
        return _dat.readDataDeath();
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
int Domain::sortBy()
{
    Console _con;
    return _con.sortBy();
}
bool Domain::removeAllPersons()
{
    return _dat.removeAllPersons();
}

bool Domain::removeAllComputers()
{
    return _dat.removeAllComputers();
}
