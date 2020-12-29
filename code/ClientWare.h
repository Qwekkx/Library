#include <string>
#include "User.h"
#include "Client.h"
#pragma once
class ClientWare
{
private:
    Client *root;
    long long capacity;

public:
    ClientWare() : root(NULL), capacity(0) {}
    void insert(Client new_client);
    Client *search(string username);
};