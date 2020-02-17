// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 4 - Problem 1

#include <iostream>
using namespace std;

/* 
 * Algorithm: output either "positive", "negative" or "zero" depending on input
 *  1. Create a void function with an int parameter (num)
 *  2. If statement = if num is greater than 0, output "positive"
 *  3. If statement - if num is less than 0, output "negative"
 *  4. If statement = if num is equal to 0, output "zero"
 * Input parameters: int, num
 * Output : "positive", "negative" or "zero"
 * Returns: none
*/

void numberSign(int num) {
    // if num is greater than 0, output "positive"
    if (num > 0) {
        cout << "positive" << endl;
    }
    // if num is less than 0, output "negative"
    if (num < 0) {
        cout << "negative" <<endl;
    }
    // if num is equal to 0, output "zero"
    if (num ==0) {
        cout << "zero" << endl;
    }
}

int main() {
    // test 1
    // expected output
    // negative
    numberSign(-12);
    
    // test 2
    // expected output
    // positive
    numberSign(289);
}