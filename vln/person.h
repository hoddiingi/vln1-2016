#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();
    //Default constructor
    Person(string name, char gender, int birth, int death);
    string getName() const;
    char getGender() const;
    int getBirth() const;
    int getNameSize();
    int getDeath() const;
<<<<<<< HEAD
    void setDeath(int death);
    int getNameSize();
=======

>>>>>>> ecbd9676e948077bf2645549466dede4f7108cd7

private:
    //Member variables
    string _name;
    char _gender;
    int _birth;
    int _death;
};

#endif // PERSON_H
