#include "data.h"
#include "console.h"
#include "person.h"
#include <fstream>
#include <vector>



//read write file

Data::Data()
{

}

vector<Console> Data::readData()
{
    vector<Console> readData;

    readData.push_back(Console.getInfo());

    //readData r("Alan Turing", "Male", 1912, 1954);

    ofstream writeText;
    writeText.open("text.txt")

    //readData.push_back(r);

    //writeText << r;

    //writeText.close();

    return readData;
}

int Data::ifSorting()
{

}
