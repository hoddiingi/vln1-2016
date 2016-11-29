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
    void setName(string name);
    void setGender(char gender);
    void setBirth(int birth);
    void setDeath(int death);

private:
    string _name;
    char _gender;
    int _birth;
    int _death;
};

#endif // PERSON_H