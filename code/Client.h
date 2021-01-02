#include <string>
#include <iostream>
#include "User.h"
#include "Book.h"
#include "Record.h"
#include <vector>
#pragma once

class Client : public User
{
private:
    vector<Record> database;

public:
    Client() : record(NULL) {}
    ~Client() {}
    void recordUpdate(Record new_record) {}
    void check_record(){};
    void printInfo();
};

void Client::printInfo()
{
    cout << "username: " << user_name << " password: " << password << endl;
}

void Client::recordUpdate(Record new_record)
{
    database.push_back(new_record);
}

void Client::check_record()
{
    int len = database.size();
    for (int i = 0; i < len; i++)
        database[i].printInfo();
}
