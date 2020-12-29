#include <iostream>
#include <string>
#include "Administrator.h"
using namespace std;
Administrator admin;
Client client;
int main()
{
    string name, password;
    cout << "Please enter your username: \n";
    cin >> name;
    cout << endl;
    if (name == admin.user_name)
    {
        cout << "Administrator, Please enter your password:\n";
        cin >> password;
        cout << endl;
        if (password == admin.password)
            admin.function();
    }
}