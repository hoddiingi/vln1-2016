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
    void writeData(Person p);
    void writeCompData(Computer c);
    vector<Person> readData();
    vector<Computer> readCompData();
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
