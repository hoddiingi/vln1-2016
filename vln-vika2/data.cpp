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
    ofstream out;
    out.open("text.txt", std::ios_base::app);

    out << p.getName() << endl;
    out << p.getGender() << endl;
    out << p.getBirth() << endl;
    out << p.getDeath() << endl;

    out.close();

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
