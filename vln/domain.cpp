#include "domain.h"
#include <vector>
#include "person.h"
#include <iostream>

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
    cout << p.getBirth();
}
