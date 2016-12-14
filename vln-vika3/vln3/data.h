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
    vector<int> readConData();

    bool addPerson(Person p);                  //Add info to table in SQLite
    bool addComputer(Computer c, QSqlError error);
    bool addConnections(int personID, int computerID, QSqlError error);

    bool removePerson(QString &name);           //Remove from table in SQLite
    bool removeAllPersons();
    bool removeComputer(QString &computername);
    bool removeAllComputers();
    bool removeConnection(QString &sciId, QSqlError error);
    bool removeAllConnections(QSqlError error);

    vector<Person> searchName(QString &name);                   //Search in vector for name or computer
    vector<Computer> searchComputer(QString &computerName);
    vector<Person> searchSciId(int &id);
    vector<Computer> searchCompId(int &id);


    void updateScientistName(QString &name, QString &update);   //Updates info
    void updateScientistBirth(QString &name, QString &update);
    void updateScientistGender(QString &name, QString &update);
    void updateScientistDeath(QString &name, QString &update);
    void updateComputerName(QString &computerName, QString &update);
    void updateComputerYear(QString &computerName, QString &update);
    void updateComputerType(QString &computerName, QString &update);
    void updateComputerBuilt(QString &computerName, QString &update);
    void updateConnectionSciId(QString &scientistId, QString &update);
    void updateConnectionCompId(QString &computerId, QString &update);

    bool updateScientists(QString &id, QString &name, QString &gender, QString &birth, QString &death);

private:

    vector<Person> _persons;          //Private member variables
    vector<Computer> _computers;
    QSqlDatabase sqlPrufa;
};

#endif // DATA_H
