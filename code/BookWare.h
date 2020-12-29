#include <string>
#include "Book.h"
#include <map>

#pragma once
using namespace std;

class BookWare
{
private:
    Book *root;
    long long capacity;
    map<string, long long> name_and_ISDN_to_ID;

public:
    BookWare() : root(NULL), capacity(0) {}
    ~BookWare();
    void insert(Book book);
    Book search(string accur);
    Book search(long long ID);
    Book Search(string vague);
};