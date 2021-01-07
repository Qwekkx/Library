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
    Client *search(string username);
};
// 使用vector存储用户数据

Client *ClientWare::search(string username)
{
    for (vector<Client>::iterator it = database.begin(); it != database.end(); it++)
        if (it->user_name == username)
            return &*it;
    return NULL;
}

// 搜索用户数据，简单的遍历，返回一个指向用户的指针，若无搜索用户返回NULL