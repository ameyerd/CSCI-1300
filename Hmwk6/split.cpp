// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// hmwk6 - Problem 3

#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: 
* 1. create an int function that accepts a string, char, array and int
* 2. check if the string length is 0, if so return 0
* 3. declare int a and j and set them equal to 0, also declare an empty string
* 4. create a for loop w variable i
*       check if the current charactere is equal to the delimiter(c)
*       if so then also check if the length of word is 0 if so continue;
*       store the word into the array and increment a and j, then reset word back to an empty string
*       else:
*       add the character to word string and loop again
* Input parameters: 
* Output: none
* Returns: j, # of splits
*/

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

int main() {
    
    // test 1
    // expected output
    // 3
    string words[6];
    cout << split("cow/big pig//fish",'/',words,6) << endl;
    
    cout << endl;
    
    // test 2
    // expected output
    // 2
    cout << split("one step",' ',words,6) << endl;
    
    
    
}
