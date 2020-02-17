// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 3

#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    
    // test 1
    // expected output
    // The Iliad by Homer
    Book book;
    book.setTitle("The Iliad");
    book.setAuthor("Homer");
    cout << book.getTitle() << " by " << book.getAuthor() << endl;
    
    // test 2
    // expected output
    // Cat's Cradle by Kurt Vonnegut
    Book book1("Cat's Cradle", "Kurt Vonnegut");
    cout << book1.getTitle() << " by " << book1.getAuthor() << endl;
    
}