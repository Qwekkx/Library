#include <string>
#include "User.h"
#include "Book.h"
#include "Record.h"

struct Record;

class Client
{
private:
    Record *record;

public:
    Client() : borrow_record(NULL) {}
    ~Client();
    void recordUpdate(Record new_record);
};
