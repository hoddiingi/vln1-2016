#include "console.h"
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include <algorithm>
#include "data.h"
#include <cctype>
#include <ctype.h>
#include "computer.h"

using namespace std;

Console::Console()
{

}

bool Console::validName(string n)
{
    for (unsigned int i = 0; i < n.size(); i++)
    {
        if (isdigit(n[i]))
        {
            return 0;
        }
    }
    return 1;
}

bool Console::validComputerName(string n)
{

    if (n == "")
    {
        return 0;
    }

    return 1;
}

bool Console::validYear(string s)
{
    for (unsigned int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
        {
            return 0;
        }
    }
    return 1;
}

void Console::getInfo()
{
    _pers = _dom.readData();
    string command;
    string anotherOne;

    do
    {
        menu(command);

        if((command == "Add") || (command == "add"))
        {
            add(anotherOne);
        }
        else if((command == "View") || (command == "view"))
        {
            int viewInput = 0;
            cout << "--------------------------------------------" << endl;
            cout << "Please enter one of the following commands:" << endl;
            cout << "1 - view list of scientists" << endl;
            cout << "2 - view a list of computers" << endl;
            cin >> viewInput;

            if (viewInput == 1)
            {
                _pers = _dom.readData();
                display();
            }
            else if (viewInput == 2)
            {
                _comp = _dat.readCompData();
                displayComputer();
            }
        }
        else if((command == "Search") || (command == "search"))
        {
            displaySearch();
        }
        else if((command == "Sort") || (command == "sort"))
        {
            _pers        = _dom.readData();
            int sortType = getSort();
            displaySort(sortType);
        }
        else if((command != "Add") && (command != "add") && (command != "View") && (command != "view") &&
                (command != "Search") && (command != "search") && (command != "Sort") && (command != "sort") &&
                (command != "Exit") && (command != "exit"))
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
        cout << endl << "-------------------------------------------"  << endl;
        cout << "Please enter one of the following commands: " << endl << endl;
        cout << "1 - sort by alphabetical order" << endl;
        cout << "2 - sort by year of birth" << endl;
        cout << "3 - sort by gender" << endl;
        cout << "4 - sort by year of death" << endl;
        cout << "-------------------------------------------"  << endl << endl;
        cin  >> sortInput;

        if(atoi(sortInput.c_str()) != 1 && atoi(sortInput.c_str()) != 2 && atoi(sortInput.c_str()) != 3 && atoi(sortInput.c_str()) != 4)
        {
            cout << "Invalid input!" << endl;
        }
    }while(atoi(sortInput.c_str()) != 1 && atoi(sortInput.c_str()) != 2 && atoi(sortInput.c_str()) != 3 && atoi(sortInput.c_str()) != 4);

    sort = atoi(sortInput.c_str());
    return sort;
}

void Console::displaySort(int& sort)
{
    _dom.readData();

    if(sort == 1)
    {
        _dom.alphabeticSort(_pers);
        display();
    }
    else if(sort == 2)
    {
        _dom.ageSorting(_pers);
        display();
    }
    else if(sort == 3)
    {
        _dom.maleFemaleSort(_pers);
        display();
    }
    else if(sort == 4)
    {
        _dom.deathSorting(_pers);
        display();
    }
}

void Console::display()
{
    cout  << endl << "NAME:\t\t\t\tGENDER:\tBORN:\tDIED:\tAGE:" << endl;

    for(unsigned int i = 0; i < _pers.size(); i++)
    {
        int nameSize = _pers[i].getNameSize();

        if(nameSize >= 0 && nameSize <= 7)
        {
            cout << _pers[i].getName() << "\t\t\t\t";
        }
        else if(nameSize >= 8  && nameSize <= 15)
        {
            cout << _pers[i].getName() << "\t\t\t";
        }
        else if(nameSize >= 16  && nameSize <= 23)
        {
            cout << _pers[i].getName() << "\t\t";
        }
        else if(nameSize >= 24  && nameSize <= 31)
        {
            cout << _pers[i].getName() << "\t";
        }
        if(_pers[i].getGender() == "m" || _pers[i].getGender() == "M")
        {
            cout << "Male\t";
        }
        else if(_pers[i].getGender() == "f" || _pers[i].getGender() == "F")
        {
            cout << "Female\t";
        }
        cout << _pers[i].getBirth() << "\t";

        if(_pers[i].getDeath() == 0)
        {
            cout << "N/A\t";
        }
        else
        {
            cout << _pers[i].getDeath() << "\t";
        }  
        cout << _dom.findAge(_pers[i]) << endl;
    }

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
    int choice;

    cout << "Enter 1 to add a scientist" << endl;
    cout << "Enter 2 to add a computer" << endl;
    cin >> choice;

    if(choice == 1)
    {
        do
        {
            std::string name;
            string gender;
            int birth = 0;
            int death = 0;

            addName(name);
            addGender(gender);
            addBirth(birth);
            addDeath(death, birth);
            addAnother(anotherOne);


            //Data d("sqlPrufa.sqlite");

            Person newData(name, gender, birth, death);
            //_dat.writeData(newData); //Eyða síðar
            _dom.addPerson(newData);

        }while(anotherOne == "y" || anotherOne == "Y");
    }
    else if(choice == 2)
    {
        do
        {
            std::string computerName;
            int year = 0;
            std::string type;
            string built;

            addComputerName(computerName);
            addYear(year);
            addType(type);
            addBuilt(built);

            Data d("sqlPruf.sqlite");
            Computer newDataComp(computerName, year, type, built);

            //_dat.writeCompData(newDataComp);
            _dom.addComputer(newDataComp);
        }while(anotherOne == "y" || anotherOne == "Y");

    }
}

void Console::addName(std::string& name)
{
    do
    {
        cout << endl << "Enter name of scientist: ";
        cin.ignore();
        std::getline(std::cin, name);

        if(!validName(name))
        {
            cout << "Name can not include digits!" << endl;
        }
    }while(!validName(name));
}

void Console::addGender(string &gender)
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
            gender = genderS;
            if(!(gender == "m" || gender == "M") && !(gender == "f" || gender == "F"))
            {
                cout << "Please only enter f or m." << endl;
            }
        }
    }while(!(gender == "f" || gender == "F") && !(gender == "m" || gender == "M"));
}

void Console::addBirth(int& birth)
{
    string birthInput;

    do
    {
        cout << "Enter year of birth: ";
        cin  >> birthInput;

        if(!validYear(birthInput))
        {
            cout << "Invalid input!" <<endl;
        }
        else if(atoi(birthInput.c_str()) > 2016)
        {
            cout << "The scientist is not born yet.." << endl;
        }
    }while(!validYear(birthInput) || atoi(birthInput.c_str()) > 2016);

    birth = atoi(birthInput.c_str());
}

void Console::addDeath(int& death, int& birth)
{
    string deathInput;
    string status;

    do
    {
        cout << "Is the person alive? (Y/N): ";
        cin  >> status;

        if(!(status == "N" || status == "n") && !(status == "Y" || status == "y"))
        {
            cout << "Invalid Input!";
        }
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
                else if(atoi(deathInput.c_str()) > 2016)
                {
                    cout << "So you think you know the future?" << endl;
                } 
            }while((!validYear(deathInput)) || (atoi(deathInput.c_str()) < birth) || (atoi(deathInput.c_str()) > 2016));

            death = atoi(deathInput.c_str());
        }
        cout << endl;

    }while(!(status == "N" || status == "n") && !(status == "Y" || status == "y"));
}

void Console::addComputerName(string& computerName)
{
    do
    {
        cout << endl << "Enter name of computer: ";
        cin.ignore();
        std::getline(std::cin, computerName);

        if(!validComputerName(computerName))
        {
            cout << "Name can not be empty" << endl;
        }
    }while(!validComputerName(computerName));
}

void Console::addYear(int& year)
{
    string yearInput;

    do
    {
        cout << "Enter the year the computer was built: ";
        cin  >> yearInput;

        if(!validYear(yearInput))
        {
            cout << "Invalid input!" <<endl;
        }
        else if(atoi(yearInput.c_str()) > 2016)
        {
            cout << "The computer hasn't been built yet.." << endl;
        }
    }while(!validYear(yearInput) || atoi(yearInput.c_str()) > 2016);

    year = atoi(yearInput.c_str());
}

void Console::addBuilt(string& built)
{
    do
    {
        cout << "Built (Y/N): ";
        std::string builtS;
        std::getline(std::cin, builtS);

        if(builtS.length() != 1)
            cout << "Please only enter Y or N." << endl;
        {
            built = builtS;
            if(!(built == "y" || built == "Y") && !(built == "n" || built == "N"))
            {
                cout << "Please only enter Y or N." << endl;
            }
        }
    }while(!(built == "y" || built == "Y") && !(built == "n" || built == "N"));
}

void Console::addType(string& type)
{
    string cpuType;
    do
    {
        cout << "Enter the type of computer: ";
        cin >> type;
        cpuType = type;
        if(!validName(type) && !validComputerName(type))
        {
            cout << "Type cannot be empty or contain digits! " << endl;
        }
    }while(!validName(type) && !validComputerName(type));
}

void Console::addAnother(string& anotherOne)
{
    do
    {
        cout << "Add another? (Y/N): ";
        cin >> anotherOne;

        if(!(anotherOne == "N" || anotherOne == "n") && !(anotherOne == "Y" || anotherOne == "y"))
        {
            cout << "Invalid Input!" <<endl;
        }
    }while(!(anotherOne == "N" || anotherOne == "n") && !(anotherOne == "Y" || anotherOne == "y"));
}

string Console::searchName()
{
    _dom.readData();
    string chosenName;
    cout << endl << "Who would you like to search for? (Case sensitive) ";
    cin >> chosenName;
    return chosenName;
}

void Console::displaySearch()
{
    _pers = _dom.readData();
    string name = searchName();

    vector<Person> k = _dom.search(_pers, name);

    cout << endl;
    cout << "NAME:\t\t\t\tGENDER:\tBORN:\tDIED:\tAGE:\t" << endl;

    for(unsigned int i = 0; i < k.size(); i++)
    {
        int nameSize = k[i].getNameSize();

        if(nameSize >= 0 && nameSize <= 7)
        {
            cout << k[i].getName() << "\t\t\t\t";
        }
        else if(nameSize >= 8  && nameSize <= 15)
        {
            cout << k[i].getName() << "\t\t\t";
        }
        else if(nameSize >= 16  && nameSize <= 23)
        {
            cout << k[i].getName() << "\t\t";
        }
        else if(nameSize >= 24  && nameSize <= 31)
        {
            cout << k[i].getName() << "\t";
        }
        if(k[i].getGender() == "m" || k[i].getGender() == "M")
        {
            cout << "Male\t";
        }
        else if(k[i].getGender() == "f" || k[i].getGender() == "F")
        {
            cout << "Female\t";
        }
        cout << k[i].getBirth() << "\t";

        if(k[i].getDeath() == 0)
        {
            cout << "N/A\t";
        }
        else
        {
            cout << k[i].getDeath() << "\t";
        }
        cout << _dom.findAge(k[i]) << endl;
    }
}

void Console::displayComputer()
{

    cout  << endl << "COMPUTER NAME:\t\t\tYEAR:\tTYPE:\t\t\tBUILT:" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for(unsigned int i = 0; i < _comp.size(); i++)
    {
        int nameSize = _comp[i].getNameSize2();

        if(nameSize >= 0 && nameSize <= 7)
        {
            cout << _comp[i].getName() << "\t\t\t\t";
        }
        else if(nameSize >= 8  && nameSize <= 15)
        {
            cout << _comp[i].getName() << "\t\t\t";
        }
        else if(nameSize >= 16  && nameSize <= 23)
        {
            cout << _comp[i].getName() << "\t\t";
        }
        else if(nameSize >= 24  && nameSize <= 31)
        {
            cout << _comp[i].getName() << "\t";
        }

        cout << _comp[i].getYear() << "\t";

        int typeSize = _comp[i].getTypeSize();

        if(typeSize >= 0 && typeSize <= 7)
        {
            cout << _comp[i].getType() << "\t\t\t";
        }
        else if(typeSize >= 8  && typeSize <= 15)
        {
            cout << _comp[i].getType() << "\t\t";
        }
        else if(typeSize >= 16  && typeSize <= 23)
        {
            cout << _comp[i].getType() << "\t";
        }
        cout << _comp[i].getBuilt() << endl;
    }
}
