#include <string>
#include <iostream>
#pragma once
using namespace std;

class Book
{
public:
    int num;
    string name;
    string ISBN;
    string author;
    string type;
    Book() : num(0) {}
    Book(string a, string b, string c, string d, int e) : num(e), name(a), ISBN(b), author(c), type(d) {}
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
    cout << "name: " << name << " ISBN: " << ISBN << " author: "
         << author << " type: " << type << " num :" << num << endl;
}
