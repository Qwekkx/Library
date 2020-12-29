#include <string>
#pragma once
using namespace std;

class User
{
public:
    long long ID;
    string user_name;
    string password;
    void setUserName(string str) { user_name = str; }
    void setPassword(string str) { password = str; }
    User() {}
    ~User() {}
};