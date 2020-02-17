// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 4 - Problem 3

#include <iostream>
using namespace std;

/* 
 * Algorithm: check if 3 int numbers are all same, all different or neither
 *  1. Create a void function with 3 int parameters (A,B, C)
 *  2. If statement = if all parameters are the same value then output all same
 *  3. If statement - if all parameters are all different then output all different
 *  4. If statement = if they are not the same but also not all different then output neither
 * Input parameters: int A, int B, int C
 * Output : All same, All different, Neither
 * Returns: none
*/

void checkEqual(int A, int B, int C) {
    // check if all 3 parameters are the same
    if (A == B && B == C && A == C) {
        cout << "All same" << endl;
    }
    // check if all 3 parameters are different
    else if (A != B && B != C && A!= C) {
        cout << "All different" << endl;
    }
    else {
        cout << "Neither" << endl;
    }
}

int main() {
    // test 1
    // expected output
    // All different
    checkEqual(1,2,3);

    // test 1
    // expected output
    // All same
    checkEqual(2,2,2);
    
}