#include "Book.h"
#include "BookWare.h"
#include "Client.h"
#include "ClientWare.h"
#include <string>
#include <iostream>
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
};

