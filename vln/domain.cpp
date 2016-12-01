#include "domain.h"
#include "person.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "data.h"
#include "person.h"

using namespace std;

struct genderComparison
{
  bool operator() (Person i, Person j) { return (i.getGender()<j.getGender());}
};


struct compareAge {
  bool operator() (Person i,Person j) { return (i.getBirth()<j.getBirth());}
};

struct compareName {

  bool operator() (Person i,Person j)
  {
      return (i.getName()<j.getName());
  }

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

vector<Person> Domain::alphabeticSort()
{
    compareName cn;
    std::sort(_persSort.begin(), _persSort.end(), cn);
    return _persSort;
}

void Domain::genderSort()
{
    genderComparison cmp;
    std::sort (_persSort.begin(), _persSort.end(), cmp);

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

