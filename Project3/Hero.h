#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <vector>
#include "Warrior.h"
using namespace std;

class Hero {
    
    public:
        Hero();                         // default constructor
        Hero(string,int,int,int,string,string,string,string,int,int, string);    //parameratized constructor
        string getName();
        int getMoney();
        int setHeroMoney();
        int getInfluence();
        int setHeroInfluence();
        int getArmySize();
        string setHeroName(string);
        int setStartRow(int);
        int setStartCol(int);
        
        int getStartRow();
        int getStartCol();
        string getW1();
        string getW2();
        string getW3();
        string getW4();
        string getHasShip();
        
    private:
        string heroName;
        int heroMoney;
        int heroInfluence;
        int army_size;
        int startingLocationRow;
        int startingLocationCol;
        string warrior1;
        string warrior2;
        string warrior3;
        string warrior4;
        vector<Warrior> warrior;
        vector<string> allHeroWarriors;
        string has_ship;
};

#endif
