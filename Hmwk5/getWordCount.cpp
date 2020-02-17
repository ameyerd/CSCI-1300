// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 5 - Problem 2

#include <iostream>
#include <string>
using namespace std;


/*
* Algorithm: takes an english sentence and returns the # of words in the sentence
* 1. define index i and count variable and set it equal to 0
* 2. check if s is an empty string, if so return 0
* 3. create a while loop checking if i is less than string length
* 4. create an if statement checking if the current index of i is equal to a space (32)
* 5. if so, increment count variable and i variable
* Input parameters: string s
* Output: none
* Returns: count
*/

int getWordCount(string s) {
    int i = 0;
    int count = 1;
    
    if (s == "") { // if s is an empty string return 0
        return 0;
    }
    while (i < s.length()) {
        if (s[i] == 32) { // check if s[i] is a space
            count++;
        }
        i++;
    }
    return count;
}


int main() {
    // test 1
    // expected output
    // 9
    cout << getWordCount("The rate the cat the dog bit chased escaped") << endl;
    
    // test 2
    // expected output
    // 0
    cout << getWordCount("");
    
}