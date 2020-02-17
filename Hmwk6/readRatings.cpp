// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// hmwk6 - Problem 7

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// ---------------------------SPLIT FUNCTION -----------------------------

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

//---------------------------READING RATINGS FUNCTION------------------------

/*
* Algorithm: create a function that loads user ratings
* 1. create an int function that accepts six input arguments
* 2. declare file to be opened, and open the file
* 3. check if numUsers is equal to maxRows, if so return -2
* 4. check if the file is open
* 5. declare string s and rating_array
* 6. create a while loop that reads each line and puts them in the s string
* 7. check if the char is a space, if so then skip the rest and loop again
* 8. if numUsers is equal to maxRows then break from loop
* 9. call the split function and create a for loop that stores the ratings into the rating array
* 10. after the for loop, store the usernames into the users array
* 11. close the file and return numUsers
* Input parameters: string fileName, string users[], int ratings[100][50], int numUsers, int maxRows, int maxColumns
* Output: none
* Returns: numUsers
*/


int readRatings(string fileName, string users[], int ratings[100][50], int numUsers, int maxRows, int maxColumns)  {
    
    // declare variable and open file
    ifstream fp;
    fp.open(fileName);
    
    // if numUsers is equal to max rows then return -2
    if (numUsers == maxRows) {
        return -2;
    }
    
    // check if file is open
    if (fp.is_open()) {
        
        // declare string and array
        string s;
        string rating_array[maxColumns + 1];
        
        // while function that reads the file
        while (getline(fp, s)) {
            //Check Empties
            if (s == "") continue;
            
            //check if it has reached maxRows
            if(numUsers == maxRows) {
                    break;
                }
            // use split function
            split(s, ',', rating_array, maxColumns + 1);
            
            
            // for loop for ratings
            int b = 0;
            for (int j = 1; j < split(s, ',', rating_array, maxColumns + 1) ; j++) {
                
                
                // declare new string for rating values
                string r = rating_array[j];
                // stoi 
                int rating_int = stoi(r);
                // store into ratings[numUsers][j]
                ratings[numUsers][b] = rating_int;
                // reset string r
                r = "";
                b++;
                
            }
         
            
            // declare user variable to store 0th column (names) of rating_array
            string user = rating_array[0];
            // store into users[numUsers] array
            users[numUsers] = user;
            // increment i
            numUsers++;
            
        }
        
        // close file
        fp.close();
        // return numUsers;
        return numUsers;
        
    }
    // else statement if file isn't open
    else {
        return -1;
    }
        
    
}

// -----------------------------------------------------

int main() {
    
    
    string users[10] = {};
    int ratings[10][50] = {{0}};
    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    readRatings("ratings.txt", users, ratings, numUsers, maxRows, maxColumns);
    
    // test 1
    // expected output
    // lists users
    for (int i = 0; i < maxRows; i++) {
        cout << users[i] << endl;
    }
    
    cout << endl;
    
    // test 2
    // expected output
    // lists ratings
    for (int j= 0; j < maxRows; j++) {
        cout << ratings[j] << endl;
    }

    
}