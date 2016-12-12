#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include <QtSql>
#include "person.h"
#include "data.h"


class Domain
{
public:
    Domain();

    int findAge(Person& sciAge) const;  //Calculates the age of a scientist

    vector<Person> readSciData(int sortedBy);
    vector<Computer> readCompData(int sortedBy);
    vector<int> readConData();

    //We use all these functions to connect from data to console

    bool addPerson(Person p, QSqlError error);
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

    bool removeAllPersons(QSqlError error);
    bool removeAllComputers(QSqlError error);
    bool removePerson(QString& name, QSqlError error);
    bool removeComputer(QString& computername, QSqlError error);
    bool removeConnection(QString &sciId, QSqlError error);
    bool removeAllConnections(QSqlError error);
    bool addConnection(int personID, int computerID, QSqlError error);

    void updateScientistName(QString &name, QString &update);
    void updateScientistGender(QString &name, QString &update);
    void updateScientistBirth(QString &name, QString &update);
    void updateScientistDeath(QString &name, QString &update);
    void updateComputerName(QString &computerName, QString &update);
    void updateComputerYear(QString &computerName, QString &update);
    void updateComputerType(QString &computerName, QString &update);
    void updateComputerBuilt(QString &computerName, QString &update);

private:
    Data _dat;          //Private member variables
};

#endif // DOMAIN_H
