#pragma once
#include<iostream>
#include"User.h"
#include"Member.h"
#include<string>
using namespace std;

class Guest:public User
{
    private:
    public:
    Guest();
    virtual void read();
    Member* Register();
};