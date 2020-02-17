// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 2 - Problem 0

#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include "User.h"
#include "Book.h"
using namespace std;

// Library class

class Library {
    public:
        Library();      // default constructor
        int getSizeBook();
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        int readBooks(string);
        void printAllBooks();
        int readRatings(string);
        int getRating(string,string);
        int getCountReadBooks(string);
        void viewRatings(string);
        double calcAvgRating(string);
        int addUser(string);
        int checkOutBook(string,string,int);
        void getRecommendations(string);
        int ssd(int,int);
    private:
        int const static sizeBook = 50;
        int const static sizeUser = 100;
        Book books[50];
        User users[100];
        int numBooks;
        int numUsers;
    
  
};

#endif