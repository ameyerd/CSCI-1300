/*  CS1300 Spring 2019
    Author: Amey Erdenebileg
    Recitation: 304 - Shudong Hao
    Cloud 9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
    Homework 3 - Problem 10
*/

#include <iostream>
#include <math.h>
using namespace std;

/* 
 * Algorithm: Create a function that calculates deceleration
 *  1. Create a double function that has a double parameter for inital speed and a double parameter for distance
 *  2. Create a double variable that calculates the deceleration using the 2 parameters
 *  3. Return answer
 * Input parameters: double, initial speed : double, distance
 * Output : none
 * Returns: deceleration
*/

double marioKart(double initialSpeed, double distance) {
    
    // The deceleration  variable calculates the deceleration with the two parametres
    double deceleration = pow(initialSpeed, 2) / (2 * distance);
    // return deceeleration vaariable
    return deceleration;
    
}

int main() {
    // test 1
    // expected output
    // 1
    cout << marioKart(4, 8) << endl;
    
    // test 2
    // expected output
    // 56.25
    cout << marioKart(30, 8);
}