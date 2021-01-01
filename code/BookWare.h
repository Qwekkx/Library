#include <string>
#include "Book.h"
#include <map>
#include <vector>

#pragma once
using namespace std;

class BookWare
{
private:
    bookNode *root;
    map<string, string> name_to_ISBN;

public:
    BookWare() : root(NULL), capacity(0) {}
    void insert(Book *book);
    void Library::insert(Book *book, bookNode *father);
    bookNode *SearchByName(string dst, bookNode *father = root);
    bookNode *SearchByISBN(string dst, bookNode *father = root);
    void SearchByAuthor(string vague, bookNode *father = root);
    void SearchByType(string vague) {}
    void *deleteBook(string book) {}
    void printInf(Book *book) {}
};

bookNode *BookWare::SearchByName(string dst, bookNode *father)
{
    if (father == NULL)
        return NULL;
    else if (dst == father->data->name)
        return father;
    else if (dst > father->data)
        return search(dst, father->right);
    else if (dst < father->data)
        return search(dst, father->left);
}

bookNode *BookWare::SearchByType(string dst, bookNode *father)
{
    map<string, string>::iterator it_find;
    it_find = name_to_ISBN.find(dst);
    return SearchByName(it_find->second)
}

void BookWare::SearchByAuthor(string vague, bookNode *father = root)
{
    if (father = NULL)
        return;
    else if ()
}

void BookWare::insert(Book *book)
{
    if (SearchByName(book->name) == NULL)
    {
        insert(book, root);
        ISBN_to_name.insert(book->ISBN, book->name);
    }
    else
        return;
}

void BookWare::insert(Book *book, bookNode *father)
{
    if (father == NULL)
    {
        father = new bookNode;
        father->data = *book;
    }
    else if (father != NULL)
    {
        if (father->data->name > book->name)
            insert(book, father->left);
        else if (ather->data->name < book->name)
            insert(book, father->right);
    }
}
