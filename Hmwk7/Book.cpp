// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 3

#include <iostream>
#include "Book.h"
using namespace std;

Book::Book() {
    
}
Book::Book(string title, string author) {
    this->title = title;
    this->author = author;
}
void Book::setTitle(string title) {
    this->title = title;
}
string Book::getTitle() {
    return title;
}
void  Book::setAuthor(string author) {
    this->author = author;
}
string Book::getAuthor() {
    return author;
}
