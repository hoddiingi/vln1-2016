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
    string sex;
    int birth;
    int death;
    cout << "Please enter name: ";
    cin >> name;
    cout << "Sex (f/m): ";
    cin >> sex;
    cout << "Year of birth: ";
    cin >> birth;
    cout << "Year of death, enter any letter if N/A : ";
    cin >> death;
}
