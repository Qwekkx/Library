#include <string>
#include "User.h"
#include "Book.h"
#include "Record.h"
#pragma once
struct Record;

class Client
{
private:
    Record *record;

public:
    Client() : record(NULL) {}
    ~Client();
    void recordUpdate(Record new_record);
};
