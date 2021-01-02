#include <string>
#include <iostream>
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

    Book() : lended(false) {}
    Book(string a, string b, string c, string d) : name(a), ISBN(b), author(c), type(d) {}
    void printInfo();
    bool operator<(Book anthor) { return this->name < anthor.name; }
};

struct bookNode
{
    bookNode() : left(NULL), right(NULL) {}
    bookNode(Book book) : data(book), left(NULL), right(NULL) {}
    void printInfo();
    Book data;
    bookNode *left, *right;
};

void Book::printInfo()
{
    cout << "name: " << name << " ISBN: " << ISBN << " author: " << author << " type: " << type << endl;
}
