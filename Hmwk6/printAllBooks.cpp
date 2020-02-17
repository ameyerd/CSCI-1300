// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// hmwk6 - Problem 6

#include <iostream>
#include <fstream>
#include <string>
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

int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size) {
    
    ifstream fp;
    fp.open(fileName);
    
    if (numBookStored == size) {
        return -2;
    }
    
    
    if (fp.is_open()) {
        string temp_array[size];
        string s = "";
        int i = numBookStored;
        while (getline(fp, s)) { // read line
            if (s.length() == 0) continue;
            
            split(s, ',', temp_array, size); // use split function
            string author = temp_array[0]; // first column is the author
            string title = temp_array[1]; // second column is the title of book
            
            authors[i] = author; // store into authors array
            titles[i] = title; // store into title array
            
            i++;
            
            if (i == size) {
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


/*
* Algorithm: create a function to display the contents of library
* 1. create a void function that accepts 3 arguments
* 2. check if the numBooks is less than or equal to 0, if so output no books stored
* 3. if numBooks stored is greater than 0 then create a while loop 
*     and output the list of books
* Input parameters: string titles[], string authors[], int numBooks
* Output: "No books are stored" or "Here's a list of books (lists books)""
* Returns: none
*/

void printAllBooks(string titles[], string authors[], int numBooks) {
    
    if (numBooks <= 0) { 
        cout << "No books are stored" << endl;
    }
    else {
        int i = 0;
        cout << "Here is a list of books" << endl;
        while(i < numBooks) {
            cout << titles[i] << " by " << authors[i] << endl;
            i++;
        }
    }
}

int main() {

    
    // test 1
    // expected output
    /* Here is a list of books
    The Hitchhiker's Guide To The Galaxy by Douglas Adams
    Watership Down by Richard Adams
    The Five People You Meet in Heaven by Mitch Albom
    Speak by Laurie Halse Anderson
    I Know Why the Caged Bird Sings by Maya Angelou
    Thirteen Reasons Why by Jay Asher
    Foundation Series by Isaac Asimov
    The Sisterhood of the Travelling Pants by Ann Brashares
    A Great and Terrible Beauty by Libba Bray
    The Da Vinci Code by Dan Brown
    */
    string titles[10] = {};
    string authors[10] = {};
    readBooks("books.txt", titles, authors, 0 , 10);
    printAllBooks(titles, authors, 10);
    
    cout << endl;
    
    // test 2
    // expected output
    // No books are stored
    readBooks("books.txt", titles, authors, 0, 0);
    printAllBooks(titles, authors, 0);
    
    
}