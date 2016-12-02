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
    char getGender() const;
    int getBirth() const;
    int getDeath() const;
<<<<<<< HEAD
    void setDeath(int death);
    int getNameSize();

=======
    int getNameSize();

    //Gets private member variables

>>>>>>> 5f6554b81ccaec67d504e6be03a2d2a394f96023
private:
    string _name;
    char _gender;
    int _birth;
    int _death;

};

#endif // PERSON_H
