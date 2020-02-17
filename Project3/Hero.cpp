// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 3

#include <iostream>
#include <vector>
#include "Hero.h"
using namespace std;


// default constructor
// set everything to 0 or have it empty
Hero::Hero() {   
    
    heroName = "";
    heroMoney = 0;
    heroInfluence = 0;
    army_size = 0;
    startingLocationRow = 0;
    startingLocationCol = 0;
    has_ship;
    warrior1;
    warrior2;
    warrior3;
    warrior4;
    
}

// parameratized constructor
// set variables to input parameters
Hero::Hero(string name, int money, int influence, int armysize, string w1, string w2, string w3, string w4, int row, int col, string ship) {
    
    heroName = name;
    heroMoney = money;
    heroInfluence = influence;
    army_size = armysize;
    warrior1 = w1;
    warrior2 = w2;
    warrior3 = w3;
    warrior4 = w4;
    startingLocationRow = row;
    startingLocationCol = col;
    has_ship = ship;
    
    // put values into vector?????
    
    
}

// return the name of the hero
string Hero::getName() {
    return heroName;
}
// return the hero's money
int Hero::getMoney() {
    return heroMoney;
}
// set hero's money
/*
int Hero::setHeroMoney(int money) {
    heroMoney = money;
}
*/
// return the hero's influence
int Hero::getInfluence() {
    return heroInfluence;
}
// set hero infulence
/*
int Hero::setHeroInfluence(int influ) {
    heroInfluence = influ;
}
*/
// return the hero's army size
int Hero::getArmySize() {
    return army_size;
}
//set army size
/*
int Hero::setArmySize(int asize) {
    army_size = asize;
}
*/
// set the hero's name
string Hero::setHeroName(string name) {
    heroName = name;
}
/*
int Hero::setStartRow(int row) {
    // if the user decides to create their own hero, use this functiont to
    // set the starting location choice of the user
    startingLocationRow = row;
}
int Hero::setStartCol(int col) {
    // if the user decides to create their own hero, use this functiont to
    // set the starting location choice of the user
    startingLocationCol = col;
}
*/
// return starting location Row
int Hero::getStartRow() { 
    return startingLocationRow;
    
}
int Hero::setStartRow(int point) {
    
    startingLocationRow = point;
}

// return starting location Col
int Hero::getStartCol() {
    return startingLocationCol;
}
int Hero::setStartCol(int point) {
    
    startingLocationCol = point;
}

string Hero::getW1() {
    return warrior1;
}
string Hero::getW2() {
    return warrior2;
}
string Hero::getW3() {
    return warrior3;
}
string Hero::getW4() {
    return warrior4;
}
string Hero::getHasShip() {
    return has_ship;
}


