#include "person.h"
#include "data.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

Data::Data()
{
    _persons = readData();
}

void Data::writeData(Person p)
{
    ofstream out;
    out.open("text.txt", std::ios_base::app);

    out << p.getName() << endl;
    out << p.getGender() << endl;
    out << p.getBirth() << endl;
    out << p.getDeath() << endl;

    out.close();
}

vector<Person> Data::readData()
{
    vector<Person> vect;
    string name, genderS, birthS, deathS;
    const char *gender;
    int birth;
    int death;

    ifstream in;
    in.open("text.txt");

    if (in.fail())
    {
        exit(1);
    }
    else
    {
        while(getline(in, name))
        {
            getline(in, genderS);
            getline(in, birthS);
            getline(in, deathS);
            birth = atoi(birthS.c_str());
            gender = (genderS.c_str());
            death = atoi(deathS.c_str());
            Person temp(name, *gender, birth, death);
            vect.push_back(temp);
        }
    }
    in.close();

    //cout << vect[1].getNameSize();

    return vect;
}


