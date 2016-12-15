#ifndef DATA_H
#define DATA_H
#include <vector>
#include <string>
#include <QtSql>
#include "person.h"
#include "computer.h"
#include "connection.h"

class Data
{
public:
    Data();

    void open();                                                        //Open SQLite
    void close();                                                       //Close SQLite
    void foreignKeys();                                                 //Checks for foreign keys in SQLite

    vector<Computer> readCompData(string orderBy, bool isAsc);          //Reads info from computer table in SQLite and stores it in vector for Computer
    vector<Person> readSciData(string orderBy, bool isAsc);             //Reads info from person table in SQLite and stores it in vector for Person
    vector<Connection> readConData();                                   //Reads info from connection table in SQLite and stores it in vector for Connection

    bool addPerson(Person p);                                           //Add info for Person to table in SQLite
    bool addComputer(Computer c, QSqlError error);                      //Add info for Computer to table in SQLite
    bool addConnections(int personID, int computerID, QSqlError error); //Add info for Connection to table in SQLite

    bool removePerson(QString &name);                                   //Remove one person from table in SQLite
    bool removeAllPersons();                                            //Remove all persons from table in SQLite
    bool removeComputer(QString &computername);                         //Remove one computer from table in SQLite
    bool removeAllComputers();                                          //Remove all computers from table in SQLite
    bool removeConnection(QString &sciId, QString &compId);             //Remove one connection from table in SQLite
    bool removeAllConnections();                                        //Remove all connections from table in SQLite

    vector<Person> searchName(QString &name);                           //Search in vector for scientist name
    vector<Computer> searchComputer(QString &computerName);             //Search in vector for computer name
    vector<Person> searchSciId(int &id);                                //Search in vector for scientist Id
    vector<Computer> searchCompId(int &id);                             //Search in vector for computer Id
    vector<Connection> searchConnId(int &connId);                       //Search in vector for connections Id


    void updateScientistName(QString &name, QString &update);           //Updates info for scientist name
    void updateScientistBirth(QString &name, QString &update);          //Updates info for scientist birth
    void updateScientistGender(QString &name, QString &update);         //Updates info for scientist gender
    void updateScientistDeath(QString &name, QString &update);          //Updates info for scientist death
    void updateComputerName(QString &computerName, QString &update);    //Updates info for computer name
    void updateComputerYear(QString &computerName, QString &update);    //Updates info for computer year
    void updateComputerType(QString &computerName, QString &update);    //Updates info for computer type
    void updateComputerBuilt(QString &computerName, QString &update);   //Updates info for computer built, yes or no
    void updateConnectionSciId(QString &scientistId, QString &update);  //Updates info for Person Id
    void updateConnectionCompId(QString &computerId, QString &update);  //Updates info for Computer Id

    bool updateScientists(QString &id, QString &name, QString &gender, QString &birth, QString &death);  //Updates scientist and uses all the parameters; name, gender, birth, death
    bool updateComputers(QString& id, QString& name, QString& year, QString& type, QString& built);      //Updates computer and uses all the parameters; name, year, type, built

private:

    vector<Person> _persons;          //Private member variables
    vector<Computer> _computers;
    QSqlDatabase sqlPrufa;
};

#endif // DATA_H
