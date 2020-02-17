// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 4 - Problem 6

#include <iostream>
using namespace std;

/* 
 * Algorithm: 
 *  1. Create an int function with an int parameter (month)
 *  2. create a Switch statement with 12 cases for each month and 
 *     return # of hours in that month
 *  3. Return corresponding # of hours of each month
 * Input parameters: int, month
 * Output : none
 * Returns: # of hours depending on which month
*/

int countHours(int month) {
    // switch statements that display the hours in a month
    switch (month) {
        // jan
        case 1:
            return 744;
            break;
        // feb    
        case 2:
            return 672;
            break;
        // mar
        case 3:
            return 744;
            break;
        // apr
        case 4:
            return 720;
            break;
        // may
        case 5:
            return 744;
            break;
        // june
        case 6:
            return 720;
            break;
        // july
        case 7:
            return 744;
            break;
        // aug
        case 8:
            return 744;
            break;
        // sept
        case 9:
            return 720;
            break;
        // oct
        case 10:
            return 744;
            break;
        // nov
        case 11:
            return 720;
            break;
        // dec
        case 12:
            return 744;
            break;
    }
}

int main() {
    // test 1
    // expected output
    // 720
    cout << countHours(4) << endl;
    
    // test 2
    // expected output
    // 672
    cout << countHours(2);
}