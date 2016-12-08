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
    vector<Computer> readCompData(string orderBy, bool isAsc);
    vector<Person> readSciData(string orderBy, bool isAsc);

    bool addPerson(Person p);
    bool addComputer(Computer c);
    bool addConnections(int personID, int computerID);

    bool removePerson(QString &name);
    bool removeAllPersons();
    bool removeComputer(QString &computername);
    bool removeAllComputers();

    vector<Person> searchName(QString &name);
    vector<Computer> searchComputer(QString &computerName);

private:
    vector<Person> _persons;
    vector<Computer> _computers;
    QSqlDatabase sqlPrufa;
};

#endif // DATA_H
