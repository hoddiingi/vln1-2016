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
    void foreignKeys();
   // vector<Computer> readCompData();

    void readCompData();
    vector<Computer> readCompData(string orderBy, bool isAsc);
    vector<Person> readSciData(string orderBy, bool isAsc);

    bool addPerson(Person p, QSqlError error);
    bool addComputer(Computer c, QSqlError error);
    bool addConnections(int personID, int computerID, QSqlError error);

    bool removePerson(QString &name, QSqlError error);
    bool removeAllPersons(QSqlError error);
    bool removeComputer(QString &computername, QSqlError error);
    bool removeAllComputers(QSqlError error);

    vector<Person> searchName(QString &name);
    vector<Computer> searchComputer(QString &computerName);
    vector<Person> searchSciId(int &id);
    vector<Computer> searchCompId(int &id);
    vector<int> readConData();

private:
    vector<Person> _persons;
    vector<Computer> _computers;
    QSqlDatabase sqlPrufa;
};

#endif // DATA_H
