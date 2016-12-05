#ifndef COMPUTER_H
#define COMPUTER_H
#include <QtSql>
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, int year, string type, char built);
    string getName() const;
    int getYear() const;
    string getType() const;
    char getBuilt() const;

private:
    string _name;
    int _year;
    string _type;
    char _built;

};

#endif // COMPUTER_H
