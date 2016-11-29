#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();
    string getName() const;
    char getGender() const;
    int getBirth() const;
    int getDeath() const;

private:
    string _name;
    char _gender;
    int _birth;
    int _death;
};

#endif // PERSON_H
