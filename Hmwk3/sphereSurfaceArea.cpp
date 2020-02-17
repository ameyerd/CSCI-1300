/*  CS1300 Spring 2019
    Author: Amey Erdenebileg
    Recitation: 304 - Shudong Hao
    Cloud 9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
    Homework 3 - Problem 6
*/

#include <iostream>
#include <math.h>
using namespace std;

/* 
 * Algorithm: Create a function that calculates the surface area of a sphere
 *  1. Create a void function that has a double parameter for the radius
 *  2. Create a double variable that calculates the surface area of a sphere
 *  3. Output answer
 * Input parameters: double, radius
 * Output : "surface area: (answer)"
 * Returns: none
*/

void sphereSurfaceArea(double radius) {
    // define surface_area variable
    double surface_area = 4 * M_PI * pow(radius, 2);
    // print out surface area
    cout << "surface area: " << surface_area << endl;
    
}

int main() {
    // test 1
    // expected output
    // "surface area: 314.159"
    sphereSurfaceArea(5);
    
    // test 2
    // expected output
    // "surface area: 1520.53"
    sphereSurfaceArea(11);
}