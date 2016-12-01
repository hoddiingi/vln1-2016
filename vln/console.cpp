#include "console.h"
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include <algorithm>
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
    _pers = _dat.readData();
    string command;
    char anotherOne;

    do
    {
        menu(command);

        if ((command == "Add") || (command == "add"))
        {
            add(anotherOne);
        }

        else if ((command == "View") || (command == "view"))
        {
             _pers = _dat.readData();
             display();
        }

        else if ((command == "Search") || (command == "search"))
        {

        }

        else if ((command == "Sort") || (command == "sort"))
        {
            int sortType = getSort();
            _dom.sorting(sortType);
            displaySort(sortType);
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

void Console::displaySort(int& sort)
{
    if(sort == 1)
    {
        _dom.alphabeticSort(_pers);
        display();
    }
    else if (sort == 2)
    {

    }
    else if (sort == 3)
    {

    }
}

void Console::display()
{
    for(unsigned int i = 0; i < _pers.size(); i++)
    {
        cout << "Name: " << _pers[i].getName() << endl;
        cout << "Gender: " << _pers[i].getGender() << endl;
        cout << "Born: " << _pers[i].getBirth() << endl;
        cout << "Died: ";
        if(_pers[i].getDeath() == 0)
            cout << "N/A" << endl;
        else
            cout << _pers[i].getDeath() << endl;
        cout << endl;
    }
}

void Console::menu(string& command)
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
}

void Console::add(char& anotherOne)
{
    do{
        std::string name;
        char gender;
        int birth = 0;
        int death = 0;

        addName(name);
        addGender(gender);
        addBirth(birth);
        addDeath(death, birth);
        addAnother(anotherOne);

        Person newData(name, gender, birth, death);
        _dat.writeData(newData);

    }while(anotherOne == 'y' || anotherOne == 'Y');
}

void Console::addName(std::string& name)
{
    cout << "Enter name of scientist: ";
    cin.ignore();
    std::getline(std::cin, name);
}

void Console::addGender(char& gender)
{
    do
    {
        cout << "Gender (f/m): ";
        cin >> gender;
        if(!(gender == 'm') && !(gender == 'f'))
            cout << "Invalid input!" <<endl;
    }while((gender != 'f') && (gender != 'm'));
}

void Console::addBirth(int& birth)
{
    string birthInput;
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
}

void Console::addDeath(int& death, int& birth)
{
    string deathInput;
    char status;
    cout << "Is the person alive? (Y/N): ";
    cin >> status;
    if(status == 'N' || status == 'n')
    {
        do{
            cout << "Enter year of death : ";
            cin >> deathInput;
            if((!validYear(deathInput)) || (atoi(deathInput.c_str()) < birth))
            {
                cout << "Invalid input!" <<endl;
            }
        }
        while((!validYear(deathInput)) || (atoi(deathInput.c_str()) < birth));
        death = atoi(deathInput.c_str());
    }
    cout << endl;
}

void Console::addAnother(char& anotherOne)
{
    cout << "Add another? (Y/N): ";
    cin >> anotherOne;
}
