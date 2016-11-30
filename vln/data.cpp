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
    out << "Name: " << p.getName() << endl;
    out << "Gender: " << p.getGender() << endl;
    out << "Date of birth: " << p.getBirth() << endl;
    out << "Date of death: " << p.getDeath() << endl;
    out << endl;
    out.close();
}
