#include "console.h"
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include <algorithm>
#include <cctype>
#include <ctype.h>
#include "computer.h"
#include <limits>

using namespace std;

Console::Console()
{

}

void Console::menu(string& command)
{
    cout << endl << "--------------------------------------------" << endl;
    cout << "Please enter one of the following commands: " << endl << endl;
    cout << "Add    - for adding scientist to the list" << endl;
    cout << "View   - for viewing the whole list" << endl;
    cout << "Search - for searching for names in the list" << endl;
    cout << "Remove - for removing" << endl;
    cout << "Update - for updating information" << endl;
    cout << "Game - for playing TicTacToe" << endl;
    cout << "Exit   - quits" << endl;
    cout << "--------------------------------------------" << endl << endl;

    cin >> command;
    cin.ignore();
    cout << endl;
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
                cout << "2 - view a list of computers" << endl;
                cout << "3 - view connection" << endl << endl;

                getline(cin, viewInput);

                   if((viewInput != "1" && viewInput != "2" && viewInput != "3"))
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
                    else if (viewInput == "3")
                   {
                        displayConnections();
                   }
            }while((viewInput != "1" && viewInput != "2" && viewInput != "3"));
        }
        else if((command == "Search") || (command == "search"))
        {
            search();
        }

        else if ((command == "Remove") || (command == "remove"))
        {
            deleteStuff();
        }
        else if((command == "Update") || (command == "update"))
        {
            int input = updateBy();
            if(input == 1)
            {
                update();
            }
            else if(input == 2)
            {
                updateComputer();
            }
            update();
        }
        else if((command == "Game") || (command == "game"))
        {
            gameplay();
        }
        else if((command != "Add") && (command != "add") && (command != "View") && (command != "view") &&
                (command != "Search") && (command != "search") && (command != "Remove") && (command != "remove") &&
                (command != "Update") && (command != "update") && (command != "Game") && (command != "game") &&
                (command != "Exit") && (command != "exit"))
        {
            cout << "Invalid input! Please enter a valid command:" << endl;
        }
    }while((command != "Exit") && (command != "exit"));
}

void Console::validInput()
{
    cout << endl << "Please enter a valid number" << endl;
    cout << "Numbers cant have space before or after them" << endl << endl;
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
                string name;
                string gender;
                int birth = 0;
                int death = 0;

                addName(name);
                addGender(gender);
                addBirth(birth);
                addDeath(death, birth);
                addAnother(anotherOne);
                cin.ignore();

                Person newData(name, gender, birth, death);
                QSqlError error;
                if(_dom.addPerson(newData, error) == false)
                    qDebug() << "Add person error : " << error << endl;
            }while(anotherOne == "y" || anotherOne == "Y");
        }
        else if(choice == "2")
        {
            do
            {
                string computerName;
                int year = 0;
                string type;
                string built;

                addComputerName(computerName);
                addYear(year);
                addType(type);
                addBuilt(built);
                addAnother(anotherOne);
                cin.ignore();

                Computer newDataComp(computerName, year, type, built);
                QSqlError error;
                if(_dom.addComputer(newDataComp, error) == false)
                {
                    qDebug() << "Add computer error : " << error << endl;
                }
            }while(anotherOne == "y" || anotherOne == "Y");
        }
        else if(choice == "3")
        {
            cout << "Connections" << endl;
            int personID;
            int computerID;
            //Birta töflu ID og nafn hjá People

            displaySciIdName();
            personID = addPersConnection();
            displayCompIdName();
            computerID = addCompConnection();


            //kalla ég í data (dom.addConnections(personID, computerID))
            QSqlError error;
            if(_dom.addConnection(personID, computerID, error) == false)
            {
                qDebug() << "Add connection error : " << error << endl;
            }
        }
    }while(choice != "1" && choice != "2" && choice != "3");
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
        cout << "8 - view a list of computers by if it was builr - desc" << endl << endl;
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


void Console::displayConnections()
{
    vector<int> j = _dom.readConData();
    _pers = _dom.readSciData(9);
    _comp = _dom.readCompData(9);

    cout << "ID\tName\t\t\t\t" << "ID\tComputer" << endl;
    cout << "--------------------------------------------" << endl;
    for(unsigned int i = 0; i < j.size(); i++)
    {
        vector<Person> test = searchSciId(j[i]);
        vector<Computer> test2 = searchCompId(j[i+1]);
        cout << test[0].getId() << "\t";
        int nameSize = test[0].getNameSize();

        if(nameSize >= 0 && nameSize <= 7)
        {
            cout << test[0].getName() << "\t\t\t\t";
        }
        else if(nameSize >= 8  && nameSize <= 15)
        {
            cout << test[0].getName() << "\t\t\t";
        }
        else if(nameSize >= 16  && nameSize <= 23)
        {
            cout << test[0].getName() << "\t\t";
        }
        else if(nameSize >= 24  && nameSize <= 31)
        {
            cout << test[0].getName() << "\t";
        }
        cout << test2[0].getId() << "\t";
        cout << test2[0].getName() << endl;
        i++;
    }
    cout << endl;
}

vector<Person> Console::searchSciId(int sciId)
{
    int id = sciId;
    return _dom.searchSciId(id);
}

vector<Computer> Console::searchCompId(int compId)
{
    int id = compId;
    return _dom.searchCompId(id);
}

int Console::addPersConnection()
{
    string input;
    do
    {
        cout << "Enter scientist ID to connect: ";
        cin >> input;
        if(!validYear(input))
        {
            cout << "Invalid input!" <<endl;
        }
    }while(validYear(input) == false);
    int idNumber = atoi(input.c_str());
    for(unsigned int i = 0; i < _pers.size(); i++)
    {
        if(idNumber == _pers[i].getId())
        {
            return idNumber;
        }
    }
    cout << "ID did not match, try again" << endl;
    return addPersConnection();
}

int Console::addCompConnection()
{
    string input;
    //cin >> input;
    do
    {
        cout << "Enter computer ID to connect: ";
        cin >> input;
        if(!validYear(input))
        {
            cout << "Invalid input!" <<endl;
        }
    }
    while(validYear(input) == false);
    int idNumber = atoi(input.c_str());
    for(unsigned int i = 0; i < _comp.size(); i++)
    {
        if(idNumber == _comp[i].getId())
        {
            return idNumber;
        }
    }
    cout << "ID did not match, try again" << endl;
    return addCompConnection();

}

void Console::displaySciIdName()
{
    _pers = _dom.readSciData(9);
    cout  << endl << "ID:\tNAME: " << endl;

    for(unsigned int i = 0; i < _pers.size(); i++)
    {
        cout << _pers[i].getId() <<"\t";
        cout << _pers[i].getName() << endl;
    }
}

void Console::displayCompIdName()
{
    _comp = _dom.readCompData(9);
    cout  << endl << "ID:\tCOMPUTER NAME: " << endl;

    for(unsigned int i = 0; i < _comp.size(); i++)
    {
        cout << _comp[i].getId() <<"\t";
        cout << _comp[i].getName() << endl;
    }
}

void Console::addName(string& name)
{
    do
    {
        cout << endl << "Enter name of scientist: ";
        getline(cin, name);

        if(!validComputerName(name) || !validName(name))
        {
            cout << "Invalid input for name!" << endl;
        }
    }while(!validComputerName(name) || !validName(name));
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
        getline(cin, computerName);

        if(!validComputerName(computerName))
        {
            cout << "Invalid input for name!" << endl;
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
        cout << endl;
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
        cout << "Enter 2 to search for a computer"  << endl << endl;
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
    //cin.ignore();
    getline(cin, computerName);
    return computerName;
}

string Console::searchConnection()
{
    string computerName;
    cout << endl << "ID number of scientist connected to a computer: ";
    //cin.ignore();
    getline(cin, computerName);
    return computerName;
}
string Console::searchScientist()
{
    string chosenName;
    cout << endl << "Name of scientist: ";
    //cin.ignore();
    getline(cin, chosenName);
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


        if (_comp[i].getBuilt() == "y"  || _comp[i].getBuilt() == "Y")
        {
            cout << "Yes" << endl;
        }
        else if (_comp[i].getBuilt() == "n"  || _comp[i].getBuilt() == "N")
        {
            cout << "No" << endl;
        }
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
        cout << "5 - remove one connection" << endl;
        cout << "6 - remove all connections" << endl;

        getline(cin, input);

        if(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6")
        {
            validInput();
        }
        else if (input == "1")
        {
            _pers = _dom.readSciData(9);
            display();
            //cin.ignore();
            QString name = QString::fromStdString(searchScientist());
            QSqlError error;
            if(_dom.removePerson(name, error) == false)
            {
                qDebug() << "Remove person error : " << error << endl;
            }
        }
        else if (input == "2")
        {
            
            QSqlError error;
            if(_dom.removeAllPersons(error) == false)
            {
                qDebug() << "Remove all persons error : " << error << endl;
            }
        }
        else if (input == "3")
        {
            _comp = _dom.readCompData(9);
            displayComputer();
            QString computer = QString::fromStdString(searchComputer());
            QSqlError error;
            if(_dom.removeComputer(computer, error))
            {
                qDebug() << "Remove computer error : " << error << endl;
            }
        }
        else if (input == "4")
        {
            QSqlError error;
            if(_dom.removeAllComputers(error) == false)
            {
                qDebug() << "Remove All computers error : " << error << endl;
            }
        }
        else if(input == "5")
        {
            displayConnections();
            QString sciId = QString::fromStdString(searchConnection());
            QSqlError error;
            if(_dom.removeConnection(sciId, error) == false)
            {
                qDebug() << "Remove connection error : " << error << endl;
            }
        }
        else if(input == "6")
        {
            QSqlError error;
            if(_dom.removeAllConnections(error) == false)
            {
                qDebug() << "Remove All connections error : " << error << endl;
            }
        }
    }while(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6");
}

string Console::getUpdate()
{
    cin.ignore();
    string name;
    cout << "Enter full name of scientist you want to update: ";
    getline(cin, name);
    return name;
}

string Console::getUpdateName()
{
    cin.ignore();
    string update;
    cout << "Enter new name: ";
    getline(cin, update);
    return update;
}

string Console::getUpdateGender()
{
    cin.ignore();
    string update;
    cout << "Enter new gender: ";
    getline(cin, update);
    return update;
}

string Console::getUpdateBirth()
{
    cin.ignore();
    string update;
    cout << "Enter new year of birth: ";
    getline(cin, update);
    return update;
}

string Console::getUpdateDeath()
{
    cin.ignore();
    string update;
    cout << "Enter new year of death: ";
    getline(cin, update);
    return update;
}

void Console::update()
{
    QString name = QString::fromStdString(getUpdate());
    int command;

    cout << endl;
    cout << "Enter 1 to update name" << endl;
    cout << "Enter 2 to update gender" << endl;
    cout << "Enter 3 to update year of birth" << endl;
    cout << "Enter 4 to update year of death" << endl;
    cin >> command;
    cout << endl;

    if(command == 1)
    {
        QString newName = QString::fromStdString(getUpdateName());
        _dom.updateScientistName(name, newName);
    }
    else if(command == 2)
    {
        QString newGender = QString::fromStdString(getUpdateGender());
        _dom.updateScientistGender(name, newGender);
    }
    else if(command == 3)
    {
        QString newBirth = QString::fromStdString(getUpdateBirth());
        _dom.updateScientistBirth(name, newBirth);
    }
    else if(command == 4)
    {
        QString newDeath = QString::fromStdString(getUpdateDeath());
        _dom.updateScientistDeath(name, newDeath);
    }
}

string Console::getComputerUpdate()
{
    cin.ignore();
    string computerName;
    cout << "Enter name of computer you want to update: ";
    getline(cin, computerName);
    return computerName;
}

string Console::getUpdateComputerName()
{
    cin.ignore();
    string update;
    cout << "Enter new name: ";
    getline(cin, update);
    return update;
}

string Console::getUpdateComputerYear()
{
    cin.ignore();
    string update;
    cout << "Enter new year: ";
    getline(cin, update);
    return update;
}

string Console::getUpdateComputerType()
{
    cin.ignore();
    string update;
    cout << "Enter new type: ";
    getline(cin, update);
    return update;
}

string Console::getUpdateComputerBuilt()
{
    cin.ignore();
    string update;
    cout << "Enter if it was built: ";
    getline(cin, update);
    return update;
}

void Console::updateComputer()
{
    QString computerName = QString::fromStdString(getComputerUpdate());
    int command;

    cout << "Enter 1 to update computer name" << endl;
    cout << "Enter 2 to update year" << endl;
    cout << "Enter 3 to update type" << endl;
    cout << "Enter 4 to update built" << endl;
    cin >> command;
    cout << endl;

    if(command == 1)
    {
        QString newName = QString::fromStdString(getUpdateComputerName());
        _dom.updateComputerName(computerName, newName);
    }
    else if(command == 2)
    {
        QString newYear = QString::fromStdString(getUpdateComputerYear());
        _dom.updateComputerYear(computerName, newYear);
    }
    else if(command == 3)
    {
        QString newType = QString::fromStdString(getUpdateComputerType());
        _dom.updateComputerType(computerName, newType);
    }
    else if(command == 4)
    {
        QString newBuilt = QString::fromStdString(getUpdateComputerBuilt());
        _dom.updateComputerBuilt(computerName, newBuilt);
    }
}

int Console::updateBy()
{
    int command;

    cout << "Enter 1 to search for a scientist" << endl;
    cout << "Enter 2 to search for a computer"  << endl << endl;
    cin >> command;
    return command;
}

int Console::gameplay()
{
    char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char player = 'X';
    int n = 0;
    while(1)
    {
        n++;
        bord(matrix);
        input(player, matrix);
        if (winner(matrix) == 'X')
        {
            bord(matrix);
            cout << "Winner is: X" << endl;
            break;
        }
        else if (winner(matrix) == 'O')
        {
            bord(matrix);
            cout << "Winner is: O" << endl;
            break;
        }
        else if (winner(matrix) == '/' && n == 9)
        {
            bord(matrix);
            cout << "Draw!" << endl;
            break;
        }
        changeplayer(player);
        winner(matrix);
    }
    return 0;
}

void Console::bord(char matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Console::input(char& player, char matrix[3][3])
{
    char a = '0';
    cout << player <<" position: ";
    cin >> a;
    if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9')
    {
        if (a == '1')
            {
                if (matrix[0][0] == '1')
                {
                    matrix[0][0] = player;
                }
                else
                {
                    cout << "Illegal move!" << endl;
                    input(player, matrix);
                }
            }
        if (a == '2')
            {
                if (matrix[0][1] == '2')
                {
                    matrix[0][1] = player;
                }
                else
                {
                    cout << "Illegal move!" << endl;
                    input(player, matrix);
                }
            }
        if (a == '3')
            {
                if (matrix[0][2] == '3')
                {
                    matrix[0][2] = player;
                }
                else
                {
                    cout << "Illegal move!" << endl;
                    input(player, matrix);
                }
            }
        if (a == '4')
            {
                if (matrix[1][0] == '4')
                {
                    matrix[1][0] = player;
                }
                else
                {
                    cout << "Illegal move!" << endl;
                    input(player, matrix);
                }
            }
        if (a == '5')
            {
                if (matrix[1][1] == '5')
                {
                    matrix[1][1] = player;
                }
                else
                {
                    cout << "Illegal move!" << endl;
                    input(player, matrix);
                }
            }
        if (a == '6')
            {
                if (matrix[1][2] == '6')
                {
                    matrix[1][2] = player;
                }
                else
                {
                    cout << "Illegal move!" << endl;
                    input(player, matrix);
                }
            }
        if (a == '7')
            {
                if (matrix[2][0] == '7')
                {
                    matrix[2][0] = player;
                }
                else
                {
                    cout << "Illegal move!" << endl;
                    input(player, matrix);
                }
            }
        if (a == '8')
            {
                if (matrix[2][1] == '8')
                {
                    matrix[2][1] = player;
                }
                else
                {
                    cout << "Illegal move!" << endl;
                    input(player, matrix);
                }
            }
        if (a == '9')
            {
                if (matrix[2][2] == '9')
                {
                    matrix[2][2] = player;
                }
                else
                {
                    cout << "Illegal move!" << endl;
                    input(player, matrix);
                }
            }
    }
    else
    {
        cout << "Illegal move!" << endl;
        input(player, matrix);
    }
}

void Console::changeplayer(char& player)
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

char Console::winner(char matrix[3][3])
{
    //Player X
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
        return 'X';
    // Player O
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
        return 'O';
    return '/';
}
