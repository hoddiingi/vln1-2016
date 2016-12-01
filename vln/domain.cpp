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

=======
>>>>>>> 70ee6146ac74b59e0eb91d5f5afbbe74a98f8455
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

<<<<<<< HEAD
bool nameAlpha (const Person& lhs, const Person& rhs)
=======
bool agePerson (const Person& lsh, const Person& rhs)
>>>>>>> 70ee6146ac74b59e0eb91d5f5afbbe74a98f8455
{
    return (lsh.getBirth() < rhs.getBirth());
}

<<<<<<< HEAD
void Domain::alphabeticSort(vector<Person> &alphaSort)
{
    std::sort(alphaSort.begin(), alphaSort.end(), nameAlpha);
}

bool  (const Person& lhs, const Person& rhs)
=======
void Domain::ageSorting(vector<Person> &ageSort)
{
    std::sort(ageSort.begin(), ageSort.end(), agePerson);
}

bool nameAlpha (const Person& lhs, const Person& rhs)
>>>>>>> 70ee6146ac74b59e0eb91d5f5afbbe74a98f8455
{
    return (lhs.getName() < rhs.getName());
}

void Domain::alphabeticSort(vector<Person> &alphaSort)
{
    std::sort(alphaSort.begin(), alphaSort.end(), nameAlpha);
<<<<<<< HEAD
}

*/
=======
    Console c;
    c.display();
}
>>>>>>> 70ee6146ac74b59e0eb91d5f5afbbe74a98f8455
