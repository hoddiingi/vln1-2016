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

    //Gets private member variables
    string getName() const;
    string getGender() const;
    int getBirth() const;
    int getDeath() const;
    int getId() const;
    void setDeath(int death);
    int getNameSize();

private:
    //Member variables
    int _id;
    string _name;
    string _gender;
    int _birth;
    int _death;
};

#endif // PERSON_H
