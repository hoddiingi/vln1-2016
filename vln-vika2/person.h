#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <QtSql>
#include <QDebug>

using namespace std;

class Person
{
public:
    Person();
    Person(int id, string name, string gender, int birth, int death);
    Person(string name, string gender, int birth, int death);
    string getName() const;
    string getGender() const;
    int getBirth() const;
    int getDeath() const;
    void setDeath(int death);
    int getNameSize();
    //Gets private member variables

private:
    int _id;
    string _name;
    string _gender;
    int _birth;
    int _death;
};

#endif // PERSON_H
