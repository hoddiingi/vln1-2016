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

bool Console::validName(string n)
{
    for (unsigned int i = 0; i < n.size(); i++)
        if (isdigit(n[i]))
            return 0;
    return 1;
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
    string anotherOne;

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
            displaySearch();
        }

        else if ((command == "Sort") || (command == "sort"))
        {
            _pers = _dat.readData();
            int sortType = getSort();
            displaySort(sortType);
        }
        else
        {
            cout << endl << "Invalid input! Please enter a valid command:" << endl;
        }

    }while((command != "Exit") && (command != "exit"));
}

int Console::getSort()
{
    int sort;
    string sortInput;
    do
    {
        cout << endl;
        cout << "Please enter one of the following commands: " << endl;
        cout << "-------------------------------------------" << endl;
        cout << "1 - sort by alphabetical order" << endl;
        cout << "2 - sort by year of birth" << endl;
        cin >> sortInput;
        if(atoi(sortInput.c_str()) != 1 && atoi(sortInput.c_str()) != 2)
            cout << "Invalid input" << endl;
    }while(atoi(sortInput.c_str()) != 1 && atoi(sortInput.c_str()) != 2);
    sort = atoi(sortInput.c_str());
    return sort;
}

void Console::displaySort(int& sort)
{
    _dat.readData();

    if(sort == 1)
    {
        _dom.alphabeticSort(_pers);
        display();
    }
    else if (sort == 2)
    {
        _dom.ageSorting(_pers);
        display();
    }
}

void Console::display()
{
    cout << endl;
    cout << "NAME:" << "\t\t\t\t" << "GENDER:" << "\t" << "BORN:" << "\t" << "DIED:" <<  "\t" << "AGE:" << endl;
    for(unsigned int i = 0; i < _pers.size(); i++)
    {

        int nameSize = _pers[i].getNameSize();

        if (nameSize >= 0 && nameSize <= 7)
        {
            cout << _pers[i].getName() << "\t\t\t\t";
        }
        else if (nameSize >= 8  && nameSize <= 15)
        {
            cout << _pers[i].getName() << "\t\t\t";
        }
        else if (nameSize >= 16  && nameSize <= 23)
        {
            cout << _pers[i].getName() << "\t\t";
        }
        else if (nameSize >= 24  && nameSize <= 31)
        {
            cout << _pers[i].getName() << "\t";
        }

        if (_pers[i].getGender() == 'm' || _pers[i].getGender() == 'M')
            cout << "Male" << "\t";
        else if (_pers[i].getGender() == 'f' || _pers[i].getGender() == 'F')
            cout << "Female" << "\t";

        cout << _pers[i].getBirth() << "\t";

        if(_pers[i].getDeath() == 0)
        {
            cout << "N/A" << "\t";
        }
        else
        {
            cout << _pers[i].getDeath() << "\t";
        }

        cout << _dom.findAge(_pers[i]) << endl;

    }
         cout << endl;
}





void Console::menu(string& command)
{
    cout << endl << "--------------------------------------------" << endl;
    cout << "Please enter one of the following commands: " << endl << endl;
    cout << "Add    - for adding scientist to the list" << endl;
    cout << "View   - for viewing the whole list" << endl;
    cout << "Search - for searching for names in the list" << endl;
    cout << "Sort   - for sorting" << endl;
    cout << "Exit   - quits" << endl;
    cout << "--------------------------------------------" << endl << endl;

    cin >> command;
}

void Console::add(string& anotherOne)
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

    }while(anotherOne == "y" || anotherOne == "Y");
}

void Console::addName(std::string& name)
{
    do{

        cout << endl << "Enter name of scientist: ";
        cin.ignore();
        std::getline(std::cin, name);
            if(!validName(name))
            {
                cout << "Name can not include digits!" << endl;
            }
    }while(!validName(name));
}
void Console::addGender(char& gender)
{
    do
    {
        cout << "Gender (f/m): ";
        std::string genderS;
        std::getline(std::cin, genderS);
        if(genderS.length() != 1)
            cout << "Please only enter f or m." << endl;
        else
        {
            gender = genderS[0];
            if(!(gender == 'm' || gender == 'M') && !(gender == 'f' || gender == 'F'))
                cout << "Please only enter f or m." << endl;
        }
    }while(!(gender == 'f' || gender == 'F') && !(gender == 'm' || gender == 'M'));
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
        else if (atoi(birthInput.c_str()) > 2016)
        {
            cout << "The scientist is not born yet.." << endl;
        }

    }
    while(!validYear(birthInput) || atoi(birthInput.c_str()) > 2016);
    birth = atoi(birthInput.c_str());
}

void Console::addDeath(int& death, int& birth)
{
    string deathInput;
    string status;
    do
    {
        cout << "Is the person alive? (Y/N): ";
        cin >> status;
        if(!(status == "N" || status == "n") && !(status == "Y" || status == "y"))
            cout << "Invalid Input!";
        if(status == "N" || status == "n")
        {
            do
            {
                cout << "Enter year of death : ";
                cin >> deathInput;
                if((!validYear(deathInput)) || (atoi(deathInput.c_str()) < birth))
                {
                    cout << "Invalid input!" <<endl;
                }
                else if (atoi(deathInput.c_str()) > 2016)
                {
                    cout << "So you think you know the future?" << endl;
                }
            }
            while((!validYear(deathInput)) || (atoi(deathInput.c_str()) < birth) || (atoi(deathInput.c_str()) > 2016));
            death = atoi(deathInput.c_str());
        }
    cout << endl;
    }
    while(!(status == "N" || status == "n") && !(status == "Y" || status == "y"));
}
void Console::addAnother(string &anotherOne)
{
    do
    {
        cout << "Add another? (Y/N): ";
        cin >> anotherOne;
        if(!(anotherOne == "N" || anotherOne == "n") && !(anotherOne == "Y" || anotherOne == "y"))
            cout << "Invalid Input!" <<endl;
    }
    while(!(anotherOne == "N" || anotherOne == "n") && !(anotherOne == "Y" || anotherOne == "y"));
}

string Console::searchName()
{
    string chosenName;
    cout << "Who would you like to search for? ";
    cin >> chosenName;
    return chosenName;
}

vector<Person> Console::getVector()
{
    return _pers;
}

void Console::displaySearch()
{
    string name = searchName();
    cout << endl;

    cout << "NAME:" << "\t\t\t\t" << "GENDER:" << "\t" << "BORN:" << "\t" << "DIED:" <<  "\t" << endl;
    vector<Person> k = _dom.search(_pers, name);
        for(unsigned int i = 0; i < k.size(); i++)
        {
            int nameSize = k[i].getNameSize();

            if (nameSize >= 0 && nameSize <= 7)
            {
                cout << k[i].getName() << "\t\t\t\t";
            }
            else if (nameSize >= 8  && nameSize <= 15)
            {
                cout << k[i].getName() << "\t\t\t";
            }
            else if (nameSize >= 16  && nameSize <= 23)
            {
                cout << k[i].getName() << "\t\t";
            }
            else if (nameSize >= 24  && nameSize <= 31)
            {
                cout << k[i].getName() << "\t";
            }

            if (k[i].getGender() == 'm' || k[i].getGender() == 'M')
            {
                cout << "Male" << "\t";
            }
            else if (k[i].getGender() == 'f' || k[i].getGender() == 'F')
            {
                cout << "Female" << "\t";
            }

            cout << k[i].getBirth() << "\t";

            if(k[i].getDeath() == 0)
            {
                cout << "N/A" << "\t";
            }
            else
            {
                cout << k[i].getDeath() << "\t";
            }
            cout << endl;
        }
}
