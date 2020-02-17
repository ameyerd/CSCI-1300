// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 8

#include <iostream>
#include <fstream>
#include "User.h"
#include "Book.h"
using namespace std;

int getRating(string username, string title, User users[], Book titles[], int numUsers, int numBooks) {
    
    // first char is uppercase, rest is lowercase
    
    // username
    if (isupper(username[0])) { // check if first char is upper case
        for (int i = 1; i < username.length(); i++) {
            if (islower(username[i])) { // check if the next chars are lower case
                // do nothing
            }
            else {
                // to lower
                username[i] = tolower(username[i]); // make char lowercase
            }
        }
    }
    else { // if first char is not uppercase
        if(islower(username[0])) {
            // change to upper case
            username[0] = toupper(username[0]);
        }
        for (int i = 1; i < username.length(); i++) {
            if (islower(username[i])) { // check if the next chars are lower case
                // do nothing
            }
            else {
                // to lower
                username[i] = tolower(username[i]); // make char lowercase
            }
        }
        
    }
    
    //cout << username << endl;
    
    // after every space char is capital~!!
    // title
    if (isupper(title[0])) { // check if first letter of 
        for (int j = 1; j < title.length(); j++) {
            if (islower(title[j])) { // check if next chars are lowercase
                // do nothing
            }
            else {
                title[j] = tolower(title[j]);
            }
        }
    }
    else { // if first char of title is not capital
        if (islower(title[0])) {
            title[0] = toupper(title[0]);
        }
        for (int j = 1; j < title.length(); j++) {
            if (islower(title[j])) { // check if next chars are lowercase
                    // do nothing
                }
            else {
                title[j] = tolower(title[j]);
            }
        }
        
    }
    // check if there is spaces
    for (int s = 1; s < title.length(); s++) {
        if (title[s] == 32) {
            title[s+1] = toupper(title[s+1]); // if space the next char is Uppercase
        }
    }
    
    //cout << title;
    
  
    // -----------------------------------
    // if numBooks = 0 return -3;
    if (numBooks == 0) {
        return -3;
    }
    
    // if there are 0 usernames in the array return -3
    int user_count = 0;
    
    for (int i = 0; i < numUsers; i++) {
            
        if (users[i].getUsername() == username) { // here
            users[i].setUsername(username); // here
            user_count++;
            
            int j = 0;
            while ( j < numBooks) {
                if(titles[j].getTitle() != title) {  // here
                    j++;
                }
                else {
                    if (titles[j].getTitle() == title) { // here
                        titles[j].setTitle(title);  // here
                        break;
                    }
                    
                }
            if (j == numBooks) {
                return -3;
            }
                
                
            }
            
            // getRating at index i
            int rating = users[i].getRatingAt(j); // here
            return rating;  
            }
            
        else {
            if (users[i].getUsername() != username) {  // here
                // do nothing
            }
            if (users[i].getUsername() != username && i == numUsers - 1) {  // here
                return -3;
            }
            
        }
    
    }
    
    if (user_count == 0) { // if zero usernames in user array
        return -3;
    }
    
    //------------------------------------------------------------
        
    
} // end of function


int main() {
    // in bash:  g++ getRatingDriver.cpp Book.cpp User.cpp
    
    
    //Creating 3 books
    Book books[3];
    //Setting book title and author for book 1
    books[0].setTitle("Title1");
    books[0].setAuthor("Author1");
    //Setting book title and author for book 2
    books[1].setTitle("Title2");
    books[1].setAuthor("Author2");
    //Setting book title and author for book 3
    books[2].setTitle("Title3");
    books[2].setAuthor("Author3");
    
    //Creating 2 users
    User users[2];
    //Setting username and ratings for User1
    users[0].setUsername("User1");
    users[0].setNumRatings(3);
    users[0].setRatingAt(0,1);
    users[0].setRatingAt(1,4);
    users[0].setRatingAt(2,2);
    //Setting username and ratings for User2
    users[1].setUsername("User2");
    users[1].setNumRatings(3);
    users[1].setRatingAt(0,0);
    users[1].setRatingAt(1,5);
    users[1].setRatingAt(2,3);
    
    
    // test 1
    // expected output
    // 4
    cout << getRating("User1", "Title2", users, books, 2, 3) << endl;
    
    // test 2 
    // expected output
    //  -3
    cout << getRating("User4", "Title1", users, books, 2, 3) << endl;
    
    
}