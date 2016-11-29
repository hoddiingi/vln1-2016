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
    string name;
    string sex;
    int birth;
    int death;
    cout << "Please enter name: ";
    cin >> name;
    cout << "Sex: ";
    cin >> sex;
    cout << "Year of birth: ";
    cin >> birth;
    cout << "Year of death, enter any letter if N/A : ";
    cin >> death;
}
