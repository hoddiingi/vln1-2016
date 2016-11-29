#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();

private:
    string _name;
    char _gender;
    int _birth;
    int _death;
};

#endif // PERSON_H
