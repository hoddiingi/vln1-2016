#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(string name, int year, string type, string built)
{
    _id    = -1;
    _name  = name;
    _year  = year;
    _type  = type;
    _built = built;
}

Computer::Computer(int id, string name, int year, string type, string built)
{
    _id    = id;
    _name  = name;
    _year  = year;
    _type  = type;
    _built = built;
}

int Computer::getId() const
{
    return _id;
}

string Computer::getName() const
{
    return _name;
}

int Computer::getYear() const
{
    return _year;
}

string Computer::getType() const
{
    return _type;
}

string Computer::getBuilt() const
{
    return _built;
}

int Computer::getNameSize2()
{
    return _name.size();
}

int Computer::getTypeSize()
{
    return _type.size();
}
