#include <string>
#include "User.h"
#include "Client.h"
#include <fstream>
#include <sstream>
#pragma once
class ClientWare
{
private:
    vector<Client> database;

public:
    void insert(Client *new_client) { database.push_back(*new_client); }
    Client *search(string username);
    void read_data();
    void save_data();
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

void ClientWare::read_data()
{
    ifstream fin("ClientWare.txt");
    string line;
    while (getline(fin, line))
    {
        string name, password;
        stringstream stream;
        stream << line;
        stream >> name >> password;
        this->insert(new Client(name, password));
    }
    fin.close();
}

void ClientWare::save_data()
{
    ofstream fout("ClientWare.txt");
    int capcity = database.size();
    for (int i = 0; i < capcity; i++)
        fout << database[i].user_name << ' ' << database[i].password << endl;
}