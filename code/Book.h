#include <string>
#pragma once
using namespace std;

class Book
{
public:
    long long ID;
    bool lended;
    string name;
    string ISBN;
    string author;
    string type;
    Book *left;
    Book *right;

    Book() : ID(0), lended(false), left(NULL), right(NULL) {}
    Book(string a, string b, string c, string d) : name(a), ISBN(b), author(c), type(d) {}
};