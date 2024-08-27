#pragma once
#include<iostream>
#include"Registed.h"
#include"Collection.h"
#include<string>
#include<vector>
using namespace std;
static vector<Collection*> ListCollection;
class Admin:public RegistedUser
{
    private:
    vector<Collection*> ListCollection;
    public:
    Admin();
    Admin(string, string, string, string);
    ~Admin();
    Admin* CreateAdmin();
    Book* CreateBook();
    void showBook(Book*);
    void hideBook(Book*);
    void editBook(Book*);
    void deleteBook(Book*);
    int getCollectionListSize();
    void AddCollection(Collection*);
    void RemoveCollection(string);
    Collection* CreateCollection(int, string);
    


};