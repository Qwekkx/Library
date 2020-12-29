#include <string>
#pragma once
using namespace std;

class User
{
protected:
    long long ID;
    string user_name;
    string password;
    bool Admin;

public:
    User();
    ~User();
};