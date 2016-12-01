#include "domain.h"
#include "person.h"
#include <iostream>
#include <algorithm>
#include <vector>
<<<<<<< HEAD

using namespace std;

struct genderComparison
{
  bool operator() (Person i, Person j) { return (i.getGender()<j.getGender());}
=======
#include "data.h"
#include "person.h"

using namespace std;

struct compareAge {
  bool operator() (Person i,Person j) { return (i.getBirth()<j.getBirth());}
>>>>>>> 9e3d8a7cbc183a58999002a919734e4eb013f285
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
<<<<<<< HEAD

=======
    compareAge cmp;
    std::sort (_persSort.begin(), _persSort.end(), cmp);

    for(unsigned int i = 0; i < _persSort.size(); i++)
    {
        cout << "Born: " << _persSort[i].getBirth() << endl;
        cout << endl;
    }
>>>>>>> 9e3d8a7cbc183a58999002a919734e4eb013f285
}

