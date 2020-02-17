#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
using namespace std;


 class Warrior {
     public:
        Warrior();     // default constructor
        Warrior(string,int,int,int,string,string,string);   // parameratized constructor
        string getWName();
        int getWStrength();
        int setWStrength(int);
        int getWLoyalty();
        int getWMorale();
        int setWMorale(int);
        string getWFree();
        string getWShip();
        string getHasDragonglass();
        
        int setStartWRow(int);
        int setStartWCol(int);
        int getStartWRow();
        int getStartWCol();
     private:
        string warriorName;
        int warriorStrength;
        int warriorLoyalty;
        int warriorMorale;
        string warriorFree;
        string warriorShip;
        string has_dragonglass;
        int startWRow;
        int startWCol;
 };
 
#endif