#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, char gender, int birth, int death);
    string getName() const;
    void setName(string name);
    char getGender() const;
    void setGender(char gender);
    int getBirth() const;
    int getNameSize();

    void setBirth(int birth);
    int getDeath() const;
    void setDeath(int death);

private:
    string _name;
    char _gender;
    int _birth;
    int _death;
};

#endif // PERSON_H
