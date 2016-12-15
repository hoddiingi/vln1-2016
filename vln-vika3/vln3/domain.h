#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include <QtSql>
#include "person.h"
#include "data.h"
#include <string>

class Domain
{
public:
    Domain();

    int findAge(Person& sciAge) const;                  //Calculates the age of a scientist

    //We use all these functions to connect from data to console, more information is in data.h
    vector<Person> readSciData(int sortedBy);
    vector<Computer> readCompData(int sortedBy);
    vector<Connection> readConData();

    bool addPerson(Person p);
    bool addComputer(Computer c, QSqlError error);
    bool addConnection (int personID, int computerID);

    void ageSorting(vector<Person>& ageSort);
    void alphabeticSort(vector<Person>& alphaSort);
    void sortingAge(vector<Person>& ageSort);
    void maleFemaleSort(vector<Person>& mfsort);
    void deathSorting(vector<Person>& deathSort);

    vector<Person> searchName(QString &name);
    vector<Computer> searchComputer(QString &computerName);
    vector<Person> searchSciId(int &id);
    vector<Computer> searchCompId(int &id);

    void open();
    void close();
    int sortBy();

    bool removeAllPersons();
    bool removeAllComputers();
    bool removePerson(QString& name);
    bool removeComputer(QString& computername);
    bool removeConnection(QString &sciId, QString &compId);
    bool removeAllConnections();
    bool addConnection(int personID, int computerID, QSqlError error);

    void updateScientistName(QString &name, QString &update);
    void updateScientistGender(QString &name, QString &update);
    void updateScientistBirth(QString &name, QString &update);
    void updateScientistDeath(QString &name, QString &update);
    void updateComputerName(QString &computerName, QString &update);
    void updateComputerYear(QString &computerName, QString &update);
    void updateComputerType(QString &computerName, QString &update);
    void updateComputerBuilt(QString &computerName, QString &update);

    bool updateScientists(QString &id, QString &name, QString &gender, QString &birth, QString &death);
    bool updateComputers(QString& id, QString& name, QString& year, QString& type, QString& built);


private:
    Data _dat;          //Private member variables
};

#endif // DOMAIN_H
