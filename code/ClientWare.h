#include <string>
#include "User.h"
#include "Client.h"
#pragma once
class ClientWare
{
private:
    vector<Client> database;

public:
    void insert(Client *new_client) { database.push_back(*new_client); }
    Client *search(string username) {}
    void print(Client *client) {}
};

Client *ClientWare::search(string username)
{
    for (vector<Client>::iterator it = database.begin(); it != database.end(); it++)
        if (it->user_name == username)
            return it;
}