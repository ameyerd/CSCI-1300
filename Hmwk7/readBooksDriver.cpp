// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 5

#include <iostream>
#include <fstream>
#include "Book.h"
#include "User.h"
using namespace std;

//split function
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
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
        	array[a] = word; 
        	a++;
            j++;
            word = "";
        } else {
            word = word + str[i];
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



int main() {
    // in bash: g++ readBooksDriver.cpp Book.cpp User.cpp
    
    // test 1
    // expected output
    // 2
    Book books[10] = {};
    cout << readBooks("fileName.txt",books, 0, 10) << endl;
    
    // test 2
    // expected output
    // 3
    Book book[10];
    book[0].setAuthor("Author Z");
    book[0].setTitle("Book N");
    cout << readBooks("fileName.txt",book, 1, 10) << endl;
}