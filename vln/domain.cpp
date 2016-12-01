#include "domain.h"
#include "person.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "data.h"
#include "person.h"
#include "console.h"

using namespace std;

/*struct compareGender{
  bool operator() (Person i, Person j) { return (i.getGender()<j.getGender());}
};

struct compareAge {
  bool operator() (Person i,Person j) { return (i.getBirth()<j.getBirth());}
};
*/

Domain::Domain()
{

}

void Domain::sorting(int sort)
{
    if(sort == 1)
    {
        cout << "ANTONalphabetic" << endl;
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

bool nameAlpha (const Person& lhs, const Person& rhs)
{
    return (lhs.getName() < rhs.getName());
}

void Domain::alphabeticSort(vector<Person> &alphaSort)
{
    std::sort(alphaSort.begin(), alphaSort.end(), nameAlpha);
    Console c;
    c.display();
}

/*vector<Person> Domain::genderSort()
{
    compareGender cg;
    std::sort (_persSort.begin(), _persSort.end(), cg);
    return _persSort;

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
*/
