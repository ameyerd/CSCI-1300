// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 2 - Probem # 0

#include <iostream>
#include "User.h"
using namespace std;
 
User::User() {
    username = "";
    numRatings = 0;
    size = 50;
    for (int i = 0; i < 50; i++) {
        ratings[i] = 0;
    }
}
User::User(string username, int rating[], int numRatings) {
    if (numRatings <= 50) {
        this->username = username;
        
        for (int i = 0; i < numRatings; i++) {
            ratings[i] = rating[i];
        }
        for (int i = numRatings; i < 50; i++) {
            ratings[i] = 0;
        }
        this->numRatings = numRatings;
    }
    
}
void User::setUsername(string name) {
    username = name;
}
string User::getUsername() {
    return username;
}
bool User::setRatingAt(int index, int value) {
    if ((value <= 5 && value >= 0) && (index < 50 && index >= 0)) {
        ratings[index] = value;
        return true;
    }
    else{
        return false;
    }
    
}
int User::getRatingAt(int index) {
    if (index >= 50) {
        return -1;
    }
    else {
        return ratings[index];
    }
}
void User::setNumRatings(int numRatings) {
    this->numRatings = numRatings;
}
int User::getNumRatings() {
    return numRatings;
}
int User::getSize() {
    return size;
}
