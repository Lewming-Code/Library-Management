#pragma once
#include<iostream>
#include"User.h"
#include<string>
using namespace std;

static int userCount = 0;

class RegistedUser:public User
{
    private:
    string userName;
    string Password;
    string phone;
    string fullName;
    public:
    RegistedUser();
    RegistedUser(string, string, string, string);
    void setUserName(string);
    string getUsername();
    void setPassword(string);
    string getPassword();
    void setUserCount();
    int getUserCount();
    void setPhone(string);
    string getPhone();
    void setFullName(string);
    string getFullName();
};