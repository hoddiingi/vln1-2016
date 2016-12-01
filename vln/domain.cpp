#include "domain.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "data.h"
#include "person.h"

using namespace std;

struct compareAge {
  bool operator() (Person i,Person j) { return (i.getBirth()<j.getBirth());}
};

Domain::Domain()
{

}

void Domain::sorting(int sort)
{
    if(sort == 1)
    {
        cout << "alphabetic";
    }
    else if(sort == 2)
    {
        cout << "gender";
    }
    else if(sort == 3)
    {
        cout << "age";
    }
}

void Domain::alphabeticSort()
{

}

void genderSort()
{

}

void Domain::ageSort()
{
    compareAge cmp;
    std::sort (_persSort.begin(), _persSort.end(), cmp);

    for(unsigned int i = 0; i < _persSort.size(); i++)
    {
        cout << "Born: " << _persSort[i].getBirth() << endl;
        cout << endl;
    }
}

