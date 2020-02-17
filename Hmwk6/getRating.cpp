// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// hmwk6 - Problem 8

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

/*
* Algorithm: create a funcation to search for a particular user's rating for a particular book title
* 1. check if the first letter of the name is capital if so leave it, if not then make it capital
* 2. do the same for book titles, after each space make the next char capital
* 3. check if numBooks is 0 if so return -3
* 4. create a for loop that stores the username and title into the respective arrays
* 5. then return the ratings
* 6. if there is zero usernames in the array return -3
* 7. if the loop reaches the end of the usernames and doesn't find the particular username return -3
* Input parameters: string username, string title, string users[], string titles[], int ratings[][50], int numUsers, int numBooks
* Output: none
* Returns: rating
*/

int getRating(string username, string title, string users[], string titles[], int ratings[][50], int numUsers, int numBooks) {
    
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
            
        if (users[i] == username) {
            users[i] = username;
            user_count++;
            
            int j = 0;
            while ( j < numBooks) {
                if(titles[j] != title) { 
                    j++;
                }
                else {
                    if (titles[j] == title) {
                        titles[j] = title;
                        break;
                    }
                    
                }
            if (j == numBooks) {
                return -3;
            }
                
                
            }
                
                 int rating = ratings[i][j];
                 return rating;
            }
            
        else {
            if (users[i] != username) {
                // do nothing
            }
            if (users[i] != username && i == numUsers - 1) {
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
    string users[2] = {"User1", "User2"};
    string titles[3] = {"Title1", "Title2", "Title3"};
    int ratings[2][50] = {{1,4,2},{0,5,3}};
    
    // test 1
    // expected output
    // 4
    cout << getRating("User1", "Title2", users, titles, ratings, 2, 3);
    
    cout << endl;
    // test 2
    // expected output
    // 3
    cout << getRating("User2", "Title3", users, titles, ratings, 2, 3);
    
}