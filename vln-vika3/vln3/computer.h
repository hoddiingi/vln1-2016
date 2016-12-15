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

    string getName() const;                   //Gets private member variables for computer name
    int getYear() const;                      //Gets private member variables for computer year
    string getType() const;                   //Gets private member variables for computer type
    string getBuilt() const;                  //Gets private member variables for built, yes or no
    int getNameSize2();                       //Gets letter count for computer name (Only used for table in display)
    int getTypeSize();                        //Gets type size count for computer type (Only used for table in display)
    int getId() const;                        //Gets Id for computer

private:
    int _id;                                  //Private member variables
    string _name;
    int _year;
    string _type;
    string _built;
};

#endif // COMPUTER_H
