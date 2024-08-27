#pragma once
#include<iostream>
#include<string>
#include"Book.h"
using namespace std;

Book::Book(){
    title = "";
    serialnumber = ""; 
    Author = "";
    pageCount = 0;
    FreePages = 0;
    category = "";
    visibilityStatus = false;
    avalibilityStatus = false;
}
Book::Book(string t, string s, string a, int p, int f, string c, bool vs, bool as){
    title = t;
    serialnumber = s; 
    Author = a;
    pageCount = p;
    FreePages = f;
    category = c;
    visibilityStatus = vs;
    avalibilityStatus = as;
}
string Book::getTitle(){
    return title;
}
string Book::getSerialnumber(){
    return serialnumber;
}
string Book::getAuthor(){
    return Author;
}
int Book::getNumberOfPages(){
    return pageCount;
}
int Book::getFreePages(){
    return FreePages;
}
string Book::getCategory(){
    return category;
}
void Book::setTitle(string t){
    title = t;
}
void Book::setSerialnumber(string s){
    serialnumber = s;
}
void Book::setAuthor(string a){
    Author = a;
}
void Book::setNumberOfPages(int p){
    pageCount = p;
}
void Book::setFreePages(int f){
    FreePages = f;
}
void Book::setCategory(string c){
    category = c;
}
void Book::setVisibilityStat(bool vs){
    visibilityStatus = vs;
}
bool Book::getVisibilityStat(){
    return visibilityStatus;
}
void Book::setAvabilityStat(bool as){
    avalibilityStatus = as;
}
bool Book::getAvabilityStat(){
    return avalibilityStatus;
}