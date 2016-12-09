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
       //qDebug() << "Database: connection ok";
    }

    foreignKeys();
}

void Data::foreignKeys()
{
    QSqlQuery query(sqlPrufa);

    if((query.exec("PRAGMA foreign_keys;")) == 0)
    {
        query.exec("PRAGMA foreign_keys=1");
    }
}

void Data::close()
{
    QString connection;
    connection = sqlPrufa.connectionName();
    sqlPrufa.close();
    sqlPrufa = QSqlDatabase();
    QSqlDatabase::removeDatabase(connection);
}
vector<Computer> Data::readCompData(string orderBy, bool isAsc)
{

    vector<Computer> vect2;

    open();
    QString queryInput = "SELECT * FROM computers ORDER BY ";
    queryInput += QString::fromStdString(orderBy);
    queryInput += " COLLATE NOCASE";
    if(isAsc == true)
        queryInput += " ASC";
    else
        queryInput += " DESC";

    QSqlQuery query(queryInput);
        int idId = query.record().indexOf("ID");
        int idCompName = query.record().indexOf("computername");
        int idYear = query.record().indexOf("year");
        int idType = query.record().indexOf("type");
        int idBuilt = query.record().indexOf("built");
        while (query.next())
        {
            int id = query.value(idId).toInt();
            string name = query.value(idCompName).toString().toStdString();
            int year = query.value(idYear).toInt();
            string type = query.value(idType).toString().toStdString();
            string built = query.value(idBuilt).toString().toStdString();
            Computer temp(id, name, year, type, built);
            vect2.push_back(temp);
         }
    close();
    return vect2;
}

vector<int> Data::readConData()
{

    vector<int> vect;

    open();


    QSqlQuery query("SELECT * FROM connection");
        int sciId = query.record().indexOf("scientistid");
        int compId = query.record().indexOf("computerid");
        while (query.next())
        {
            int sci = query.value(sciId).toInt();
            vect.push_back(sci);
            int comp = query.value(compId).toInt();
            vect.push_back(comp);
         }
    close();
    return vect;
}

vector<Person> Data::readSciData(string orderBy, bool isAsc)
{

    vector<Person> vect;

    open();
    QString queryInput = "SELECT * FROM people ORDER BY ";
    queryInput += QString::fromStdString(orderBy);
    queryInput += " COLLATE NOCASE";
    if(isAsc == true)
        queryInput += " ASC";
    else
        queryInput += " DESC";

    QSqlQuery query(queryInput);
        int idId = query.record().indexOf("ID");
        int idName = query.record().indexOf("name");
        int idGender = query.record().indexOf("gender");
        int idBirth = query.record().indexOf("birth");
        int idDeath = query.record().indexOf("death");
        while (query.next())
        {
            int id = query.value(idId).toInt();
            string name = query.value(idName).toString().toStdString();
            string gender = query.value(idGender).toString().toStdString();
            int birth = query.value(idBirth).toInt();
            int death = query.value(idDeath).toInt();
            Person temp(id, name, gender, birth, death);
            vect.push_back(temp);
         }
    close();
    return vect;
}

bool Data::addPerson(Person p, QSqlError error)
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
       // qDebug() << "addPerson error:  " << query.lastError();
        error = query.lastError();
   }
   close();

   return success;
}
bool Data::addComputer(Computer c, QSqlError error)
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
        //qDebug() << "addPerson error:  " << query.lastError();
        error = query.lastError();
    }
    close();
    return success;
}

bool Data::addConnections(int personID, int computerID, QSqlError error)
{
    open();
    bool success = false;

    QSqlQuery query;


    query.prepare("INSERT INTO Connection (scientistID, computerID) VALUES (:scientistID, :computerID)");
    query.bindValue(":scientistID", personID);
    query.bindValue(":computerID", computerID);

    if(query.exec())
    {
        success = true;
    }
    else
    {
         //qDebug() << "addConnections error:  " << query.lastError();
        error = query.lastError();
    }

    close();
    return success;
}
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
    close();

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
    QString search = "SELECT * FROM computers WHERE computerName LIKE '%" + computerName + "%'";

    query.prepare(search);
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

    return results;
}

bool Data::removePerson(QString& name, QSqlError error)
{
    open();
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM people WHERE name = (:name)");
    qDebug() << name << endl;
    removeQuery.bindValue(":name", name);


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
/*
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
            //qDebug() << "remove person failed: " << queryDelete.lastError();
            error = queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person does not exist";
    }
    close();
    return success;*/
}

bool Data::removeAllPersons(QSqlError error)
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
        //qDebug() << "remove all persons failed: " << removeQuery.lastError();
        error = removeQuery.lastError();
    }
    close();
    return success;
}

bool Data::removeComputer(QString &computername, QSqlError error)
{
    open();
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM computers WHERE ComputerName = (:computername)");
    qDebug() << computername << endl;
    removeQuery.bindValue(":computername", computername);


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
    /*open();
    bool success = false;
    vector<Computer> result = searchComputer(computername);

    if(result.size() > 0)
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM computers WHERE computername = (:computername)");
        queryDelete.bindValue(":computername", computername);
        success = queryDelete.exec();

        if(!success)
        {
            //qDebug() << "remove computer failed: " << queryDelete.lastError();
            error = queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove computer failed: computer does not exist";
    }
    close();
    return success;*/
}

bool Data::removeAllComputers(QSqlError error)
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
        //qDebug() << "remove all computers failed: " << removeQuery.lastError();
        error = removeQuery.lastError();
    }
    close();
    return success;
}

void Data::updateScientistName(QString &name, QString &update)
{
    open();

    QSqlQuery query(sqlPrufa);

    query.exec("UPDATE People SET name='" +update+ "'"
             + "WHERE name='" +name+ "'");

    close();
}

void Data::updateScientistBirth(QString &name, QString &update)
{
    open();

    QSqlQuery query(sqlPrufa);

    query.exec("UPDATE People SET birth='" +update+ "'"
              +"WHERE name='" +name+ "'");

    close();
}
vector<Person> Data::searchSciId(int &id)
{
    open();
    vector<Person> results;

    //Search function, we search from out vector and then put the results in another vector so it shows us all results

    QString idCheck = QString::number(id);
    int idFind;
    string nameFind;
    string genderFind;
    int birthFind;
    int deathFind;

    QSqlQuery query(sqlPrufa);

    QString search = "SELECT * FROM people WHERE id LIKE " + idCheck;

    query.prepare(search);

    query.exec();

    while(query.next())
    {
        // it exists
        idFind = query.value("ID").toInt();
        nameFind = query.value("Name").toString().toStdString();
        genderFind = query.value("Gender").toString().toStdString();
        birthFind = query.value("Birth").toInt();
        deathFind = query.value("Death").toInt();
        Person p2(idFind, nameFind, genderFind, birthFind, deathFind);
        results.push_back(p2);
    }
<<<<<<< HEAD

=======
    close();
>>>>>>> d83d2c3064649a6f2a152ec25e978e04c7e62e35
    return results;
}

vector<Computer> Data::searchCompId(int &id)
{
    open();
    vector<Computer> results;

    //Search function, we search from out vector and then put the results in another vector so it shows us all results

    QString idCheck = QString::number(id);
    int idFind;
    string nameFind;
    int yearFind;
    string typeFind;
    string builtFind;

    QSqlQuery query(sqlPrufa);

    QString search = "SELECT * FROM computers WHERE id LIKE " + idCheck;

    query.prepare(search);

    query.exec();

    while(query.next())
    {
        // it exists
        idFind = query.value("ID").toInt();
        nameFind = query.value("computername").toString().toStdString();
        yearFind = query.value("year").toInt();
        typeFind = query.value("type").toString().toStdString();
        builtFind = query.value("built").toString().toStdString();
        Computer c(idFind, nameFind, yearFind, typeFind, builtFind);
        results.push_back(c);
    }
    close();
    return results;
}
void Data::updateScientistDeath(QString &name, QString &update)
{
    open();

    QSqlQuery query(sqlPrufa);

    query.exec("UPDATE People SET death='" +update+ "'"
              +"WHERE name='" +name+ "'");

    close();
}
