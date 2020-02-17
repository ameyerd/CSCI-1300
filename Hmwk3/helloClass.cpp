/*  CS1300 Spring 2019
    Author: Amey Erdenebileg
    Recitation: 304 - Shudong Hao
    Cloud 9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
    Homework 3 - Problem 2
*/

#include <iostream>
using namespace std;

/* 
 * Algorithm: ask for user input and output answer
 *  1. Output "Enter a CS course number: "
 *  2. User enters their input
 *  3. Output "Hello, CS (user input) World!"
 * Input parameters: none
 * Output : "Hello, CS (user input) World!"
 * Returns: none
*/

int main() {
    // asks user for their input (course number)
    cout << "Enter a CS course number: " << endl;
    int course;
    cin >> course;
    
    // test 1
    // expected output
    // "Hello, CS (course) World!"
    cout << "Hello, CS " << course << " World!" << endl;
    
}