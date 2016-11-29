#include "console.h"
#include <iostream>
#include <string>
#include "person.h"

using namespace std;

Console::Console()
{

}
void Console::getInfo()
{
    string command;

    cout << "Please enter one of the following commands: " << endl;
    cout << "Add - for adding scientist to the list" << endl;
    cout << "View - for viewing the whole list" << endl;
    cout << "Search - for searching for names in the list" << endl;
    cout << "Exit - quits" << endl;

    cin >> command;

    do
    {

    if (command == 'Add' || command == 'add')
    {
        string name;
        char gender;
        int birth;
        int death;

        cout << "Enter name of scientist: ";
        cin >> name;
        cout << "Gender (f/m): ";
        cin >> gender;
        cout << "Enter year of birth: ";
        cin >> birth;
        cout << "Enter year of death, unless N/A: ";
        cin >> death;

        Person newPerson(name, gender, birth, death);

    }
    else if (command == 'View' || command == 'view')
    {

    }
    else if (command == 'Search' || command == 'search')
    {

    }

    }while(command != 'Exit' || command != 'exit');
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
