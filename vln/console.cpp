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
    _dat.readData();
    string command;
    char anotherOne;

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
<<<<<<< HEAD
        string name;
        char gender;
        int birth;
        int death = 0;
        string birthInput;
        string deathInput;
        char status;

        cout << "Enter name of scientist: ";
        cin >> ws;
        getline(cin,name);

=======
>>>>>>> 2ee6c48899b97e7de3f19d76447e2c9b2eb9c099
        do{
            std::string name;
            char gender;
            int birth;
            int death = 0;
            string birthInput;
            string deathInput;
            char status;

            cout << "Enter name of scientist: ";
            cin.ignore();
            std::getline(std::cin, name);
            do{
                cout << "Gender (f/m): ";
                cin >> gender;
                if(!(gender == 'm') && !(gender == 'f'))
                    cout << "Invalid input!" <<endl;
            }
<<<<<<< HEAD
        }


        while(!validYear(birthInput));
        {
        birth = atoi(birthInput.c_str());
        cout << "Is the scientist alive? (Y/N)";
        cin >> status;
        }

        if (status == 'N' || status == 'n')
        {
            do{
                cout << "Enter year of death: ";
                cin >> deathInput;
                if((!validYear(deathInput)) || (atoi(deathInput.c_str()) < birth))
                {
                    cout << "Invalid input!" <<endl;
                }
            }while((!validYear(deathInput)) || (atoi(deathInput.c_str()) < birth));

        }

        death = atoi(deathInput.c_str());
        cout << endl;



        Person newData(name, gender, birth, death);
        dat.writeData(newData);
=======
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

            Person newData(name, gender, birth, death);
            _dat.writeData(newData);
            cout << "Add another? (Y/N): ";
            cin >> anotherOne;
        }
        while(anotherOne == 'y' || anotherOne == 'Y');

>>>>>>> 2ee6c48899b97e7de3f19d76447e2c9b2eb9c099

    }
    else if ((command == "View") || (command == "view"))
    {
        vector<Person> pers = _dat.readData();

        for(unsigned int i = 0; i < pers.size(); i++)
        {
            cout << "Name: " << pers[i].getName() << endl;
            cout << "Gender: " << pers[i].getGender() << endl;
            cout << "Born: " << pers[i].getBirth() << endl;
            cout << "Died: ";
            if(pers[i].getDeath() == 0)
                cout << "N/A" << endl;
            else
                cout << pers[i].getDeath() << endl;
            cout << endl;
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
