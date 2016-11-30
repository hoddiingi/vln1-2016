#include "data.h"
<<<<<<< HEAD
#include "console.h"
=======
>>>>>>> abba0accedb7981623994220f7504b07dc75d2ba
#include "person.h"
#include "console.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

//read write file

Data::Data()
{

}

void Data::writeData(Person p)
{
    fstream out;
    out.open("text.txt", std::ios_base::app);
    out << "Name: " << p.getName() << endl;
    out.close();
}
