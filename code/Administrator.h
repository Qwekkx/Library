#include "Book.h"
#include "BookWare.h"
#include "Client.h"
#include "ClientWare.h"
#include <string>
#pragma once

class Administrator : public User
{
private:
    BookWare book_ware;
    ClientWare client_ware;

public:
    Administrator() : User() { ID = 666666, user_name = "Admin", password = "yysyqs"; }
    ~Administrator() {}
    Administrator(string a, string b) : User() { user_name = a, password = b; }
    void function();
};

void Administrator::function()
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
    CLIENTMANAGE:
        cout << "You are operating clientware.\nSelect your operation:\n"
             << "1 --> change client information\n"
             << "2 --> add new client\n"
             << "3 --> reset client information\n"
             << "4 -->search client information\n"
             << "5-->go back\n";
        cin >> func;
        switch (func)
        {
        case 1:
            break;
        case 5:
            goto OPERATION;

        default:
            cout << "warning: invalid operation. Please change your input.\n\n";
            goto CLIENTMANAGE;
        }
        break;
    case 3:
        cout << "thanks for using";
        break;
    default:
        cout << "warning: invalid operation. Please change your input.\n\n";
        goto OPERATION;
    }
}
