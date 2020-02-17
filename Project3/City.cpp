// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 3

#include <iostream>
#include "City.h"
using namespace std;


// default constructor
// set everything to 0 or have it empty
City::City() {
    
    cityLetter = "";
    cityName = "";
    cityMoney = 0;
    cityArmy_size = 0;
    cityPoints = 0;
    
}
// parameratized constructor
// set variables to input parameters
City::City(string letter, string name, int money, int armysize, int points) {
    
    cityLetter = letter;
    cityName = name;
    cityMoney = money;
    cityArmy_size = armysize;
    cityPoints = points;
    
}
// return assigned letter (A-Z) of specific city
string City::getCityLetter() {
    return cityLetter;
}
// return city name
string City::getCityName() {
    return cityName;
}
// return city's money
int City::getCityMoney() {
    return cityMoney;
}
// return city's army size
int City::getCityArmySize() {
    return cityArmy_size;
}
// return city's points
int City::getCityPoints() {
    return cityPoints;
}