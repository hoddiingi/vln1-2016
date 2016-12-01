#include "domain.h"
#include <iostream>
#include <algorithm>

using namespace std;

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

void ageSort()
{
    //std::sort (_persSort.begin(), myvector.end(), myobject);
}
