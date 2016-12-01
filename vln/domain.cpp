#include "domain.h"
#include "person.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct genderComparison
{
  bool operator() (Person i, Person j) { return (i.getGender()<j.getGender());}
};

Domain::Domain()
{

}

void Domain::sorting(int sort)
{


    if(sort == 1)
    {
        cout << "alphabetic" << endl;
    }
    else if(sort == 2)
    {
        cout << "gender" << endl;
    }
    else if(sort == 3)
    {
        cout << "age" << endl;
    }
}

void Domain::alphabeticSort()
{

}

void Domain::genderSort()
{
    genderComparison cmp;
    std::sort (_persSort.begin(), _persSort.end(), cmp);

}

void Domain::ageSort()
{

}
