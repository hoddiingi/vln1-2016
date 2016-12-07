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
    void writeData(Person p);
    vector<Person> readData();
    void writeCompData(Computer c);
    vector<Computer> readCompData();
    Data(const QString& path);
    bool addPerson(Person p);
    bool addComputer(Computer c);
    //bool removePerson(const QString& name);
    bool removeAllPersons();
    //bool removeComputer(const QString& name);
    bool removeAllComputers();
    void open();
    void close();
    vector<Person> searchName(QString &name);

private:
    vector<Person> _persons;
    vector<Computer> _computers;
    QSqlDatabase sqlPrufa;
};

#endif // DATA_H
