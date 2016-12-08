#ifndef DATA_H
#define DATA_H
#include <vector>
#include <string>
#include <QtSql>
#include "person.h"
#include "computer.h"

class Data
{
public:
    Data();
    void open();
    void close();

    vector<Person> readData();
   // vector<Computer> readCompData();

    void readCompData();
    vector<Computer> readCompDataName();
    vector<Computer> readCompDataYear();
    vector<Computer> readCompDataType();
    vector<Computer> readCompDataBuilt();
    vector<Person> readDataName();
    vector<Person> readDataGender();
    vector<Person> readDataBirth();
    vector<Person> readDataDeath();

    bool addPerson(Person p);
    bool addComputer(Computer c);

    bool removePerson(QString &name);
    bool removeAllPersons();
    bool removeComputer(QString &name);
    bool removeAllComputers();

    vector<Person> searchName(QString &name);
    vector<Computer> searchComputer(QString &computerName);

private:
    vector<Person> _persons;
    vector<Computer> _computers;
    QSqlDatabase sqlPrufa;
};

#endif // DATA_H
