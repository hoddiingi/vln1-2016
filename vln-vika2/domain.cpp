#include "domain.h"
#include "person.h"
#include <algorithm>
#include <vector>
#include "data.h"

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

vector<Person> Domain::searchSciId(int &id)
{
    return _dat.searchSciId(id);
}

vector<Computer> Domain::searchCompId(int &id)
{
    return _dat.searchCompId(id);
}

vector<Computer> Domain::readCompData(int sortedBy)
{
    if(sortedBy == 1)
        return _dat.readCompData("computername", true);
    else if(sortedBy == 2)
        return _dat.readCompData("computername", false);
    else if(sortedBy == 3)
        return _dat.readCompData("year", true);
    else if(sortedBy == 4)
        return _dat.readCompData("year", false);
    else if(sortedBy == 5)
        return _dat.readCompData("type", true);
    else if(sortedBy == 6)
        return _dat.readCompData("type", false);
    else if(sortedBy == 7)
        return _dat.readCompData("built", true);
    else if(sortedBy == 8)
        return _dat.readCompData("built", false);
    else
        return _dat.readCompData("ID", true);
}

vector<Person> Domain::readSciData(int sortedBy)
{
    if(sortedBy == 1)
        return _dat.readSciData("name", true);
    else if(sortedBy == 2)
        return _dat.readSciData("name", false);
    else if(sortedBy == 3)
        return _dat.readSciData("gender", true);
    else if(sortedBy == 4)
        return _dat.readSciData("gender", false);
    else if(sortedBy == 5)
        return _dat.readSciData("birth", true);
    else if(sortedBy == 6)
        return _dat.readSciData("birth", false);
    else if(sortedBy == 7)
        return _dat.readSciData("death", true);
    else if(sortedBy == 8)
        return _dat.readSciData("death", false);
    else
        return _dat.readSciData("ID", true);
}

vector<int> Domain::readConData()
{
    return _dat.readConData();
}

vector<Person> Domain::searchName(QString &name)
{
    return _dat.searchName(name);
}

vector<Computer> Domain::searchComputer(QString &computerName)
{
    return _dat.searchComputer(computerName);
}

bool Domain::addPerson(Person p, QSqlError error)
{
    return _dat.addPerson(p, error);
}

bool Domain::addComputer(Computer c, QSqlError error)
{
    return _dat.addComputer(c, error);
}

bool Domain::removeAllPersons(QSqlError error)
{
    return _dat.removeAllPersons(error);
}

bool Domain::removeAllComputers(QSqlError error)
{
    return _dat.removeAllComputers(error);
}

bool Domain::removePerson(QString& name, QSqlError error)
{
    return _dat.removePerson(name, error);
}

bool Domain::removeComputer(QString& computername, QSqlError error)
{
    return _dat.removeComputer(computername, error);
}

bool Domain::removeConnection(QString &sciId, QSqlError error)
{
    return _dat.removeConnection(sciId, error);
}

bool Domain::removeAllConnections(QSqlError error)
{
    return _dat.removeAllConnections(error);
}

bool Domain::addConnection(int personID, int computerID, QSqlError error)
{
    return _dat.addConnections(personID, computerID, error);
}

void Domain::updateScientistName(QString &name, QString &update)
{
    return _dat.updateScientistName(name, update);
}

void Domain::updateScientistGender(QString &name, QString &update)
{
    return _dat.updateScientistGender(name, update);
}

void Domain::updateScientistBirth(QString &name, QString &update)
{
    return _dat.updateScientistBirth(name, update);
}

void Domain::updateScientistDeath(QString &name, QString &update)
{
    return _dat.updateScientistDeath(name, update);
}

void Domain::updateComputerName(QString &computerName, QString &update)
{
    return _dat.updateComputerName(computerName, update);
}

void Domain::updateComputerYear(QString &computerName, QString &update)
{
    return _dat.updateComputerYear(computerName, update);
}

void Domain::updateComputerType(QString &computerName, QString &update)
{
    return _dat.updateComputerType(computerName, update);
}

void Domain::updateComputerBuilt(QString &computerName, QString &update)
{
    return _dat.updateComputerBuilt(computerName, update);
}
