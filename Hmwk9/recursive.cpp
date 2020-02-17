// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 9 - Problem 2

#include <iostream>
#include <string>
using namespace std;

/* 
 * Algorithm: converts a decimal value to integer using recursion
 *  1. first calculate the first remainder which will be the last number
 *  2. if the number is less than or equal to 1, return the last number
 *  3. define variables and create another num variable similar to original num
 *  4. create an if statement for when num2 is greater than 0
 *  5. calculate the remainder and convert it into a string
 *  6. call the function itself + the remainder into the binary string variable which
 *     will loop through again until num is less than or equal to 1
 *  7. return binary string
 * Input parameters: int num
 * Output : none
 * Returns: result (binary)
*/

string decimalToBinaryRecursive(int num) {
    
    int last = num % 2;     // calculate the first number
    string lastone = to_string(last);   // convert to string
        
    if (num <= 1) {    // base case
        return lastone; 
    }
    // recursion
    string binary; 
    string bin;
        
    int num2 = num;
    
    if (num2 > 1) {
        
        int remain = num2 % 2;  // calculate remainder
        
        bin = to_string(remain);    // int --> string
        
        // call the function itself + bin and store into the binary variable
        binary = decimalToBinaryRecursive(num2 / 2) + bin;
    }
    
    return binary;

}

int main() {
    
    //test case 1
    // expected output
    // 1000
    cout << decimalToBinaryRecursive(8) << endl;
    
    // test case 2
    // expected output
    // 1
    cout << decimalToBinaryRecursive(1);
    
    
}