#include "data.h"
#include <fstream>
#include <vector>



Data::Data()
{

}

vector<Data> Data::readData()
{
    vector<Data> readData;

    readData r("Alan Turing", "Male", 1912, 1954);

    ofstream writeText;
    writeText.open("text.txt")

    readData.push_back(r);

    writeText << r;

    writeText.close();

    return readData;
}
