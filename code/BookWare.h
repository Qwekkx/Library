#include <string>
#include "Book.h"
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

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
    ~BookWare() { deleteAll(root); }
    void deleteAll(bookNode *&father);
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
    void deleteBook(string name);
    void deleteBook(string name, bookNode *&father);
    void read_data();
    void save_data();
    void save_data(bookNode *father);
};

void BookWare::deleteAll(bookNode *&father)
{
    deleteAll(father->left);
    deleteAll(father->right);
    delete father;
}
//析构时调用该函数，希望能跑起来

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
//典型的二叉搜索树插入语句

bookNode *BookWare::SearchByName(string dst)
{
    return SearchByName(dst, root);
}
//区分外部接口和内部接口
//递归函数必须要有bookNode实参才能实现，但是对外接口不可能用这个
//所以重载了函数来区分内外接口

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
    if (Len == 0)
    {
        cout << "Books not found.\n";
        return;
    }
    cout << "find " << Len << " books:\n";
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
    if (Len == 0)
    {
        cout << "Books not found.\n";
        return;
    }

    for (int i = 0; i < Len; i++)
        printList[i].printInfo();
    printList.clear();
}

void BookWare::SearchByType(string vague, bookNode *father)
{
    if (father == NULL)
        return;
    else
    {
        int len = vague.size();
        bool judge = true;
        for (int i = 0; i < len; i++)
            if (vague[i] != father->data.type[i])
                judge = false;
        if (judge)
            printList.push_back(father->data);
    }
    SearchByType(vague, father->left);
    SearchByType(vague, father->right);
}
//基本实现和按作者搜索类似
//区别是使用了模糊搜索

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
//典型的二叉搜索树搜索算法
//不过还需要添加map中的键值对

void BookWare::read_data()
{
    ifstream fin("BookWare.txt");
    string line;
    while (getline(fin, line))
    {
        string name, ISBN, author, type;
        int num;
        stringstream stream;
        stream << line;
        stream >> name >> ISBN >> author >> type >> num;
        this->insert(new Book(name, ISBN, author, type, num));
    }
    fin.close();
}

void BookWare::save_data()
{
    ofstream fout("text.txt", ios::out | ios::trunc);
    fout.close();
    save_data(root);
}
//前两个函数语句的作用是清空文件中原本的数据

void BookWare::save_data(bookNode *father)
{
    if (father == NULL)
        return;
    else
    {
        ofstream fout("BookWare.txt", ios::app);
        fout << father->data.name << ' ' << father->data.ISBN << ' '
             << father->data.author << ' ' << father->data.type << ' '
             << father->data.num << endl;
        save_data(father->left);
        save_data(father->right);
    }
}
//前序遍历模拟存档

void BookWare::deleteBook(string name)
{
    deleteBook(name, root);
}

void BookWare::deleteBook(string name, bookNode *&father)
{
    bookNode *tmp;
    if (father != NULL)
    {
        if (name < father->data.name)
            deleteBook(name, father->left);
        else if (name > father->data.name)
            deleteBook(name, father->left);
        else if (father->left != NULL && father->right != NULL)
        {
            tmp = father->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            father->data = tmp->data;
            deleteBook(father->data.name, father->right);
        }
        else
        {
            tmp = father;
            if (father->left == NULL)
                father = father->right;
            else
                father = father->right;
            delete tmp;
        }
    }
}
//标准的二叉搜索树删除算法