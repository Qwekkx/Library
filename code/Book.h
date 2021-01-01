#include <string>
#pragma once
using namespace std;

class Book
{
public:
    bool lended;
    string name;
    string ISBN;
    string author;
    string type;

    Book() : ID(0), lended(false), left(NULL), right(NULL) {}
    Book(string a, string b, string c, string d) : name(a), ISBN(b), author(c), type(d) {}
};

struct bookNode
{
    bookNode() : left(NULL), right(NULL) {}
    bookNode(Book book) : data(book), left(NULL), right(NULL) {}
    Book data;
    bookNode *left, *right;
};
