// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 7

#include <iostream>
#include <fstream>
#include "User.h"
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

// read ratings
int readRatings(string fileName, User users[], int numUsersStored, int usersArrSize, int maxCol)  {
    
    // declare variable and open file
    ifstream fp;
    fp.open(fileName.c_str());
    
    // if numUsers is equal to max rows then return -2
    if (numUsersStored == usersArrSize) {
        return -2;
    }
    
    // check if file is open
    if (fp.is_open()) {
        
        // declare string and array
        string s;
        string rating_array[maxCol + 1];
        
        // while function that reads the file
        while (getline(fp, s)) {
            //Check Empties
            if (s == "") continue;
            
            //check if it has reached maxRows
            if(numUsersStored == usersArrSize) {
                    break;
                }
            // use split function
            split(s, ',', rating_array, maxCol + 1);
            
            
            // for loop for ratings
            int b = 0;
            for (int j = 1; j < split(s, ',', rating_array, maxCol + 1) ; j++) {
                
                
                // declare new string for rating values
                string r = rating_array[j];
                // stoi 
                int rating_int = stoi(r);
                // store into ratings[numUsers][j]
                users[numUsersStored].setRatingAt(b, rating_int); // if not j then b
                // reset string r
                r = "";
                b++;
                
            }
         
            
            // declare user variable to store 0th column (names) of rating_array
            string user = rating_array[0];
            // store into users[numUsers] array
            users[numUsersStored].setUsername(user);
            // increment i
            numUsersStored++;
            
        }
        
        // close file
        fp.close();
        // return numUsers;
        return numUsersStored;
        
    }
    // else statement if file isn't open
    else {
        return -1;
    }
        
    
}

int main() {
    // in bash:  g++ readRatingsDriver.cpp User.cpp -std=c++11
    
    // test 1
    // expected output
    // 4
    User users[10];
    int numUsersStored = 0;
    int usersArrSize = 10;
    cout << readRatings("ratings.txt", users, numUsersStored,usersArrSize, 50) << endl;
    
    // testing data member username
    cout<<users[0].getUsername()<<endl;
    cout<<users[1].getUsername()<<endl;
    // expected output 
    // Ninja
    // Myth
    
    // testing data member ratings
    cout<<users[0].getRatingAt(0)<<endl;
    cout<<users[0].getRatingAt(1)<<endl;
    // expected output
    // 0
    // 1
    
    cout << endl;
    
    // test 2
    // expected output
    // 2
    
    User user[2];
    user[0].setUsername("ritchie");
    user[0].setRatingAt(0,0);
    user[0].setRatingAt(1,1);
    user[0].setRatingAt(2,2);
    int numUsers = 1;
    int usersArrSizes = 2;
    cout << readRatings("ratings.txt", user, numUsers,usersArrSizes, 50) << endl;
    
    // testing data member username
    cout<<users[0].getUsername()<<endl;
    cout<<users[1].getUsername()<<endl;
    // Expected Output
    // ritchie
    // stroustrup
    
    // testing data member ratings
    cout<<users[0].getRatingAt(0)<<endl;
    cout<<users[0].getRatingAt(1)<<endl;
    cout<<users[0].getRatingAt(2)<<endl;
    // expected output
    // 0
    // 1
    // 2
    
    
    
}
