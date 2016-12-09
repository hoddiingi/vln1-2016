#ifndef COMPUTER_H
#define COMPUTER_H
#include <QtSql>
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, int year, string type, string built);
    Computer(int id, string name, int year, string type, string built);
    string getName() const;
    int getYear() const;
    string getType() const;
    string getBuilt() const;
    int getNameSize2();
    int getTypeSize();
    int getId() const;

private:
    int _id;
    string _name;
    int _year;
    string _type;
    string _built;
};

#endif // COMPUTER_H
