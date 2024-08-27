#pragma once
#include<iostream>
#include"Registed.cpp"
#include"Book.cpp"
#include"Member.h"
#include<string>
#include<vector>
using namespace std;

Member::Member(){
        startYear = 0;
        endYear = 0;
}
Member::Member(string un, string pw, string p, string fn, int sy, int ey):RegistedUser(un, pw, p, fn){
        startYear = sy;
        endYear = ey;
        setAccessLevel(member);
}
Member::~Member(){
        if(!BorrowBook.empty()){
        for(int i =0; i<BorrowBook.size(); i++){
            if(BorrowBook[i])
            delete BorrowBook[i];
        }
    }
}
void Member::read(){
        cout<<"Member is reading"<<endl;
}
void Member::Borrow(Book* b){
        Book* Temp;
        Temp = b;
        cout<<"Borrowing book"<<endl;
        if(b->getAvabilityStat() && b->getVisibilityStat()){
                b->setAvabilityStat(false);
                BorrowBook.push_back(Temp);
        }
        else cout<<"Book not available to borrow."<<endl;
}
void Member::Return(Book* b){
        bool check = false;
        cout<<"Returning book"<<endl;
        for(int i =0; i<BorrowBook.size(); i++){
                if(BorrowBook[i]->getTitle() == b->getTitle()){
                        b->setAvabilityStat(true);
                        Book* Temp = BorrowBook[i];
                        BorrowBook[i] = BorrowBook[BorrowBook.size()];
                        BorrowBook[BorrowBook.size()] = Temp;   
                        check = true;
                        BorrowBook.pop_back();
                        break;
                }
                
        }
        if(check == false) cout<<"Book not exit in borrow list"<<endl;
}
void Member::Subcribe(){
        cout<<"Subcribing to the list";
}
void Member::Unsubcribe(){
        cout<<"Unsubcribe to the list";
}
void Member::DisplayCollectionList(){
        cout<<"Displaying collection list";
}
void Member::DisplayBorrowList(){
        cout<<setw(10)<<"Title"<<setw(10)<<"Serial"<<setw(10)<<"Author"<<endl;
        cout<<"======================================="<<endl;
        for(int i=0; i<BorrowBook.size(); i++){
            cout<<setw(10)<<BorrowBook[i]->getTitle()<<setw(10)<<BorrowBook[i]->getSerialnumber()<<setw(10)<<BorrowBook[i]->getAuthor()<<endl;
        }
}