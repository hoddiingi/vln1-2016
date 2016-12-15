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


    string getName() const;             //Gets private member variables for scientist name
    string getGender() const;           //Gets private member variables for scientist gender, f/m
    int getBirth() const;               //Gets private member variables for scientist birth
    int getDeath() const;               //Gets private member variables for scientist death
    int getId() const;                  //Gets private member variables for scientist Id
    int getNameSize();                  //Gets letter count for name size (Only used for table in display)

private:

    int _id;                            //Private member variables
    string _name;
    string _gender;
    int _birth;
    int _death;
};

#endif // PERSON_H
