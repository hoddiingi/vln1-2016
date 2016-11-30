#include "console.h"
#include <iostream>
#include <string>
#include "person.h"
#include "data.h"
#include <cctype>
#include <ctype.h>

using namespace std;

Console::Console()
{

}
bool Console::validYear(string s)
{
    for (unsigned int i = 0; i < s.size(); i++)
        if (!isdigit(s[i]))
            return 0;
    return 1;
}

void Console::getInfo()
{
    string command;

    do
    {

    cout << "--------------------------------------------" << endl;
    cout << "Please enter one of the following commands: " << endl;
    cout << "Add - for adding scientist to the list" << endl;
    cout << "View - for viewing the whole list" << endl;
    cout << "Search - for searching for names in the list" << endl;
    cout << "Exit - quits" << endl;
    cout << "--------------------------------------------" << endl;

    cin >> command;

    if (command == "Add" || command == "add")
    {
        string name;
        char gender;
        int birth;
        int death = 0;
        string birthInput;
        string deathInput;

        cout << "Enter name of scientist: ";
        cin >> name;
        do{
            cout << "Gender (f/m): ";
            cin >> gender;
            if(!(gender == 'm') && !(gender == 'f'))
                cout << "Invalid input!" <<endl;
        }
        while((gender != 'f') && (gender != 'm'));
        do{
            cout << "Enter year of birth: ";
            cin >> birthInput;
            if(!validYear(birthInput))
            {
                cout << "Invalid input!" <<endl;
            }
        }
        while(!validYear(birthInput));
        birth = atoi(birthInput.c_str());
        do{
            cout << "Enter year of death, if N/A input 0: ";
            cin >> deathInput;
            if((!validYear(deathInput)) || (atoi(deathInput.c_str()) > birth) || !(deathInput == "0"))
            {
                cout << "Invalid input!" <<endl;
            }
        }
        while((!validYear(deathInput)) || (atoi(deathInput.c_str()) > birth) || !(deathInput == "0"));
        death = atoi(deathInput.c_str());
        cout << endl;

        Person newData(name, gender, birth, death);
        dat.writeData(newData);

    }
    else if (command == "View" || command == "view")
    {

    }
    else if (command == "Search" || command == "search")
    {

    }

    }while((command != "Exit") && (command != "exit"));
}

void Console::getSort()
{
    int sort;

    cout << "Please enter one of the following commands: " << endl;
    cout << "1 - for alphabetical order" << endl;
    cout << "2 - sort by gender" << endl;
    cout << "3 - sort by age (youngest to oldest)" << endl;
    cin >> sort;

    if(sort == 1)
    {

    }
    else if(sort == 2)
    {

    }
    else if(sort == 3)
    {

    }
}
