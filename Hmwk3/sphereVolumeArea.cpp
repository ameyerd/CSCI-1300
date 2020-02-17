/*  CS1300 Spring 2019
    Author: Amey Erdenebileg
    Recitation: 304 - Shudong Hao
    Cloud 9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
    Homework 3 - Problem 4
*/

#include <iostream>
#include <math.h>
using namespace std;

/* 
 * Algorithm: Ask for user for radius and output volume and surface area
 *  1. Ask user to input radius
 *  2. Create volume variable that calculates the volume
 *  3. Output answer
 *  4. Create surface area variable that calcutes the surface area
 *  5. Output answewr
 * Input parameters: none
 * Output : "volume: (answer)
             surface area: (answer)"
 * Returns: none
*/

int main(){
    // asks user for input (radius)
    cout << "Enter a radius: " << endl;
    double radius;
    cin >> radius;
    // define volume variable
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    // define surface_area variable
    double surface_area;
    surface_area = 4 * M_PI * pow(radius, 2);
    
    // test 1
    // expected output with input 5
    // "volume: 523.599
    //  surface area: 314.159"
    cout << "volume: " << volume << endl; // print out volume
    cout << "surface area: " << surface_area << endl; // print out surface area 
   
}