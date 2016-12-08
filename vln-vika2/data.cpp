#include "person.h"
#include "data.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <QSqlQuery>

using namespace std;

Data::Data()
{

}

void Data::open()
{
    sqlPrufa = QSqlDatabase::addDatabase("QSQLITE");
    QString sqlPrufaName = "sqlPrufa.sqlite";
    sqlPrufa.setDatabaseName(sqlPrufaName);

    sqlPrufa.open();
    if (!sqlPrufa.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
}

void Data::close()
{
    sqlPrufa = QSqlDatabase::addDatabase("QSQLITE");
    QString sqlPrufaName = "sqlPrufa.sqlite";
    sqlPrufa.setDatabaseName(sqlPrufaName);

    sqlPrufa.close();
}

vector<Person> Data::readData()
{
    open();
    vector<Person> vect;

    QSqlQuery query("SELECT * FROM people");

    int idName   = query.record().indexOf("name");
    int idGender = query.record().indexOf("gender");
    int idBirth  = query.record().indexOf("birth");
    int idDeath  = query.record().indexOf("death");

    while (query.next())
    {
        string name = query.value(idName).toString().toStdString();
        string gender = query.value(idGender).toString().toStdString();
        int birth = query.value(idBirth).toInt();
        int death = query.value(idDeath).toInt();

        Person temp(name, gender, birth, death);
        vect.push_back(temp);
    }
    close();
    return vect;
}

vector<Computer> Data::readCompDataName()
{

    vector<Computer> vect2;

    open();

    QSqlQuery query("SELECT * FROM computers ORDER BY computername COLLATE NOCASE ASC");
    int idCompName = query.record().indexOf("computername");
    int idYear = query.record().indexOf("year");
    int idType = query.record().indexOf("type");
    int idBuilt = query.record().indexOf("built");
    while (query.next())
    {
        string name = query.value(idCompName).toString().toStdString();
        int year = query.value(idYear).toInt();
        string type = query.value(idType).toString().toStdString();
        string built = query.value(idBuilt).toString().toStdString();
        Computer temp(name, year, type, built);
        vect2.push_back(temp);
         }
    close();
    return vect2;
}
vector<Computer> Data::readCompDataYear()
{

    vector<Computer> vect2;

    open();

    QSqlQuery query("SELECT * FROM computers ORDER BY year COLLATE NOCASE ASC");
    int idCompName = query.record().indexOf("computername");
    int idYear = query.record().indexOf("year");
    int idType = query.record().indexOf("type");
    int idBuilt = query.record().indexOf("built");
    while (query.next())
    {
        string name = query.value(idCompName).toString().toStdString();
        int year = query.value(idYear).toInt();
        string type = query.value(idType).toString().toStdString();
        string built = query.value(idBuilt).toString().toStdString();
        Computer temp(name, year, type, built);
        vect2.push_back(temp);
         }
    close();
    return vect2;
}
vector<Computer> Data::readCompDataType()
{
    vector<Computer> vect2;

    open();
    QSqlQuery query("SELECT * FROM computers ORDER BY type COLLATE NOCASE ASC");
    int idCompName = query.record().indexOf("computername");
    int idYear = query.record().indexOf("year");
    int idType = query.record().indexOf("type");
    int idBuilt = query.record().indexOf("built");
    while (query.next())
    {
        string name = query.value(idCompName).toString().toStdString();
        int year = query.value(idYear).toInt();
        string type = query.value(idType).toString().toStdString();
        string built = query.value(idBuilt).toString().toStdString();
        Computer temp(name, year, type, built);
        vect2.push_back(temp);
         }
    close();
    return vect2;
}
vector<Computer> Data::readCompDataBuilt()
{
    vector<Computer> vect2;
    open();
    QSqlQuery query("SELECT * FROM computers ORDER BY built COLLATE NOCASE ASC");
    int idCompName = query.record().indexOf("computername");
    int idYear = query.record().indexOf("year");
    int idType = query.record().indexOf("type");
    int idBuilt = query.record().indexOf("built");
    while (query.next())
    {
        string name = query.value(idCompName).toString().toStdString();
        int year = query.value(idYear).toInt();
        string type = query.value(idType).toString().toStdString();
        string built = query.value(idBuilt).toString().toStdString();
        Computer temp(name, year, type, built);
        vect2.push_back(temp);
         }
    close();
    return vect2;
}
vector<Person> Data::readDataName()
{

    vector<Person> vect;

    open();

    QSqlQuery query("SELECT * FROM people ORDER BY name COLLATE NOCASE ASC");
        int idName = query.record().indexOf("name");
        int idGender = query.record().indexOf("gender");
        int idBirth = query.record().indexOf("birth");
        int idDeath = query.record().indexOf("death");
        while (query.next())
        {
            string name = query.value(idName).toString().toStdString();
            string gender = query.value(idGender).toString().toStdString();
            int birth = query.value(idBirth).toInt();
            int death = query.value(idDeath).toInt();
            Person temp(name, gender, birth, death);
            vect.push_back(temp);
         }
    close();
    return vect;
}

vector<Person> Data::readDataGender()
{

    vector<Person> vect;

    open();

    QSqlQuery query("SELECT * FROM people ORDER BY gender COLLATE NOCASE ASC");
        int idName = query.record().indexOf("name");
        int idGender = query.record().indexOf("gender");
        int idBirth = query.record().indexOf("birth");
        int idDeath = query.record().indexOf("death");
        while (query.next())
        {
            string name = query.value(idName).toString().toStdString();
            string gender = query.value(idGender).toString().toStdString();
            int birth = query.value(idBirth).toInt();
            int death = query.value(idDeath).toInt();
            Person temp(name, gender, birth, death);
            vect.push_back(temp);
         }
    close();
    return vect;
}

vector<Person> Data::readDataBirth()
{

    vector<Person> vect;

    open();

    QSqlQuery query("SELECT * FROM people ORDER BY birth COLLATE NOCASE ASC");
        int idName = query.record().indexOf("name");
        int idGender = query.record().indexOf("gender");
        int idBirth = query.record().indexOf("birth");
        int idDeath = query.record().indexOf("death");
        while (query.next())
        {
            string name = query.value(idName).toString().toStdString();
            string gender = query.value(idGender).toString().toStdString();
            int birth = query.value(idBirth).toInt();
            int death = query.value(idDeath).toInt();
            Person temp(name, gender, birth, death);
            vect.push_back(temp);
         }
    close();
    return vect;
}

vector<Person> Data::readDataDeath()
{

    vector<Person> vect;

    open();

    QSqlQuery query("SELECT * FROM people ORDER BY death COLLATE NOCASE ASC");
        int idName = query.record().indexOf("name");
        int idGender = query.record().indexOf("gender");
        int idBirth = query.record().indexOf("birth");
        int idDeath = query.record().indexOf("death");
        while (query.next())
        {
            string name = query.value(idName).toString().toStdString();
            string gender = query.value(idGender).toString().toStdString();
            int birth = query.value(idBirth).toInt();
            int death = query.value(idDeath).toInt();
            Person temp(name, gender, birth, death);
            vect.push_back(temp);
         }
    close();
    return vect;
}

bool Data::addPerson(Person p)
{
   open();

   QString name = QString::fromStdString(p.getName());
   QString gender = QString::fromStdString(p.getGender());
   int birth = p.getBirth();
   int death = p.getDeath();
   bool success = false;
   // you should check if args are ok first...

   QSqlQuery query;

   query.prepare("INSERT INTO People (name, gender, birth, death) VALUES (:name, :gender, :birth, :death)");
   query.bindValue(":name", name);
   query.bindValue(":gender", gender);
   query.bindValue(":birth", birth);
   query.bindValue(":death", death);

   if(query.exec())
   {
       success = true;
   }
   else
   {
        qDebug() << "addPerson error:  "
                 << query.lastError();
   }
   close();

   return success;
}

bool Data::addComputer(Computer c)
{
    open();
    QString name = QString::fromStdString(c.getName());
    int year = c.getYear();
    QString type = QString::fromStdString(c.getType());
    QString built = QString::fromStdString(c.getBuilt());
    bool success = false;
    // you should check if args are ok first...
    QSqlQuery query;
    query.prepare("INSERT INTO Computers (computername, year, type, built) VALUES (:computername, :year, :type, :built)");
    //query.bindValue(":id",  3);
    query.bindValue(":computername", name);
    query.bindValue(":year", year);
    query.bindValue(":type", type);
    query.bindValue(":built", built);

    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "addPerson error:  "
                 << query.lastError();
    }
    close();
    return success;
}

bool Data::removePerson(QString& name)
{
    open();
    bool success = false;
    vector<Person> result = searchName(name);

    if(result.size() > 0)
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM people WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove person failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person does not exist";
    }
    return success;
    close();
}

bool Data::removeAllPersons()
{
    open();
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM people");

    if(removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all persons failed: " << removeQuery.lastError();
    }
    close();
    return success;
}


bool Data::removeComputer(QString &name)
{
    open();
    bool success = false;
    vector<Computer> result = searchComputer(name);

    if(result.size() > 0)
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM computers WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove computer failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove computer failed: computer does not exist";
    }
    return success;
    close();
}

bool Data::removeAllComputers()
{
    open();
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM computers");

    if(removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all computers failed: " << removeQuery.lastError();
    }
    close();
    return success;
}

//Search fyrir SQLite
vector<Person> Data::searchName(QString &name)
{
    open();
    vector<Person> results;

    //Search function, we search from out vector and then put the results in another vector so it shows us all results

    string nameFind;
    string genderFind;
    int birthFind;
    int deathFind;

    QSqlQuery query(sqlPrufa);

    QString search = "SELECT * FROM people WHERE name LIKE '%" + name + "%'";

    query.prepare(search);

    query.exec();

    while(query.next())
    {
        // it exists
        nameFind = query.value("Name").toString().toStdString();
        genderFind = query.value("Gender").toString().toStdString();
        birthFind = query.value("Birth").toInt();
        deathFind = query.value("Death").toInt();
        Person p2(nameFind, genderFind, birthFind, deathFind);
        results.push_back(p2);
    }

    return results;
}

vector<Computer> Data::searchComputer(QString &computerName)
{
    open();
    vector<Computer> results;

    //Search function, we search from out vector and then put the results in another vector so it shows us all results

    string nameFind;
    int yearFind;
    string typeFind;
    string builtFind;

    QSqlQuery query(sqlPrufa);
    QString search = "SELECT * FROM computers WHERE computername LIKE (:computername)";

    query.prepare(search);
    query.bindValue(":computername", computerName);
    query.exec();

    while(query.next())
    {
        // it exists
        nameFind = query.value("computername").toString().toStdString();
        yearFind = query.value("year").toInt();
        typeFind = query.value("type").toString().toStdString();
        builtFind = query.value("built").toString().toStdString();
        Computer c(nameFind, yearFind, typeFind, builtFind);
        results.push_back(c);
    }

    close();
    return results;
}
