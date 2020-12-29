#include "Book.h"
#include "User.h"
#include <string>
#pragma once

class Administrator : public User
{
public:
    Administrator() : User() { Admin = true; }
    Administrator(string a, string b) : User(), user_name(a), password(b) {}
    ~Administrator() {}
};

int main()
{
    
}