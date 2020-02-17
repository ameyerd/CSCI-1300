/*  CS1300 Spring 2019
    Author: Amey Erdenebileg
    Recitation: 304 - Shudong Hao
    Cloud 9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
    Homework 3 - Problem 9
*/

#include <iostream>
#include <iomanip>
using namespace std;

/* 
 * Algorithm: Create a function that converts celsius to fahrenheit
 *  1. Create a void function that has an int parameter for temperature in celsius
 *  2. Create a double variable that converts celsisus to fahrenheit
 *  3. Ouput answer
 * Input parameters: int, temp (in celsius)
 * Output : "The temperature of (temp) in Fahrenheit is (answer)"
 * Returns: none
*/

void celsiusToFahrenheit(int temp) {
    // The conversion variable converts the temp celsius parameter into Fahrenheit
    double conversion = ((9.0/5.0) * temp) + 32;
    // Output answer
    cout << "The temperature of " << temp << " in Fahrenheit is " << setprecision(2) << fixed << conversion << endl;
    
}

int main() {
    // test 1
    // expected output
    // 100.40
    celsiusToFahrenheit(38);
    
    // test 2
    // expected output
    // 32.00
    celsiusToFahrenheit(0);
}