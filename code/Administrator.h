#include "Book.h"
#include "User.h"
#include "BookWare.h"
#include "ClientWare.h"
#include <string>
#pragma once

class Administrator : public User
{
private:
    BookWare book_ware;
    ClientWare client_ware;

public:
    Administrator() : User() { Admin = true; }
    Administrator(string a, string b) : User() { user_name = a, password = b; }
    ~Administrator() {}
};
