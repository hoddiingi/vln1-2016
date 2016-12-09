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
   //We use all these to connect from data to console
    void ageSorting(vector<Person>& ageSort);
    void alphabeticSort(vector<Person>& alphaSort);
    void sortingAge(vector<Person>& ageSort);
    void maleFemaleSort(vector<Person>& mfsort);
    void deathSorting(vector<Person>& deathSort);
    void search();
    vector<Person> searchName(QString &name);
    vector<Computer> searchComputer(QString &computerName);
    void updateScientistName(QString &name, QString &update);
    void updateScientistBirth(QString &birth, QString &update);
    void updateScientistDeath(QString &name, QString &update);

    vector<Person> search(vector<Person>& p, string name);
    int findAge(Person& sciAge) const;
    vector<Person> readSciData(int sortedBy);
    vector<Computer> readCompData(int sortedBy);
    bool addPerson(Person p);
    bool addComputer(Computer c);
    void open();
    void close();
    int sortBy();
    bool removeAllPersons();
    bool removeAllComputers();
    bool removePerson(QString& name);
    bool removeComputer(QString& computername);
    bool addConnection (int personID, int computerID);

private:
    Data _dat;
};

#endif // DOMAIN_H
