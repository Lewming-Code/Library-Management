#pragma once
#include<iostream>
#include<string>
using namespace std;
class Book
{
    private:
    string title;
    string serialnumber; 
    string Author;
    int pageCount;
    int FreePages;
    string category;
    bool visibilityStatus;
    bool avalibilityStatus;
    public:
    Book();
    Book(string, string, string, int, int, string, bool, bool);
    string getTitle();
    string getSerialnumber(); 
    string getAuthor();
    int getNumberOfPages();
    int getFreePages();
    string getCategory();
    void setTitle(string);
    void setSerialnumber(string); 
    void setAuthor(string);
    void setNumberOfPages(int);
    void setFreePages(int);
    void setCategory(string);
    void setVisibilityStat(bool);
    bool getVisibilityStat();
    void setAvabilityStat(bool);
    bool getAvabilityStat();

};