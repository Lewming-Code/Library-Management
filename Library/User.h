#pragma once
#include<iostream>
#include<string>
using namespace std;

enum AccessbilityType {guest, member, admin};
class User
{
    private:
    int id;
    int AccessbilityLevel;
    public:
    User();
    User(int);
    virtual void read();
    void setID(int);
    int getID();
    void setAccessLevel(int);
    int getAccessLevel();
};