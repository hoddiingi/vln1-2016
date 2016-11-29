#include "console.h"
#include <iostream>
#include <string>

using namespace std;

Console::Console()
{

}
void Console::getInfo()
{
    string name;
    char gender;
    int birth;
    int death;

    cout << "Please enter name: ";
    cin >> name;
    cout << "Gender (f/m): ";
    cin >> gender;
    cout << "Year of birth: ";
    cin >> birth;
    cout << "Year of death, enter '0' if N/A: ";
    cin >> death;
}

int Console::getSort()
{
    int command;

    cout << "Please enter one of the following commands: " << endl;
    cout << "1 - for alphabetical order" << endl;
    cout << "2 - sort by gender" << endl;
    cout << "3 - sort by age (youngest to oldest)" << endl;
    cin >> command;

    return command;
}
