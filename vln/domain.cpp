#include "domain.h"
#include "person.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "data.h"
#include "person.h"
#include "console.h"

using namespace std;

<<<<<<< HEAD
/*struct compareGender{
  bool operator() (Person i, Person j) { return (i.getGender()<j.getGender());}
};

struct compareAge {
  bool operator() (Person i,Person j) { return (i.getBirth()<j.getBirth());}
=======
struct genderComparison
{
    bool operator() (Person i, Person j) { return (i.getGender()<j.getGender());}
};

struct compareAge
{
    bool operator() (Person i,Person j) { return (i.getBirth()<j.getBirth());}
};

struct compareName
{
    bool operator() (Person i,Person j)
    {
      return (i.getName()<j.getName());
    }
>>>>>>> 6424bf76461b588aa15549c7ff23531a838b98fa
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

<<<<<<< HEAD
bool nameAlpha (const Person& lhs, const Person& rhs)
{
    return (lhs.getName() < rhs.getName());
}

void Domain::alphabeticSort(vector<Person> &alphaSort)
{
    std::sort(alphaSort.begin(), alphaSort.end(), nameAlpha);
    Console c;
    c.display();
=======
vector<Person> Domain::alphabeticSort()
{
    compareName cn;
    std::sort(_persSort.begin(), _persSort.end(), cn);
    return _persSort;
>>>>>>> 6424bf76461b588aa15549c7ff23531a838b98fa
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
<<<<<<< HEAD
*/
=======
>>>>>>> 6424bf76461b588aa15549c7ff23531a838b98fa
