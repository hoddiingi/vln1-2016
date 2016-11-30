#include "data.h"
#include "person.h"
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
    out.close();
}
