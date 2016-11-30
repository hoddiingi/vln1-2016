#include "console.h"
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include <algorithm>

using namespace std;

Console::Console()
{

}
void Console::getInfo()
{
    _dat.readData();
    string command;

    do
    {

    cout << "--------------------------------------------" << endl;
    cout << "Please enter one of the following commands: " << endl;
    cout << "Add - for adding scientist to the list" << endl;
    cout << "View - for viewing the whole list" << endl;
    cout << "Search - for searching for names in the list" << endl;
    cout << "Sort - for sorting" << endl;
    cout << "Exit - quits" << endl;
    cout << "--------------------------------------------" << endl;

    cin >> command;

    if ((command == "Add") || (command == "add"))
    {
        string name;
        char gender;
        int birth;
        int death;

        cout << "Enter name of scientist: ";
        cin >> name;
        do{
            cout << "Gender (f/m): ";
            cin >> gender;
            if(!(gender == 'm') && !(gender == 'f'))
                cout << "Invalid input!" <<endl;
        }
        while((gender != 'f') && (gender != 'm'));

        cout << "Enter year of birth: ";
        cin >> birth;
        cout << "Enter year of death, unless N/A: ";
        cin >> death;
        cout << endl;

        Person newData(name, gender, birth, death);
        _dat.writeData(newData);

    }
    else if ((command == "View") || (command == "view"))
    {
        vector<Person> pers = _dat.readData();

        for(unsigned int i = 0; i < pers.size(); i++)
        {
            cout << pers[i].getName() << endl;
            cout << pers[i].getGender() << endl;
            cout << pers[i].getBirth() << endl;
            cout << pers[i].getDeath() << endl;
        }
    }
    else if ((command == "Search") || (command == "search"))
    {

    }
    else if ((command == "Sort") || (command == "sort"))
    {
        int sortType = getSort();
        _dom.sorting(sortType);
    }

    }while((command != "Exit") && (command != "exit"));
}

int Console::getSort()
{
    int sort;

    cout << "Please enter one of the following commands: " << endl;
    cout << "1 - for alphabetical order" << endl;
    cout << "2 - sort by gender" << endl;
    cout << "3 - sort by age (youngest to oldest)" << endl;
    cin >> sort;

    return sort;
}
