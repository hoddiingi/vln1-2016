#include "person.h"
#include "domain.h"
#include "data.h"
#include <string>


Person::Person()
{

}

Person::Person(string name, string gender, int birth, int death)
{
    _id     = -1;
    _name   = name;
    _gender = gender;
    _birth  = birth;
    _death  = death;
}

Person::Person(int id, string name, string gender, int birth, int death)
{
    _id     = id;
    _name   = name;
    _gender = gender;
    _birth  = birth;
    _death  = death;
}

string Person::getName() const
{
    return _name;
}

string Person::getGender() const
{
    return _gender;
}

int Person::getBirth() const
{
    return _birth;
}

int Person::getDeath() const
{
    return _death;
}

int Person::getNameSize()
{
    return _name.size();
}
