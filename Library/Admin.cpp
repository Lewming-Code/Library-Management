#pragma once
#include<iostream>
#include"Admin.h"
#include"Registed.cpp"
#include"Collection.cpp"
#include<string>
using namespace std;

Admin::Admin(){
}
Admin::Admin(string un, string pw, string p, string fn):RegistedUser(un, pw, p, fn){
    setAccessLevel(admin);
}
Admin::~Admin(){
    if(!ListCollection.empty()){
        for(int i =0; i<ListCollection.size(); i++){
            if(ListCollection[i])
            delete ListCollection[i];
        }
    }
}
Admin* Admin::CreateAdmin(){
    cout<<"Creating new Admin"<<endl;;
    string un, pw, p, fn;
    cout<<"Enter your user name: "; cin>>un;
    cout<<"Enter your Password: "; cin>>pw;
    cout<<"Enter your phone number: "; cin>>p;
    cout<<"Enter your full name: "; cin>>fn;
    Admin* newA = new Admin(un, pw, p, fn); 
    cout<<"Register success"<<endl;
    return newA;
}
Book* Admin::CreateBook(){
    cout<<"Creating new book: "<<endl;
    string t, s, a;
    int p, f;
    string c;
    cout<<"Enter Book Title: "; cin>>t;
    cout<<"Enter Book Serial: "; cin>>s;
    cout<<"Enter Book Author: "; cin>>a;
    cout<<"Enter Number of Book Pages: "; cin>>p;
    cout<<"Enter Number of free Pages: "; cin>>f;
    Book* newB = new Book(t, s, a, p, f, c, true, true); 
    cout<<"Creating success"<<endl;
    return newB;
}
void Admin::showBook(Book* b){
    if(!b->getVisibilityStat()){
        b->setVisibilityStat(true);
        cout<<"Book showed"<<endl;
    }
    else cout<<"Book is not hidden"<<endl;
}
void Admin::hideBook(Book* b){
    if(b->getVisibilityStat()){
        b->setVisibilityStat(false);
        cout<<"Book Hidden"<<endl;
    }
    else cout<<"Book is currently hidden"<<endl;
}
void Admin::editBook(Book* b){
    cout<<"Admin is editing book";
    string t, s, a;
    int p, f;
    string c;
    cout<<"Enter Book new Title: "; cin>>t; b->setTitle(t);
    cout<<"Enter Book new Serial: "; cin>>s; b->setSerialnumber(s);
    cout<<"Enter Book new Author: "; cin>>a; b->setAuthor(a);
    cout<<"Enter new Number of Book Pages: "; cin>>p; b->setNumberOfPages(p);
    cout<<"Enter new Number of free Pages: "; cin>>f; b->setFreePages(f);
    cout<<"Edditing success"<<endl;
}
void Admin::deleteBook(Book* b){
    if(b->getTitle() != ""){
        string choice;
        cout<<"Do you want to delete this book?(Y/N) ";
        cin>>choice;
        if(choice == "y" || choice == "Y"){
            delete b;
            cout<<"Delete Book Success"<<endl;
        }
        else cout<<"Delete Book fail"<<endl;
    }
    else cout<<"No book to delete"<<endl;
}
int Admin::getCollectionListSize(){
    return ListCollection.size();
}
void Admin::AddCollection(Collection* cl){
    ListCollection.push_back(cl);
}
void Admin::RemoveCollection(string cn){
    for(int i=0; i<ListCollection.size(); i++){
        if(ListCollection[i]->getCollectionName() == cn)
        ListCollection[i]->~Collection();
    }
}
Collection* Admin::CreateCollection(int ID, string CName){
    Collection* Temp = new Collection(ID, CName);
    return Temp;
}