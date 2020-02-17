// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 4 - Problem 2

#include <iostream>
using namespace std;

/* 
 * Algorithm: return next value in Collatz sequence
 *  1. Create an int function with an int parameter (num)
 *  2. If statement = if num is even then divide num by 2
 *  3. If statement - if num is odd then multiply num by 3 then add 1
 *  4. If statement = if num is a negative integer, return 0
 * Input parameters: int, num
 * Output : none
 * Returns: num/2 , (3*num) + 1 or 0
*/

int collatzStep(int num) {
    // checks if num is an even number
    if ((num%2) == 0) {
        return num/2;
    }
    // checks if num is an odd number
    if ((num%2) == 1) {
        return (3*num) + 1;
    }
    else {
        return 0;
    }
}

int main() {
    // test 1
    // expected output
    // 0
    cout << collatzStep(-5) << endl;
    
    // test 2
    // expected output
    // 22
    cout << collatzStep(7);
}