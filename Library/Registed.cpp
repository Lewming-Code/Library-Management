#pragma once
#include<iostream>
#include"Registed.h"
#include"User.cpp"
#include<string>
using namespace std;

RegistedUser::RegistedUser():User(){}
RegistedUser::RegistedUser(string un, string pw, string p, string fn):User(){
    setUserName(un);
    setPassword(pw);
    setPhone(p);
    setFullName(fn);
}
void RegistedUser::setUserName(string Name){
    userName = Name;
}
string RegistedUser::getUsername(){
    return userName;
}
void RegistedUser::setPassword(string Pass){
    Password = Pass;
}
string RegistedUser::getPassword(){
    return Password;
}
void RegistedUser::setUserCount(){
    userCount++;
}
int RegistedUser::getUserCount(){
    return userCount;
}
void RegistedUser::setPhone(string PHONE){
    phone = PHONE;
}
string RegistedUser::getPhone(){
    return phone;
}
void RegistedUser::setFullName(string fName){
    fullName = fName;
}
string RegistedUser::getFullName(){
    return fullName;
}