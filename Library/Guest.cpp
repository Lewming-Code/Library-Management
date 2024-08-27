#pragma once
#include<iostream>
#include"Guest.h"
#include"User.cpp"
#include"Member.cpp"
#include<string>
using namespace std;

Guest::Guest():User(){
    setAccessLevel(guest);
}
void Guest::read(){
    cout<<"Guest is reading"<<endl;
}
Member* Guest::Register(){
    cout<<"Register a new Account."<<endl;
    string un, pw, p, fn;
    int sy, ey;
    cout<<"Enter your user name: "; cin>>un;
    cout<<"Enter your Password: "; cin>>pw;
    cout<<"Enter your phone number: "; cin>>p;
    cout<<"Enter your full name: "; cin>>fn;
    cout<<"What year do you want to start your subscription: "; cin>>sy;
    cout<<"What year do you want to end your subscription: "; cin>>ey;
    Member* NewM = new Member(un, pw, p, fn, sy, ey);
    cout<<"Register success"<<endl;
    return NewM;
}