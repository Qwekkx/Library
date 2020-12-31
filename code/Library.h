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

public:
    Library() : admin(new Administrator),
                book_ware(new BookWare),
                client(NULL),
                client_ware(new ClientWare) {}
    void run();
};

void Library::run()
{
    string name, password;
    cout << "Please enter your username: \n";
    cin >> name;
    cout << endl;
    if (name == admin->user_name)
    {
        cout << "Administrator, Please enter your password:\n";
        cin >> password;
        cout << endl;
        if (password == admin->password)
            admin->run();
    }
    else
    {
    }
}
