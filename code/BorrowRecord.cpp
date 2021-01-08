#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include "BorrowRecord.h"
using namespace std;

static list<string> R;
static bool fir=false;

string turnstring(int n)
{
    string a;
    while (n)
    {
        a = (char)(n % 10 + '0') + a;
        n/=10;
    }
    return a;
}

bool Record_RecordInitial()
{
    ifstream fin;
    
    fin.open("BorrowRecord.txt");
    string a;
    
    while(getline(fin,a))
    {
        if(a.size()>1)
            R.push_back(a);
    }
    return true;
}

string Record_allRecord()
{
    if(!fir){ Record_RecordInitial(); fir=true; }
    string outer="Here's all the borrowing archives records we have ;)\n";
    
    list<string>::iterator it=R.begin();
    while( it!= R.end())
    {
        outer=outer+'\n'+*it;
        it++;
    }
    return outer;
}

string Record_userRecord(string user)
{
    if(!fir){ Record_RecordInitial(); fir=true; }
    string outer = "Here's your borrowing archives records :)\n";

    int allrecord=0;
    list<string>::iterator it = R.begin();
    while (it != R.end())
    {
        if( user == it->substr(0,it->find(' ')) )
        {
            outer = outer + '\n' + it->substr(it->find(' ')+1);
        }
        it++;
    }
    return outer;
}

bool Record_changeUserRecord(string user, string title, string data, int dur, int num)
{
    if(!fir){ Record_RecordInitial(); fir=true; }
    
    string a=user+' ';
    
    if(num<0) a+="[Borrow] ";
    else if(num>0) a+="[Return] ";
    else if(num==0) return false;
    
    a+="amount:"+turnstring(num>0? num:-num)+' ';
    a+="title:"+title+' ';
    a+="data:"+data+' ';
    a+="duration:"+turnstring(dur)+'\n';
    
    R.push_back(a);
    
    return true;
}

bool Record_saveData()
{
    ofstream fout("BorrowRecord.txt");
    
    list<string>::iterator it=R.begin();
    while(it!=R.end()){
        fout<<*it<<"\n";
        it++;
    }
    return true;
}
