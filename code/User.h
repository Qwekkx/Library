#include <string>
#include <iostream>
#pragma once
using namespace std;

class User
{
public:
    string user_name;
    string password;
    User() {}
    User(string a, string b) : user_name(a), password(b) {}
    ~User() {}
    void set();
};

void User::set()
{
    cout << "Which would you like to reset?\n"
         << "1    --> username\n"
         << "2    --> password\n"
         << "else --> return\n";
    int func;
    cin >> func;
    switch (func)
    {
    case 1:
        cout << "Please input your new username\n";
        cin >> user_name;
        cout << "DONE\n";
        break;
    case 2:
        cout << "Please input your new password\n";
        cin >> password;
        cout << "DONE.\n";
    default:
        break;
    }
}