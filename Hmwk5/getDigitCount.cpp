// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 5 - Problem 1

#include <iostream>
#include <string>
using namespace std;


/*
* Algorithm: count the number of digits in a string
* 1. define index i and count variable and set it equal to 0
* 2. create a while loop checking if i is less than string length
* 3. create an if statement checking if the string is within 0-9
* 4. if the string is within 0-9 add 1 to counter and increment i
* Input parameters: string s
* Output: none
* Returns: count
*/

int getDigitCount(string s) {
    int i = 0;
    int count = 0;
    
    while (i < s.length()) {
        if (s[i] <= 57 && s[i] >= 48) { //if s[i] is between 0-9
        count++;
    }
        i++;
    }
    return count;
}


int main() {
    // test 1
    // expected output
    // 2
    cout << getDigitCount("h1hldskf3") << endl;
    
    // test 2
    // expected output
    // 4
    cout << getDigitCount("123ioo0");
}