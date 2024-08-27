#pragma once
#include<iostream>
#include"User.h"
#include<string>
using namespace std;

User::User(){
    int i = rand()%999999+100000;
    setID(i);
}
User::User(int ID){
    setID(ID);
}
void User::setID(int ID){
    id = ID;
}
int User::getID(){
    return id;
}
void User::read(){
    cout<<"User is reading";
}
void User::setAccessLevel(int Type){
    AccessbilityLevel = Type;
}
int User::getAccessLevel(){
    return AccessbilityLevel;
}