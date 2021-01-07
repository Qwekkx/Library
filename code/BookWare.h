#include <string>
#include "Book.h"
#include <map>
#include <vector>
#include <algorithm>

#pragma once
using namespace std;

// 二叉搜索树以书名为关键码，为保证能用ISBN搜索，
// 使用map建立ISBN到name的索引，用ISBN搜索时先
// 转化为name

class BookWare
{
private:
    bookNode *root;
    map<string, string> ISBN_to_name;
    vector<Book> printList;

public:
    BookWare() : root(NULL) {}
    void insert(Book *book);
    void insert(Book *book, bookNode *&father);
    bookNode *SearchByName(string dst);
    bookNode *SearchByISBN(string dst);
    bookNode *SearchByName(string dst, bookNode *father);
    bookNode *SearchByISBN(string dst, bookNode *father);
    void SearchByAuthor(string vague);
    void SearchByAuthor(string vague, bookNode *father);
    void SearchByType(string vague);
    void SearchByType(string vague, bookNode *father);
    void *deleteBook(string book) {}
};

bookNode *BookWare::SearchByName(string dst)
{
    return SearchByName(dst, root);
}

bookNode *BookWare::SearchByISBN(string dst)
{
    return SearchByISBN(dst, root);
}

bookNode *BookWare::SearchByName(string dst, bookNode *father)
{
    if (father == NULL)
        return NULL;
    else if (dst == father->data.name)
        return father;
    else if (dst > father->data.name)
        return SearchByName(dst, father->right);
    else
        return SearchByName(dst, father->left);
}

//典型的二叉搜索树搜索数据函数，下同

bookNode *BookWare::SearchByISBN(string dst, bookNode *father)
{
    return SearchByName(ISBN_to_name[dst]);
}

void BookWare::SearchByAuthor(string vague)
{
    SearchByAuthor(vague, root);
    sort(printList.begin(), printList.end());
    long long Len = printList.size();
    for (int i = 0; i < Len; i++)
        printList[i].printInfo();
    printList.clear();
}

// 为保证按书名字典序输出，使用了vector储存输出列表
// 先作一个前序遍历，将符合要求的书存储到列表里，然后
// 按书名排序，最后逐个输出信息

void BookWare::SearchByAuthor(string vague, bookNode *father)
{
    if (father == NULL)
        return;
    else if (father->data.author == vague)
        printList.push_back(father->data);
    SearchByAuthor(vague, father->left);
    SearchByAuthor(vague, father->right);
}

void BookWare::SearchByType(string vague)
{
    SearchByType(vague, root);
    sort(printList.begin(), printList.end());
    long long Len = printList.size();
    for (int i = 0; i < Len; i++)
        printList[i].printInfo();
    printList.clear();
}

void BookWare::SearchByType(string vague, bookNode *father)
{
    if (father == NULL)
        return;
    else if (father->data.type == vague)
        printList.push_back(father->data);
    SearchByType(vague, father->left);
    SearchByType(vague, father->right);
}

void BookWare::insert(Book *book)
{
    if (SearchByName(book->name) == NULL)
    {
        insert(book, root);
        ISBN_to_name[book->ISBN] = book->name;
    }
    else
        return;
}

//典型的二叉搜索树插入语句

void BookWare::insert(Book *book, bookNode *&father)
{
    if (father == NULL)
    {
        father = new bookNode;
        father->data = *book;
    }
    else if (father != NULL)
    {
        if (father->data.name > book->name)
            insert(book, father->left);
        else if (father->data.name < book->name)
            insert(book, father->right);
    }
}
