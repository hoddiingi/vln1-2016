#include "person.h"

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
