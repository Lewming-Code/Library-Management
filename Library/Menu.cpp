#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Menu.h"
using namespace std;

Menu:: Menu(){
    name = "Default menu";
    description = "Default description";
    action = -1;
    subMenu.clear();
}
Menu::Menu(string n, string desc, int act = -1){
    name = n;
    description = desc;
    action = act;
    subMenu.clear();
}
Menu::~Menu(){
    if(!subMenu.empty()){
        for(int i =0; i<subMenu.size(); i++){
            if(subMenu[i])
            delete subMenu[i];
        }
    }
    subMenu.clear();
}
void Menu::setName(string n ){
    name = n;
}
string Menu::getName(){
    return name;
}
void Menu::setDesc(string desc){
    description = desc;
}
string Menu::getDesc(){
    return description;
}
void Menu::setAction(int act){
    action = act;
}
int Menu::getAction(){
    return action;
}
void Menu::displayMenu(){
    cout<<"====="<<this->name<<"===== \n";
    cout<<this->description<<endl;
    for(int i =0; i<subMenu.size(); i++){
        cout<<i+1<<". "<<subMenu[i]->getName()<<endl;
    }
}
Menu* Menu::getSubMenu(int i){
    if(i>0 && i<=subMenu.size()){
        i--;
        return subMenu[i];
    }
    else
    return nullptr;
}
void Menu::AddSubMenu(Menu* m){
    subMenu.push_back(m);
}
int Menu::PromtOption(){
    while(true){
        int option;
        cout<<"Pick an option: ";
        cin>>option;
        try{
            if(cin.fail())
                throw "Invalid input";
            else if(option<1 || option >subMenu.size())
                throw "Out of menu range";
            else 
                return option;
        }
        catch(const char* error){
            cin.ignore();
            cin.clear();
            cout<<"Error: "<<error<<endl;
        }
    }
}