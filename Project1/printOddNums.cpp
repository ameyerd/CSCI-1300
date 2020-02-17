// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 1 - Problem 1

#include <iostream>
using namespace std;

/*
* Algorithm: print odd numbers given a max value
*   1. Create a void function that accepts 1 paramenter (int, max)
*   2. Define num variable as an int and set = to 1
*   3. Create a while loop that if num is less than or equal to max, print num and add 2
*   4. Repeat until num is not less or equal to max value
* Input parameters: int max
* Output: odd #s depending on max value
* Returns: none
*/

void printOddNums(int max) {
    // define num variable as an int and set = to 1
    int num = 1;
    // loop when num is less than or equal to max value
    while (num <= max) {
        cout << num << endl;
        // update num variable by adding 2
        num += 2;
    }
}

int main() {
    // test 1
    // expected output
    // 1 3 5 7
    printOddNums(8);
    
    // test 2
    // expected output
    // 1 3 5 7 9 11
    printOddNums(11);
}