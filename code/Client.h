#include <string>
#include "User.h"
#include "Book.h"

struct Record;

class Client
{
private:
    Record *record;

public:
    Client() : borrow_record(NULL) {}
    ~Client();
    recordUpdate();
};

struct Record
{
    string name;
    string date;
    Book book;
    long long duration;
};