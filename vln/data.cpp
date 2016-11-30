#include "data.h"
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
