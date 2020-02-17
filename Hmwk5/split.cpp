// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 5 - Problem 3

#include <iostream>
#include <string>
using namespace std;


/*
* Algorithm: split the input into smaller substrings, separated by the deimeter
* 1. define index i and count variable and set it equal to 0
* 2. check if s is an empty string, if so return 0
* 3. check if the first character of s is equal to the delimiter, if so add 1 to i
* 4. create a while loop checking if i is less than string length
* 5. if the index of s is not equal to delimiter, output the character
* 6. if the index of s is equal to delimiter then also check if the next char is
*    also equal to the delimiter, if so increment i, then output a space and increment counter and i
* Input parameters: string s, char c
* Output: substring
* Returns: counter
*/


int split(string s, char c) {
    int i = 0;
    int counter = 0;
    
    if (s == "") { // if empty string return 0
        return 0;
    }
    
    if (s[0] == c) { // if first char is equal to delimiter increment i
        i += 1;
    }
    if (s[s.length() == c]) { // if last char is equal to delimiter increment counter
        counter++;
    }
    
    while (i < s.length()) {
        if (s[i] != c) { // if char is not equal to delimiter then just output the char
            cout << s[i];
        }
        else if (s[i] == c) {
            if (s[i] == s[i+1]) { // check if the char is equal to the next char
                i = i+1;
            }
            cout << " " << endl;
            counter++;
        }
        i++;
    }
    if (s[s.length() == c]) {
            i++;
        }
    if (i == s.length()) { // if i is equal to length, decrement counter and print a space
        cout << "" << endl;
        counter--;
    }

    
    return counter;
}

int main() {
    // test 1
    // expected output
    // one
    // small
    // step
    cout << split("one small step" , ' ') << endl;
    
    // test 2
    // expected output
    // cow
    // big pig
    // fish
    split("cow/big pig//fish", '/');
    
}