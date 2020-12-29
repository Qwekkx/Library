#include "Book.h"
#include "User.h"
#include "BookWare.h"
#include <string>
#pragma once

class Administrator : public User
{
private:
    BookWare book_ware;

public:
    Administrator() : User() { Admin = true; }
    Administrator(string a, string b) : User() { user_name = a, password = b; }
    ~Administrator() {}
};

int main()
{
    Administrator a("123", "456");
    system("pause");
}