#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"Book.cpp"
#include"Collection.h"
using namespace std;

Collection::Collection(){
    Cid = 0;
    CollectionName = "";
}
Collection::Collection(int ID, string cn){
    setCID(ID);
    setCollectionName(cn);
}
Collection::~Collection(){
    if(!ListBook.empty()){
        for(int i =0; i<ListBook.size(); i++){
            if(ListBook[i])
            delete ListBook[i];
        }
    }
    if(!SubMember.empty()){
        for(int i =0; i<SubMember.size(); i++){
            if(SubMember[i])
            delete SubMember[i];
        }
    }
}
void Collection::setCID(int ID){
    Cid =ID;
}
int Collection::getCID(){
    return Cid;
}
void Collection::setCollectionName(string cn){
    CollectionName = cn;
}
string Collection::getCollectionName(){
    return CollectionName;
}
int Collection::getBookListSize(){
    return ListBook.size();
}
void Collection::AddBook(Book* b){
    this->ListBook.push_back(b);
}
void Collection::RemoveBook(string t){
    for(int i=0; i<ListBook.size(); i++){
        if(ListBook[i]->getTitle()== t)
        delete ListBook[i];
    }
}
void Collection::AddSub(Member* m){
    SubMember.push_back(m);
}
void Collection::RemoveSub(Member* m){
    if(!SubMember.empty()){
        for(int i =0; i<SubMember.size(); i++){
            if(SubMember[i]->getID() == m->getID()){
                Member* Temp = SubMember[i];
                SubMember[i] = SubMember[SubMember.size()-1];
                SubMember[SubMember.size()-1] = Temp;
            } 
        }
        SubMember.pop_back();
    }
}
void Collection::ListBookDisplay(User* u){
    if(!ListBook.empty()){
        cout<<setw(10)<<"Title"<<setw(10)<<"Serial"<<setw(10)<<"Author"<<endl;
        cout<<"======================================="<<endl;
        for(int i =0; i<ListBook.size(); i++){
            if(u->getAccessLevel() == member || u->getAccessLevel() == guest){
                if(ListBook[i]->getAvabilityStat() && ListBook[i]->getVisibilityStat())
                cout<<setw(10)<<ListBook[i]->getTitle()<<setw(10)<<ListBook[i]->getSerialnumber()<<setw(10)<<ListBook[i]->getAuthor()<<endl;
            }
            else if(u->getAccessLevel()==admin){
                if(!ListBook[i]->getVisibilityStat())
                    cout<<setw(10)<<ListBook[i]->getTitle()<<setw(10)<<ListBook[i]->getSerialnumber()<<setw(10)<<ListBook[i]->getAuthor()<<setw(10)<<"Hidden"<<endl;
                else 
                    cout<<setw(10)<<ListBook[i]->getTitle()<<setw(10)<<ListBook[i]->getSerialnumber()<<setw(10)<<ListBook[i]->getAuthor()<<endl;
                
            }
        }
    }
}
bool Collection::checkSub(Member* m){
    bool check = false;
    for(int i = 0;i<SubMember.size(); i++){
        if(SubMember[i]->getID() == m->getID()){
            check = true;
            break;
        }
    }
    return check;
}
Book* Collection::getBookT(string b){
    bool check = false;
    Book* Temp = new Book();
    for(int i =0; i<ListBook.size(); i++){
        if(ListBook[i]->getTitle() == b){
            cout<<setw(10)<<"Title"<<setw(10)<<"Serial"<<setw(10)<<"Author"<<endl;
            cout<<"======================================="<<endl;
            if(ListBook[i]->getAvabilityStat() && ListBook[i]->getVisibilityStat()){
                cout<<setw(10)<<ListBook[i]->getTitle()<<setw(10)<<ListBook[i]->getSerialnumber()<<setw(10)<<ListBook[i]->getAuthor()<<endl;
                check = true;
                Temp = ListBook[i];
            }
        }
    }
    if(check == false) cout<<"Book not found"<<endl;  
    return Temp;
}
Book* Collection::getBookS(string s){
    bool check = false;
    Book* Temp = new Book();
    for(int i =0; i<ListBook.size(); i++){
        if(ListBook[i]->getSerialnumber() == s){
            cout<<setw(10)<<"Title"<<setw(10)<<"Serial"<<setw(10)<<"Author"<<endl;
            cout<<"======================================="<<endl;
            if(ListBook[i]->getAvabilityStat() && ListBook[i]->getVisibilityStat()){
                cout<<setw(10)<<ListBook[i]->getTitle()<<setw(10)<<ListBook[i]->getSerialnumber()<<setw(10)<<ListBook[i]->getAuthor()<<endl;
                check = true;
                Temp = ListBook[i];
            }
        }
    }
    if(check == false) cout<<"Book not found"<<endl;
        
    return Temp;
}

Book* Collection::FindBook(string b){
    bool check = false;
    Book* Temp = new Book();
    for(int i =0; i<ListBook.size(); i++){
        if(ListBook[i]->getTitle() == b || ListBook[i]->getSerialnumber() == b){
            cout<<setw(10)<<"Title"<<setw(10)<<"Serial"<<setw(10)<<"Author"<<endl;
            cout<<"======================================="<<endl;
            cout<<setw(10)<<ListBook[i]->getTitle()<<setw(10)<<ListBook[i]->getSerialnumber()<<setw(10)<<ListBook[i]->getAuthor()<<endl;
            check = true;
            Temp = ListBook[i];
        }
    }
    if(check == false) cout<<"Book not found"<<endl;
    return Temp;
}