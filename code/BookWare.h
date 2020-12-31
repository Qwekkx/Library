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
    void insert(Book *book) {}
    Book *accuSearch(string accur) { return new Book; }
    Book *search(long long ID);
    void vagueSearchAuthor(string vague) {}
    void vagueSearchType(string vague) {}
    Book *deleteBook(string book) {}
    void printInf(Book *book) {}
};