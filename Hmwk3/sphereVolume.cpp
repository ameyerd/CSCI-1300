/*  CS1300 Spring 2019
    Author: Amey Erdenebileg
    Recitation: 304 - Shudong Hao
    Cloud 9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
    Homework 3 - Problem 5
*/

#include <iostream>
#include <math.h>
using namespace std;

/* 
 * Algorithm: Create a function that calculates the volume of a sphere
 *  1. Create a void function that has a double parameter for radius
 *  2. Create a double variable for the volume that calculates the volume of the sphere
 *  3. Output answer
 * Input parameters: double, radius
 * Output : "volume: (answer)"
 * Returns: none
*/
void sphereVolume(double radius) {
    // define volume variable
    double volume = (4.0/3.0) * M_PI * pow(radius, 3);
    // print out volume
    cout << "volume: " << volume << endl;
    
}

int main() {
    
    // test 1
    // expected output
    // "volume = 523.599"
    sphereVolume(5);
    
    // test 2
    // expected output
    // "volume = 7238.23"
    sphereVolume(12);
}