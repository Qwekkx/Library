#include "Administrator.h"
#include "Client.h"
#include "ClientWare.h"
#include "BookWare.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#pragma once

class Library
{
public:
    Administrator *admin;
    BookWare *book_ware;
    Client *client;
    ClientWare *client_ware;
    void userRun();
    void adminRun();
    void chang_book_information();
    void add_new_book();
    void add_new_client();
    void delete_book();
    void search_book_information();
    void borrow_book();
    void change_client_info();
    void search_client_info();

public:
    Library();
    void run();
    void initialization();
    void save_data();
};

// 仅有三个公有接口，其余皆为私有接口，供公有接口run()使用
// 成员变量皆为指针，

Library::Library() : admin(new Administrator),
                     book_ware(new BookWare),
                     client(NULL),
                     client_ware(new ClientWare) {}
// 通过初始化列表为所有指针new空间

void Library::run()
{
    string name;
    cout << "Please enter your username: \n";
    cin >> name;
    cout << endl;
    if (name == admin->user_name)
        adminRun();
    else
    {
        client = client_ware->search(name);
        system("cls");
        if (client == NULL)
            cout << "User not found,please check out.";
        else
            userRun();
    }
}
//run()为主程序，首先要求用户提供用户名，并判断是否有该用户

void Library::adminRun()
{
    string password;
    system("cls");
    cout << "Administrator, Please enter your password:\n";
    cin >> password;
    cout << endl;
    system("cls");
    if (password != admin->password)
    {
        cout << "password wrong, endding program.";
        system("pause");
        return;
    }
    int func;
    cout << "Correct. \n";
OPERATION:
    cout << "Select your operation:\n"
         << "1 --> manage bookware\n"
         << "2 --> manage clientware\n"
         << "3 --> change my username or password\n"
         << "4 --> signout.\n";
    cin >> func;
    cout << endl;
    switch (func)
    {
    case 1:
    BOOKMANAGE:
        system("cls");
        cout << "You are operating bookware.\nSelect your operation:\n"
             << "1 --> change book informantion\n"
             << "2 --> add new book\n"
             << "3 --> delete a book\n"
             << "4 --> search book information\n"
             << "5 --> go back\n";
        cin >> func;
        cout << endl;
        switch (func)
        {
        case 1:
            chang_book_information();
            goto BOOKMANAGE;
        case 2:
            add_new_book();
            goto BOOKMANAGE;
        case 3:
            delete_book();
            goto BOOKMANAGE;
        case 4:
            search_book_information();
            goto BOOKMANAGE;
        case 5:
            goto OPERATION;
        default:
            cout << "warning: invalid operation. Please change your input.\n\n";
            goto BOOKMANAGE;
        }
        break;
    case 2:
    CLIENTMANAGE:
        system("cls");
        cout << "You are operating clientware.\nSelect your operation:\n"
             << "1 --> change client information\n"
             << "2 --> add new client\n"
             << "3 --> search client information\n"
             << "4 --> go back\n";
        cin >> func;
        switch (func)
        {
        case 1:
            change_client_info();
            goto CLIENTMANAGE;
            break;
        case 2:
            add_new_client();
            goto CLIENTMANAGE;
            break;
        case 3:
            search_client_info();
            goto CLIENTMANAGE;
            break;
        case 4:
            goto OPERATION;

        default:
            cout << "warning: invalid operation. Please change your input.\n\n";
            goto CLIENTMANAGE;
        }
        break;
    case 3:
        admin->set();
        goto OPERATION;
    case 4:
        cout << "thanks for using";
        break;
    default:
        cout << "warning: invalid operation. Please change your input.\n\n";
        goto OPERATION;
    }
}

void Library::userRun()
{
    string password;
    cout << "Please enter your password:\n";
    cin >> password;
    cout << endl;
    system("cls");
    if (password != client->password)
    {
        cout << "password wrong, endding program.";
        system("pause");
        return;
    }
    int func;
    cout << "Correct.\n";
OPERATION:
    cout << "Select your operation:\n"
         << "1 --> search book\n"
         << "2 --> borrow book\n"
         << "3 --> check my borrow record\n"
         << "4 --> change my username or password\n"
         << "5 --> sign out\n";
    cin >> func;
    cout << endl;
    switch (func)
    {
    case 1:
        search_book_information();
    case 2:
        borrow_book();
    case 3:
        client->check_record();
    case 4:
        client->set();
    default:
        cout << "warning: invalid operation. Please change your input.\n\n";
        goto OPERATION;
    }
}

void Library::chang_book_information()
{
    system("cls");
    cout << "Please input the book name or ISBN.\n"
         << "1 -->name\n"
         << "2 -->ISBN\n";
    int func;
    cin >> func;
    cout << "Please input your content:\n";
    string str;
    cin >> str;
    cout << endl;
    bookNode *selected;
    switch (func)
    {
    case 1:
        selected = book_ware->SearchByName(str);
        break;
    case 2:
        selected = book_ware->SearchByISBN(str);
        break;
    }
    if (selected == NULL)
    {
        cout << "Book not found\n";
        system("pause");
        return;
    }
    cout << "Which do you want to change?\n"
         << "1 --> name\n"
         << "2 --> ISBN\n"
         << "3 --> type\n"
         << "4 --> author\n";
    cin >> func;
    cout << "input your content\n";
    cin >> str;
    switch (func)
    {
    case 1:
        selected->data.name = str;
        break;
    case 2:
        selected->data.ISBN = str;
        break;
    case 3:
        selected->data.type = str;
        break;
    case 4:
        selected->data.author = str;
        break;
    }
    cout << "DONE\n\n";
}

void Library::add_new_book()
{
    system("cls");
    Book *new_book = new Book;
    cout << "Please input book name,ISBN,author,type by order.\n"
         << "name:";
    cin.get();
    getline(cin, new_book->name);
    cout << endl
         << "ISBN:";
    getline(cin, new_book->ISBN);
    cout << endl
         << "author:";
    getline(cin, new_book->author);
    cout << endl
         << "type:";
    getline(cin, new_book->type);
    book_ware->insert(new_book);
    cout << "Done.\n\n";
}

void Library::delete_book()
{
    system("cls");
    string str;
    cout << "Please input book name or ISBN:\n";
    cin >> str;
    book_ware->deleteBook(str);
    cout << "Done\n\n";
}

void Library::search_book_information()
{
    system("cls");
    cout << "Which way do you like to search by?\n"
         << "1 --> name\n"
         << "2 -->ISBN\n"
         << "3 --> author\n"
         << "4 --> type\n";
    int func;
    cin >> func;
    string str;
    cout << "Please input your content:\n";
    cin >> str;
    bookNode *book;
    switch (func)
    {
    case 1:
        book = book_ware->SearchByName(str);
        if (book == NULL)
        {
            cout << "Book not found\n";
            system("pause");
            return;
        }
        book->data.printInfo();
        break;
    case 2:
        book = book_ware->SearchByISBN(str);
        if (book == NULL)
        {
            cout << "Book not found\n";
            system("pause");
            return;
        }
        book->data.printInfo();
        break;

    case 3:
        book_ware->SearchByAuthor(str);
        break;
    case 4:
        book_ware->SearchByType(str);
        break;
    }
    cout << "DONE\n\n";
}

void Library::borrow_book()
{
    system("cls");
    cout << "Please input the book's name which you want to borrow.\n";
    string name;
    bookNode *borrowed = book_ware->SearchByName(name);
    if (borrowed == NULL)
    {
        cout << "Book not found\n";
        system("pause");
        return;
    }
    cout << "Please input the borrow date like '2020 12 31'\n";
    string date;
    cin.get();
    getline(cin, date);
    cout << "Please input the duration:\n";
    long long duration;
    cin >> duration;
    Record new_record{name, date, &borrowed->data, duration};
    client->recordUpdate(new_record);
}

void Library::change_client_info()
{
    system("cls");
    cout << "Input the client name\n";
    string str;
    cin >> str;
    cout << endl;
    Client *selected = client_ware->search(str);
    if (selected == NULL)
    {
        cout << "Client not found\n";
        system("pause");
        return;
    }
    cout << "Which do you want to change?\n"
         << "1 --> username\n"
         << "2 --> password\n";
    int func;
    cin >> func;
    cout << "input your content\n";
    cin >> str;
    switch (func)
    {
    case 1:
        selected->user_name = str;
        break;
    case 2:
        selected->password = str;
    }
    cout << "DONE\n\n";
}

void Library::add_new_client()
{
    system("cls");
    Client *new_client = new Client;
    cout << "Please input username and password by order.\n"
         << "username:";
    cin.get();
    getline(cin, new_client->user_name);
    cout << endl
         << "password:";
    getline(cin, new_client->password);
    client_ware->insert(new_client);
    cout << "Done.\n\n";
}

void Library::search_client_info()
{
    system("cls");
    cout << "Please input username:\n";
    string str;
    cin >> str;
    Client *selected = client_ware->search(str);
    if (selected == NULL)
    {
        cout << "Client not found\n";
        system("pause");
        return;
    }
    selected->printInfo();
    cout << "DONE\n\n";
}

void Library::initialization()
{
    ifstream fin("Admin.txt");
    string a, b;
    fin >> a >> b;
    admin->user_name = a;
    admin->password = b;
    fin.close();
    fin.open("ClientWare.txt");
    string line;
    while (getline(fin, line))
    {
        string name, password;
        stringstream stream;
        stream << line;
        stream >> name >> password;
        Client *new_client = new Client;
        new_client->user_name = name;
        new_client->password = password;
        client_ware->insert(new_client);
    }
    fin.close();
    fin.open("BookWare.txt");
    while (getline(fin, line))
    {
        string name, ISBN, author, type;
        stringstream stream;
        stream << line;
        stream >> name >> ISBN >> author >> type;
        Book *new_book = new Book;
        new_book->name = name, new_book->ISBN = ISBN,
        new_book->author = author, new_book->type = type;
        book_ware->insert(new_book);
    }
    fin.close();
}

void Library::save_data()
{
    ofstream fout("Admin.txt");
    fout << admin->user_name << ' ' << admin->password;
}
