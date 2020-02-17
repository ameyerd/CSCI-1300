// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 2 - Problem # 0

#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

// User class defintion
class User {
    public:
        User();  // default constructor
        User(string, int [], int);  // parameterized constructor
        string getUsername();
        void setUsername(string);
        int getRatingAt(int);
        bool setRatingAt(int, int);
        int getNumRatings();
        void setNumRatings(int);
        int getSize();
    private: // cannot be accessed by outside
        string username;
        int size;
        int ratings[50];
        int numRatings;
    
};

#endif