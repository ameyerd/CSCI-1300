// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 4

include <iostream>
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
User::User(string username, int ratings[], int numRatings) {
    if (numRatings <= 50) {
        this->username = username;
        this->numRatings = numRatings;
        for (int i = 0; i < 50; i++) {
            this->ratings[i] = ratings[i];
        }
        
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
