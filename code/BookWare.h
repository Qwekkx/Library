#include <string>
#include "Book.h"
#include "Administrator.h"
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
    friend Administrator;
    BookWare() : root(NULL), capacity(0) {}
    void insert(Book book);
    Book search(string accur);
    Book Search(string vague);
    Book search(long long ID);
};