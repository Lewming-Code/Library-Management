#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Book.h"
using namespace std;
static vector<Book*> ListBook;
class Collection
{
    private:
        int Cid;
        string CollectionName;
        vector<Book*> ListBook;
        vector<Member*> SubMember;
    public:
        Collection();
        Collection(int, string);
        ~Collection();
        void setCID(int);
        int getCID();
        void setCollectionName(string);
        string getCollectionName();
        int getBookListSize();
        void AddBook(Book*);
        void RemoveBook(string);
        void AddSub(Member*);
        void RemoveSub(Member*);
        void ListBookDisplay( User*);
        bool checkSub(Member*);
        Book* getBookT(string);
        Book* getBookS(string);
        Book* FindBook(string);

};