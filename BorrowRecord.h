#pragma once
#include <string>

using std::string;

bool Record_RecordInitial();

string Record_allRecord();

string Record_userRecord(string user);

bool Record_changeUserRecord(string user, string title, string data, int dur, int num);

bool Record_saveData();

string Record_turnstring(int n);

bool Record_returnBook(string user, string title);

// 我感觉没有这个文件，程序照样能跑唉
// 毕竟只有函数声明XD