// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// hmwk6 - Problem 2

#include <iostream>
using namespace std;

/*
* Algorithm: write a function that indicates whether a postition is above or below water level
* 1. create a void function that accepts an array, int and double
* 2. create a for loop w variable i
*       create a for loop within the othser one w variable j
* 4. check if array[i][j] is less than or equal to water level output, "*""
* 5. check if array[i][j] is more than water level, output "_"
* Input parameters: double array, int rows, double water level
* Output: depends on array
* Returns:none
*/

void floodMap(double array[][4], int rows, double water) {
    
    // if array[i] <= water == *
    // if array[i] > water == _
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (array[i][j] <= water) { // check if array is less than or equal water level
                cout << "*";
            }
            if (array[i][j] > water) { // check if array is greater water level
                cout << "_";
            }
        }
        cout << "" << endl;
    }
}

int main() {
    
    // test 1
    // expected output
    // ____
    // ____
    double map[2][4] = {{0.2, 0.8, 0.8, 0.2},
    {0.2, 0.2, 0.8, 0.5}};
    floodMap(map, 2, 0.0);
    
    cout << endl;
    
    // test 2
    // expecuted output
    // *__*
    // **_*
    floodMap(map, 2, 0.5);
    
}