#pragma once
#include<iostream>
#include"Registed.h"
#include"Book.h"
#include<string>
#include<vector>
using namespace std;

class Member:public RegistedUser
{
    private:
        int startYear;
        int endYear;
        vector<Book*> BorrowBook;
    public:
        Member();
        Member(string, string, string, string, int, int);
        ~Member();
        virtual void read();
        void Borrow(Book*);
        void Return(Book*);
        void Subcribe();
        void Unsubcribe();
        void DisplayCollectionList();
        void DisplayBorrowList();
};