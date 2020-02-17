/*  CS1300 Spring 2019
    Author: Amey Erdenebileg
    Recitation: 304 - Shudong Hao
    Cloud 9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
    Homework 3 - Problem 7
*/

#include <iostream>
using namespace std;

/* 
 * Algorithm: Create a function that converts seconds into hours, minutes, seconds
 *  1. Create a void function that has an int paramenter for seconds
 *  2. Create an int variable for hours that calculates hours from seconds
 *  3. Create an int variable for minutes that calculates the remainder minutes
 *  4. Create an int variable seconds that calculates the remainder seconds
 *  5. Output the answer
 * Input parameters: int, seconds
 * Output : "(answer) hours, (answer) minutes, (answer) seconds"
 * Returns: none
*/

void convertSeconds(int seconds) {
    // define hours variable
    int hours;
    hours = seconds / 3600;
    // define minutes variable
    int minutes;
    minutes = (seconds % 3600) / 60;
    // define second variable
    int second;
    second = seconds % 60;
    // prints out hours, minutes and seconds
    cout << hours << " hour(s) " << minutes << " minute(s) " << second << " second(s)" << endl;
    
    
}

int main() {
    // test 1
    // expected output
    // 1 hour(s) 2 minute(s) 41 second(s)
    convertSeconds(3761);
    
    // test 2
    // expected output
    // 255 hour(s) 52 minute(s) 0 second(s)
    convertSeconds(921120);
}