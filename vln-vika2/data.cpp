#include "person.h"
#include "data.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

Data::Data()
{
    //_persons = readData();
}

void Data::writeData(Person p)
{
   /* ofstream out;
    out.open("text.txt", std::ios_base::app);

    out << p.getName() << endl;
    out << p.getGender() << endl;
    out << p.getBirth() << endl;
    out << p.getDeath() << endl;

    out.close();


    QString name = QString::fromStdString(p.getName());
//    QString gender = QString::fromStdString(p.getGender());
  //  QString birth = QString::fromStdString(p.getBirth());
    //QString death = QString::fromStdString(p.getDeath());


    QSqlQuery query;
    query.prepare("INSERT INTO people (name) VALUES (name)");
   // query.bindValue("name", name);
*/

}

void Data::writeCompData(Computer c)
{
    ofstream out;
    out.open("text.txt", std::ios_base::app);

    out << c.getName() << endl;
    out << c.getYear() << endl;
    out << c.getType() << endl;
    out << c.getBuilt() << endl;

    out.close();
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

Data::Data(const QString& path)
{
   sqlPrufa = QSqlDatabase::addDatabase("QSQLITE");
   QString sqlPrufaName = "sqlPrufa.sqlite";
   sqlPrufa.setDatabaseName(sqlPrufaName);


   if (!sqlPrufa.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }
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

   return success;
}

void Data::open()
{
    sqlPrufa = QSqlDatabase::addDatabase("QSQLITE");
    QString sqlPrufaName = "sqlPrufa.sqlite";
    sqlPrufa.setDatabaseName(sqlPrufaName);


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
    sqlPrufa.close();
}
