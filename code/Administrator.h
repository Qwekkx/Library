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

public:
    Administrator() : User() { ID = 666666, user_name = "Admin", password = "yysyqs"; }
    ~Administrator() {}
};

