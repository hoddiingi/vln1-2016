#include "person.h"
#include "domain.h"



Person::Person()
{

}
string Person::getName() const
{
    return _name;
}
char Person::getGender() const
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
void Person::setName(string name)
{
    _name = name;
}
void Person::setGender(char gender)
{
    _gender = gender;
}
void Person::setBirth(int birth)
{
    _birth = birth;
}
void Person::setDeath(int death)
{
    _death = death;
}
