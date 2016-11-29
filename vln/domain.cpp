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

   return returnData;
}

void Domain::writeData(Person p)
{
    cout << p.getBirth();
}
