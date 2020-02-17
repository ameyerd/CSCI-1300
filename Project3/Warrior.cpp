// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 3

#include <iostream>
#include "Warrior.h"
using namespace std;


// default constructor
// set everything to 0 or have it empty
Warrior::Warrior() {
    
    warriorName = "";
    warriorStrength = 0;
    warriorLoyalty = 0;
    warriorMorale = 0;
    warriorFree;
    warriorShip;
    has_dragonglass;
    startWRow;
    startWCol;
    
}
// parameratized constructor
// set variables to input parameters
Warrior::Warrior(string name, int strength, int loyalty, int morale, string is_free, string ship, string dragonglass) {
    
    warriorName = name;
    warriorStrength = strength;
    warriorLoyalty = loyalty;
    warriorMorale = morale;
    warriorFree = is_free;
    warriorShip = ship;
    has_dragonglass = dragonglass;
    
}

// return warrior name
string Warrior::getWName() {
    return warriorName;
}
// return warrior strength
int Warrior::getWStrength() {
    return warriorStrength;
}
int Warrior::setWStrength(int point) {
    
    warriorStrength = point;
    
} 
// return warrior loyalty
int Warrior::getWLoyalty() {
    return warriorLoyalty;
}
// return warrior morale
int Warrior::getWMorale() {
    return warriorMorale;
}
int Warrior::setWMorale(int point) {
    
    warriorMorale = point;
    
}
// return if warrior is free
string Warrior::getWFree() {
    return warriorFree;
}
// return if warrior has ship
string Warrior::getWShip() {
    return warriorShip;
}
// return is warrior has dragonglass
string Warrior::getHasDragonglass() {
    return has_dragonglass;
}
int Warrior::setStartWRow(int point) {
    
    startWRow = point;
}
int Warrior::setStartWCol(int point) {
    
    startWCol = point;
}
int Warrior::getStartWRow() {
    return startWRow;
    
}
int Warrior::getStartWCol() {
    return startWCol;
    
}