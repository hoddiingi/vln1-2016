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
    //Gives the private member variables the value of these variables
    string getName() const;
    char getGender() const;
    int getBirth() const;
    int getDeath() const;
    int getNameSize();

    //Gets private member variables

private:
    //Member variables
    string _name;
    char _gender;
    int _birth;
    int _death;

};

#endif // PERSON_H
