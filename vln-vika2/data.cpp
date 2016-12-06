#include "person.h"
#include "data.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

Data::Data()
{
    _persons = readData();
}
void Data::writeData(Person p)
{
   /* ofstream out;
    out.open("text.txt", std::ios_base::app);

    out << p.getName() << endl;
    out << p.getGender() << endl;
    out << p.getBirth() << endl;
    out << p.getDeath() << endl;

    out.close();*/


    QString name = QString::fromStdString(p.getName());
//    QString gender = QString::fromStdString(p.getGender());
  //  QString birth = QString::fromStdString(p.getBirth());
    //QString death = QString::fromStdString(p.getDeath());


    QSqlQuery query;
    query.prepare("INSERT INTO people (name) VALUES (name)");
   // query.bindValue("name", name);


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


vector<Computer> Data::readCompData()
{
    vector<Computer> vect2;
    return vect2;

}

vector<Person> Data::readData()
{
    vector<Person> vect;
    string name, genderS, birthS, deathS;
    const char *gender;
    int birth;
    int death;

    ifstream in;
    in.open("text.txt");

    if(in.fail())
    {
        exit(1);
    }
    else
    {
        while(getline(in, name))
        {
            getline(in, genderS);
            getline(in, birthS);
            getline(in, deathS);
            birth = atoi(birthS.c_str());
            gender = (genderS.c_str());
            death = atoi(deathS.c_str());
            Person temp(name, *gender, birth, death);
            vect.push_back(temp);
        }
    }
    in.close();

    return vect;
}

Data::Data(const QString& path)
{
   data = QSqlDatabase::addDatabase("QSQLITE");
   data.setDatabaseName(path);

   if (!data.open())
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
   QString name = QString::fromStdString(p.getName());
   char gender = p.getGender();
   int birth = p.getBirth();
   int death = p.getDeath();
   bool success = false;
   // you should check if args are ok first...
   QSqlQuery query;
   query.prepare("INSERT INTO people (Name, Gender, Birth, Death) VALUES (:Name, :Gender, :Birth, :Death)");
   query.bindValue(":Name",  name);
   query.bindValue(":Gender", gender);
   query.bindValue(":Birth", birth);
   query.bindValue(":Death", death);
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
