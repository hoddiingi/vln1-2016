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

    void open();                                                //Open and close SQLite
    void close();
    void foreignKeys();                                         //Checks for foreign keys

    vector<Computer> readCompData(string orderBy, bool isAsc);  //Reads info from table in SQLite and stores it in vector
    vector<Person> readSciData(string orderBy, bool isAsc);

    bool addPerson(Person p, QSqlError error);                  //Add info to table in SQLite
    bool addComputer(Computer c, QSqlError error);
    bool addConnections(int personID, int computerID, QSqlError error);

    bool removePerson(QString &name, QSqlError error);           //Remove from table in SQLite
    bool removeAllPersons(QSqlError error);
    bool removeComputer(QString &computername, QSqlError error);
    bool removeAllComputers(QSqlError error);
    bool removeConnection(QString &sciId, QSqlError error);
    bool removeAllConnections(QSqlError error);

    vector<Person> searchName(QString &name);                   //Search in vector for name or computer
    vector<Computer> searchComputer(QString &computerName);
    vector<Person> searchSciId(int &id);
    vector<Computer> searchCompId(int &id);
    vector<int> readConData();

    void updateScientistName(QString &name, QString &update);   //Updates info
    void updateScientistBirth(QString &name, QString &update);
    void updateScientistDeath(QString &name, QString &update);

private:

    vector<Person> _persons;          //Private member variables
    vector<Computer> _computers;
    QSqlDatabase sqlPrufa;
};

#endif // DATA_H
