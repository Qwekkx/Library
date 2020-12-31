#include "Administrator.h"
#include "Client.h"
#include "ClientWare.h"
#include "BookWare.h"
#include <iostream>
#include <string>
using namespace std;
#pragma once

class Library
{
private:
    Administrator *admin;
    BookWare *book_ware;
    Client *client;
    ClientWare *client_ware;
    void userRun();
    void adminRun();

public:
    Library();
    void run();
};

Library::Library() : admin(new Administrator),
                     book_ware(new BookWare),
                     client(NULL),
                     client_ware(new ClientWare) {}

void Library::run()
{
    string name;
    cout << "Please enter your username: \n";
    cin >> name;
    cout << endl;
    if (name == admin->user_name)
    {
        adminRun();
    }
    else
    {
        client = client_ware->search(name);
        if (client == NULL)
            cout << "User not found,please check out.";
        else
            userRun();
    }
}

void Library::adminRun()
{
    string password;
    cout << "Administrator, Please enter your password:\n";
    cin >> password;
    cout << endl;
    if (password != admin->password)
        return;
    int func;
    cout << "Correct. \n";
OPERATION:
    cout << "Select your operation:\n"
         << "1 --> manage bookware\n"
         << "2 --> manage clientware\n"
         << "3 --> change my username or password\n"
         << "4 --> signout.\n";
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
            chang_book_information();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
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
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            goto OPERATION;

        default:
            cout << "warning: invalid operation. Please change your input.\n\n";
            goto CLIENTMANAGE;
        }
        break;
    case 3:
        admin->set();
        goto OPERATION;
    case 4:
        cout << "thanks for using";
        break;
    default:
        cout << "warning: invalid operation. Please change your input.\n\n";
        goto OPERATION;
    }
}

void Library::userRun()
{
    string password;
    cout << "Please enter your password:\n";
    cin >> password;
    cout << endl;
    if (password != client->password)
        return;
    int func;
    cout << "Correct.\n";
OPERATION:
    cout << "Select your operation:\n"
         << "1 --> search book\n"
         << "2 --> borrow book\n"
         << "3 --> check my borrow record\n"
         << "4 --> change my username or password\n"
         << "5 --> sign out\n";
    cin >> func;
    cout << endl;
    switch (func)
    {
    case 1:
    case 2:
    case 4:
        client->set();
    default:
        cout << "warning: invalid operation. Please change your input.\n\n";
        goto OPERATION;
    }
}

void Library::chang_book_information()
{
    cout << "Please input the book name or ISBN.\n";
    string str;
    cin >> str;
    Book *selected = accuSearch(str);
    cout << "Which do you want to change?\n"
         << "1 --> name\n"
         << "2 --> ISBN\n"
         << "3 --> type\n"
         << "4 --> author\n";
    int func;
    cout << "input your content";
    cin >> str;
    switch (func)
    {
    case 1:
        selected
    }
}