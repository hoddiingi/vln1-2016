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


    string getName() const;             //Gets private member variables
    string getGender() const;
    int getBirth() const;
    int getDeath() const;
    int getId() const;
    int getNameSize();

private:

    int _id;                            //Private member variables
    string _name;
    string _gender;
    int _birth;
    int _death;
};

#endif // PERSON_H
