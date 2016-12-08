#ifndef DOMAIN_H
#define DOMAIN_H
#include <vector>
#include <QtSql>
//#include "console.h"
#include "person.h"
#include "data.h"


class Domain
{
public:
    Domain();
    void ageSorting(vector<Person>& ageSort);
    void alphabeticSort(vector<Person>& alphaSort);
    void sortingAge(vector<Person>& ageSort);
    void maleFemaleSort(vector<Person>& mfsort);
    void deathSorting(vector<Person>& deathSort);
    //Sorting functions
    void search();
    vector<Person> searchName(QString &name);
    vector<Computer> searchComputer(QString &computerName);
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
    //Console _con;

};

#endif // DOMAIN_H
