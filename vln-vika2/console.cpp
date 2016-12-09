#include "console.h"
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include <algorithm>
//#include "data.h"
#include <cctype>
#include <ctype.h>
#include "computer.h"
#include <limits>

using namespace std;

Console::Console()
{

}

void Console::validInput()
{
    cout << endl << "Please enter a valid number" << endl;
    cout << "Numbers cant have space before or after them" << endl << endl;
}
/*
void Console::removeWhitespace(string& str)
{
        cout << "þetta er fall fyrir for loop: " << str << endl;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            str.erase(i, 1);
            i--;
        }
    }
    cout << "þetta er fall eftir for loop: " << str << endl;
}

bool Console::validInput(string& input, int min, int max)
{
    //while(true)
   // {
        //cout << "Enter a number: ";
        //string s;
        //getline(cin,s);
        char *endp = 0;
        int ret = strtol(input.c_str(),&endp,10);
        if(endp!=input.c_str() && !*endp && ret >= min && ret <= max)
        {
            return true;
        }
        else
        {
            return false;
        }
        //cout << "Invalid input. Allowed range: " << min << "-" << max <<endl;
    //}
}*/

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
            string viewInput;
            do
            {
                cout << "--------------------------------------------" << endl;
                cout << "Please enter one of the following commands:" << endl;
                cout << "1 - view list of scientists" << endl;
                cout << "2 - view a list of computers" << endl << endl;

                getline(cin, viewInput);

                   if((viewInput != "1" && viewInput != "2"))
                    {
                        validInput();
                    }
                    else if (viewInput == "1")
                    {
                        int num1 = getSort();
                        _pers = _dom.readSciData(num1);
                        display();
                    }
                    else if (viewInput == "2")
                    {
                        int num = sortBy();
                        _comp = _dom.readCompData(num);
                        displayComputer();
                    }
            }while((viewInput != "1" && viewInput != "2"));
        }
        else if((command == "Search") || (command == "search"))
        {
            search();
        }
        /*else if((command == "Sort") || (command == "sort"))
        {
            _pers        = _dom.readData();
            int sortType = getSort();
            displaySort(sortType);
        }*/
        else if ((command == "Remove") || (command == "remove"))
        {
            deleteStuff();
        }
        else if((command != "Add") && (command != "add") && (command != "View") && (command != "view") &&
                (command != "Search") && (command != "search") && (command != "Sort") && (command != "sort") &&
                (command != "Exit") && (command != "exit"))
        {
            cout << endl << "Invalid input! Please enter a valid command:" << endl;
        }
    }while((command != "Exit") && (command != "exit"));
}

int Console::sortBy()
{
    string res;
    int ress;
    do
    {
        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "1 - view a list of computers by name - asc" << endl;
        cout << "2 - view a list of computers by name - desc" << endl;
        cout << "3 - view a list of computers by year - asc" << endl;
        cout << "4 - view a list of computers by year - desc" << endl;
        cout << "5 - view a list of computers by type - asc" << endl;
        cout << "6 - view a list of computers by type - desc" << endl;
        cout << "7 - view a list of computers by if it was built - asc" << endl;
        cout << "8 - view a list of computers by if it was builr - desc" << endl;
        getline(cin, res);

        if(res != "1" && res != "2" && res != "3" && res != "4" && res != "5" && res != "6" && res != "7" && res != "8")
        {
            validInput();
        }
    }while(res != "1" && res != "2" && res != "3" && res != "4" && res != "5" && res != "6" && res != "7" && res != "8");
    ress = atoi(res.c_str());
    return ress;
}

int Console::getSort()
{
    int sort;
    string sortInput;
    do
    {
        cout << endl << "-------------------------------------------"  << endl;
        cout << "Please enter one of the following commands: " << endl << endl;
        cout << "1 - sort by alphabetical order - asc" << endl;
        cout << "2 - sort by alphabetical order - desc" << endl;
        cout << "3 - sort by gender - asc" << endl;
        cout << "4 - sort by gender - desc" << endl;
        cout << "5 - sort by year of birth - asc" << endl;
        cout << "6 - sort by year of birth - desc" << endl;
        cout << "7 - sort by year of death - asc" << endl;
        cout << "8 - sort by year of death - desc" << endl;
        cout << "-------------------------------------------"  << endl << endl;
        getline(cin, sortInput);

        if(sortInput != "1" && sortInput != "2" && sortInput != "3" && sortInput != "4" && sortInput != "5" && sortInput != "6" && sortInput != "7" && sortInput != "8")
        {
            validInput();
        }
    }while(sortInput != "1" && sortInput != "2" && sortInput != "3" && sortInput != "4" && sortInput != "5" && sortInput != "6" && sortInput != "7" && sortInput != "8");

    sort = atoi(sortInput.c_str());
    return sort;
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
    cout << "Remove - for removing" << endl;
    cout << "Exit   - quits" << endl;
    cout << "--------------------------------------------" << endl << endl;

    cin >> command;
    cin.ignore();
    cout << endl;
}

void Console::add(string& anotherOne)
{
    string choice;

    do
    {
        cout << endl;
        cout << "Enter 1 to add a scientist" << endl;
        cout << "Enter 2 to add a computer" << endl;
        cout << "Enter 3 to add a connection" << endl;
        getline(cin, choice);

        if(choice != "1" && choice != "2" && choice != "3")
        {
            validInput();
        }
        else if(choice == "1")
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

                Person newData(name, gender, birth, death);
                //_dat.writeData(newData); //Eyða síðar
                _dom.addPerson(newData);
            }while(anotherOne == "y" || anotherOne == "Y");
        }
        else if(choice == "2")
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
                addAnother(anotherOne);

                Computer newDataComp(computerName, year, type, built);
                //_dat.writeCompData(newDataComp);
                _dom.addComputer(newDataComp);
            }while(anotherOne == "y" || anotherOne == "Y");
        }
        else if(choice == "3")
        {
            cout << "Connections" << endl;
            int personID;
            int computerID;
            displaySciIdName();
            personID = addPersConnection();
            displayCompIdName();
            computerID = addCompConnection();
            //kalla ég í data (dom.addConnections(personID, computerID))
            _dom.addConnection(personID, computerID);
        }
    }while(choice != "1" && choice != "2" && choice != "3");
}
int Console::addPersConnection()
{
    int input;
    cout << "Enter scientist ID to connect: ";
    cin >> input;

    return input;
}
int Console::addCompConnection()
{
    int input;
    cout << "Enter computer ID to connect: ";
    cin >> input;

    return input;
}

void Console::displaySciIdName()
{
    _pers = _dom.readSciData(1);
    cout  << endl << "ID:\tNAME: " << endl;

    for(unsigned int i = 0; i < _pers.size(); i++)
    {

        cout << _pers[i].getId() <<"\t";
        cout << _pers[i].getName() << endl;

    }

}
void Console::displayCompIdName()
{
    _comp = _dom.readCompData(1);
    cout  << endl << "ID:\tCOMPUTER NAME: " << endl;

    for(unsigned int i = 0; i < _comp.size(); i++)
    {

        cout << _comp[i].getId() <<"\t";
        cout << _comp[i].getName() << endl;

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
        cin >> gender;

        if(gender.length() != 1)
            cout << "Please only enter f or m." << endl;
        else
        {
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
        cin >> built;

        if(built.length() != 1)
            cout << "Please only enter Y or N." << endl;
        {
            if(!(built == "y" || built == "Y") && !(built == "n" || built == "N"))
            {
                cout << "Please only enter Y or N." << endl;
            }
        }
    }while(!(built == "y" || built == "Y") && !(built == "n" || built == "N"));
}

void Console::addType(string& type)
{
    do
    {
        cout << "Enter the type of computer: ";
        cin >> type;
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

void Console::search()
{
    string choice;
    do
    {
        cout << "Enter 1 to search for a scientist" << endl;
        cout << "Enter 2 to search for a computer"  << endl;
        getline(cin, choice);

        if(choice != "1" && choice != "2")
        {
            validInput();
        }
        else if(choice == "1")
        {
            displaySearchScientist();
        }
        else if(choice == "2")
        {
            displaySearchComputer();
        }
    }while(choice != "1" && choice != "2");
}

string Console::searchComputer()
{
    string computerName;
    cout << endl << "Name of computer: ";
    cin.ignore();
    std::getline(std::cin, computerName);
    return computerName;
}

string Console::searchScientist()
{
    string chosenName;
    cout << endl << "Name of scientist: ";
    cin.ignore();
    std::getline(std::cin, chosenName);
    return chosenName;
}

void Console::displaySearchScientist()
{
    QString name = QString::fromStdString(searchScientist());
    vector<Person> k = _dom.searchName(name);

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

void Console::displaySearchComputer()
{
    QString name = QString::fromStdString(searchComputer());
    vector<Computer> k = _dom.searchComputer(name);

    cout << endl;
    cout << "NAME:\t\t\t\tYEAR:\tTYPE:\tBUILT:\t" << endl;

    for(unsigned int i = 0; i < k.size(); i++)
    {
        int nameSize = k[i].getNameSize2();
        int typeSize = k[i].getTypeSize();

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
        cout << k[i].getYear() << "\t";
        if(typeSize >= 0 && typeSize <= 7)
        {
            cout << k[i].getType() << "\t\t\t";
        }
        else if(typeSize >= 8  && typeSize <= 15)
        {
            cout << k[i].getType() << "\t\t";
        }
        else if(typeSize >= 16  && typeSize <= 23)
        {
            cout << k[i].getType() << "\t";
        }
        cout << k[i].getBuilt() << "\t";
        cout << endl;
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

void Console::deleteStuff()
{
    string input;

    do
    {
        cout << "1 - remove one person" << endl;
        cout << "2 - remove all persons" << endl;
        cout << "3 - remove one computer" << endl;
        cout << "4 - remove all computers" << endl;

        getline(cin, input);

        if(input != "1" && input != "2" && input != "3" && input != "4")
        {
            validInput();
        }
        else if (input == "1")
        {
            display();
            QString name = QString::fromStdString(searchScientist());
            _dom.removePerson(name);
        }
        else if (input == "2")
        {
            
            _dom.removeAllPersons();
        }
        else if (input == "3")
        {
            QString computer = QString::fromStdString(searchComputer());
            _dom.removeComputer(computer);
        }
        else if (input == "4")
        {
            _dom.removeAllComputers();
        }
    }while(input != "1" && input != "2" && input != "3" && input != "4");
}
