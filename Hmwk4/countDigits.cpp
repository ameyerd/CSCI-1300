// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 4 - Problem 5

#include <iostream>
using namespace std;

/* 
 * Algorithm: count the number of digits of given number
 *  1. Create an int function with 1 parameter (num)
 *  2. If statement = if num is less than 0, make num equal to num times *-1 to make it positive
 *  3. If statement - if num is less than 100, check if num is less than 10 if yes return 1, otherwise return 2
 *  4. Else statement = else if num is greater than 100, check if num is less than 1000 if yes return 3, otherwise return 4
 * Input parameters: int num
 * Output : none
 * Returns: # of digits
*/

int countDigits(int num) {
    // checks if number is negative
    if (num < 0) {
        num = num * -1;
    }
    // checks if num is less than 100
    if (num < 100) {
        // if it is, check again if its less than 10, if yes return 1 otherwise (:) return 2
        return num < 10 ? 1:2;
    }
    else {
        // if its not less than 100, check if less than 1000, if yes return 3 otherwise (:) return 4
        return num < 1000 ? 3:4;
    }
}

int main() {
    // test 1
    // expected output
    // 2
    cout << countDigits(-12) << endl;
    
    // test 2
    // expected output
    // 3
    cout << countDigits(197);
}