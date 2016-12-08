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
    vector<Computer> readCompDataNameAsc();
    vector<Computer> readCompDataNameDesc();
    vector<Computer> readCompDataYearAsc();
    vector<Computer> readCompDataYearDesc();
    vector<Computer> readCompDataTypeAsc();
    vector<Computer> readCompDataTypeDesc();
    vector<Computer> readCompDataBuiltAsc();
    vector<Computer> readCompDataBuiltDesc();
    vector<Person> readDataNameAsc();
    vector<Person> readDataNameDesc();
    vector<Person> readDataGenderAsc();
    vector<Person> readDataGenderDesc();
    vector<Person> readDataBirthAsc();
    vector<Person> readDataBirthDesc();
    vector<Person> readDataDeathAsc();
    vector<Person> readDataDeathDesc();

    bool addPerson(Person p);
    bool addComputer(Computer c);

    //bool removePerson(const QString& name);
    bool removeAllPersons();

    //bool removeComputer(const QString& name);
    bool removeAllComputers();
    vector<Person> searchName(QString &name);
    vector<Computer> searchComputer(QString &computerName);

private:
    vector<Person> _persons;
    vector<Computer> _computers;
    QSqlDatabase sqlPrufa;
};

#endif // DATA_H
