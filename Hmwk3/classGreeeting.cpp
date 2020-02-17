/*  CS1300 Spring 2019
    Author: Amey Erdenebileg
    Recitation: 304 - Shudong Hao
    Cloud 9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
    Homework 3 - Problem 3
*/

#include <iostream>
using namespace std;

/* 
 * Algorithm: Make a function that outputs answer using parameter
 *  1. Create a void function that doesn't return anything
 *  2. Make the function so it accepts an int parameter
 *  3. Output "Hello, CS (user input) World!"
 * Input parameters: int, course_number
 * Output : "Hello, CS (user input) World!"
 * Returns: none
*/

void classGreeting(int course_number) {
    // prints output using the parameter passed into the function
    cout << "Hello, CS " << course_number << " World!" << endl;
}

int main() {
    // test 1
    // expected output
    // "Hello, CS 1300 World!"
    classGreeting(1300);
    
    // test 2
    // expected output
    // "Hello, CS 1234 World!"
    classGreeting(1234);
}