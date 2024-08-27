#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Menu
{
    private:
    string name;
    string description;
    vector<Menu*> subMenu;
    int action;
    public:
    Menu();
    Menu(string, string, int act);
    ~Menu();
    void setName(string);
    string getName();
    void setDesc(string);
    string getDesc();
    void setAction(int);
    int getAction();
    Menu* getSubMenu(int);
    void displayMenu();
    void AddSubMenu(Menu* m);
    int PromtOption();

};