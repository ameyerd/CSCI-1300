// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 6

#include <iostream>
#include <fstream>
#include "Book.h"
using namespace std;

// split function
int split(string str, char c, string array[], int num) {
    
    if (str.length() == 0) {
        return 0;
    }
    int a = 0;
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) // check if current char is equal to delimiter
        {
        	if (word.length() == 0) continue; // ignore rest
        	array[a] = word; // store into array
        	a++;
            j++;
            word = ""; // reset word
        } else {
            word = word + str[i]; //add char into string
        }
    }
    return j ;
    
}

// read books

int readBooks(string fileName, Book books[], int numBookStored, int booksArrSize) {
    
    ifstream fp;
    fp.open(fileName.c_str());
    
    if (numBookStored == booksArrSize) {
        return -2;
    }
    
    
    if (fp.is_open()) {
        string temp_array[booksArrSize];
        string s = "";
        int i = numBookStored;
        while (getline(fp, s)) { // read line
            if (s.length() == 0) continue;
            
            split(s, ',', temp_array, booksArrSize); // use split function
            string author = temp_array[0]; // first column is the author
            string title = temp_array[1]; // second column is the title of book
            
            books[i].setAuthor(author); // store into authors array
            books[i].setTitle(title); // store into title array
            
            i++;
            
            if (i == booksArrSize) {
                break;
            }
            
                
        }
        
        
        fp.close();
        return i;
        
        }
        else {
        return -1;
        
    }
    
}


// print all books

void printAllBooks(Book books[], int numBooks) {
    
    if (numBooks <= 0) { 
        cout << "No books are stored" << endl;
    }
    else {
        int i = 0;
        cout << "Here is a list of books" << endl;
        while(i < numBooks) {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
            i++;
        }
    }
}


int main() {
    // in bash:  g++ printAllBooksDriver.cpp Book.cpp
    
    // test 1
    // expected output
    // Here is a list of books
    // Calculus1 by Gottfried Leibniz
    Book books[1];
    books[0].setTitle("Calculus1");
    books[0].setAuthor("Gottfried Leibniz");
    printAllBooks(books, 1);
    
    
    cout << endl;
    
    // test 2
    // expected output
    // Here is a list of books
    // Calculus by Gottfried Leibniz
    // Algebra by Alan Turing
    // Physics by Isaac Newton

    Book book[3];
    book[0].setTitle("Calculus");
    book[0].setAuthor("Gottfried Leibniz");
    
    book[1].setTitle("Algebra");
    book[1].setAuthor("Alan Turing");
    
    book[2].setTitle("Physics");
    book[2].setAuthor("Isaac Newton");
    
    printAllBooks(book, 3);
}

