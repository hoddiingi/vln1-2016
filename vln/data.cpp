#include "data.h"
#include "console.h"
#include "person.h"
#include "console.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

//read write file

Data::Data()
{

}

void Data::writeData(Person p)
{
    fstream out;
    out.open("text.txt", std::ios_base::app);

    out << p.getName() << endl;
    out << p.getGender() << endl;
    out << p.getBirth() << endl;
    out << p.getDeath() << endl;
    out << endl;

    out.close();
}
void readData(Person p)
{
    string name;
    char gender;
    int birth;
    int death;

    ifstream in;
    in.open("text.txt");
    if (in.fail())
    {
        cout << "Failed to open!";
    }
    else
    {
        while(in >> name >> gender >> birth >> death)
        {

        }
    }

    in.close();
}
