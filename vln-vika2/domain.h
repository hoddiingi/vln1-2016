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

    int findAge(Person& sciAge) const;                  //Calculates the age of a scientist

    vector<Person> readSciData(int sortedBy);
    vector<Computer> readCompData(int sortedBy);

    //We use all these functions to connect from data to console

    bool addPerson(Person p);
    bool addComputer(Computer c);
    bool addConnection (int personID, int computerID);

    void ageSorting(vector<Person>& ageSort);
    void alphabeticSort(vector<Person>& alphaSort);
    void sortingAge(vector<Person>& ageSort);
    void maleFemaleSort(vector<Person>& mfsort);
    void deathSorting(vector<Person>& deathSort);

    vector<Person> searchName(QString &name);
    vector<Computer> searchComputer(QString &computerName);

    bool removeAllPersons();
    bool removeAllComputers();
    bool removePerson(QString& name);
    bool removeComputer(QString& computername);

    void updateScientistName(QString &name, QString &update);
    void updateScientistBirth(QString &birth, QString &update);
    void updateScientistDeath(QString &name, QString &update);

    int sortBy();



private:
    Data _dat;
};

#endif // DOMAIN_H
