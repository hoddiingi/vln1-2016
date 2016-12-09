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
    //Open and close SQLite
    void open();
    void close();
    //Checks for foreign keys
    void foreignKeys();

    //Reads info from table in SQLite and stores it in vector
    vector<Computer> readCompData(string orderBy, bool isAsc);
    vector<Person> readSciData(string orderBy, bool isAsc);

    //Add info to table in SQLite
    bool addPerson(Person p);
    bool addComputer(Computer c);
    bool addConnections(int personID, int computerID);

    //Remove from table in SQLite
    bool removePerson(QString &name);
    bool removeAllPersons();
    bool removeComputer(QString &computername);
    bool removeAllComputers();

    //Search in vector for name or computer
    vector<Person> searchName(QString &name);
    vector<Computer> searchComputer(QString &computerName);

private:
    //Member variables
    vector<Person> _persons;
    vector<Computer> _computers;
    QSqlDatabase sqlPrufa;
};

#endif // DATA_H
