// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 2

#include <iostream>
#include <string>
#include "Planet.h"
using namespace std;

/* Algorithm: write a function that returns the planet with the largest radius in an array
*   1. create an int function that returns the idx of the planet with the largest radius
*   2. if the size = 0, return -1
*   3. create 2 int vars to keep track of the largest radius and the idx
*   4. create a for loop that loops through the planets in the array and update largest variable if
*       the radius of the planet is larger than the previous one
*   5. return idx
* Inputer parameters: Planet planets[], int size
* Output: none
* Returns: idx (planet with largest radius)
*/

int maxRadius(Planet planets[], int size) {
    
    if (size == 0) {
            return -1;
        }
    
    int largest = 0;
    int idx = 0;
    for (int i = 0; i < size; i++) {
        int rad = planets[i].getRadius();
        if (rad > largest) {
            largest = rad;
            idx = i;
        }
    }
    
    return idx;
}


int main() {
    // in bash: g++ maxRadiusDriver.cpp Planet.cpp
    
    // test 1
    // expected output
    // Bird World
    // 4321
    // 3.37941e+11
    Planet planets[5];
    planets[0] = Planet("On A Cob Planet", 1234);
    planets[1] = Planet("Bird World", 4321);

    int idx = maxRadius(planets, 2);
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
    
    // test 2
    // expected output
    // -1
    //Planet planets[3];
    //int idex = maxRadius(planets, 0);
    //cout << idex << endl;
    
}