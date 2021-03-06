// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 2 - Problem # 0
#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

// Book class definition
class Book {
    public:
        Book();  // default constructor
        Book(string, string);  // parameterized constructor
        string getTitle();
        void setTitle(string);
        string getAuthor();
        void setAuthor(string);
    private: // cannot be accessed by outside
        string title;
        string author;

};

#endif
