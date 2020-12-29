#include <iostream>
#include <string>
#include "Administrator.h"
using namespace std;
Administrator admin;

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
        {
            int func;
            cout << "Correct. \n";
        OPERATION:
            cout << "Select your operation:\n"
                 << "1 --> manage bookware\n"
                 << "2 --> manage clientware\n"
                 << "3 --> signout.\n";
            cin >> func;
            cout << endl;
            switch (func)
            {
            case 1:
            BOOKMANAGE:
                cout << "You are operating bookware.\nSelect your operation:\n"
                     << "1 --> change book informantion\n"
                     << "2 --> add new book\n"
                     << "3 --> delete a book\n"
                     << "4 --> search book information\n"
                     << "5 --> go back\n";
                cin >> func;
                switch (func)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 5:
                    goto OPERATION;
                default:
                    cout << "warning: invalid operation. Please change your input.\n\n";
                    goto BOOKMANAGE;
                }
                break;
            case 2:
                cout << "You are operating clientware.\nSelect your operation:\n"
                
                break;
            case 3:
                cout << "thanks for using";
                break;
            default:
                cout << "warning: invalid operation. Please change your input.\n\n";
                goto OPERATION;
            }
        }
    }
}