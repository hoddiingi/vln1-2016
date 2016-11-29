#include "domain.h"
#include <vector>
#include "person.h"
#include <iostream>
#include <fstream>

using namespace std;

Domain::Domain()
{

}

vector<Person> Domain::readData()
{
    vector<Person> returnData;
    //returnData[Person::getBirth()]
    //returnData.push_back(Person::getBirth())
<<<<<<< HEAD
=======

   return returnData;
}
>>>>>>> 6ece16006aa2d1680a6068c4ba08f9821ecf7241

void Domain::writeData(Person p)
{
    fstream out;
    out.open("text.txt", std::ios_base::app);
    out << "Name: " << p.getName() << endl;
    out.close();
}
