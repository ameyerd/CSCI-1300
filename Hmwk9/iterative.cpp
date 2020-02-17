// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 9 - Problem 1

#include <iostream>
#include <string>
using namespace std;

/* 
 * Algorithm: converts a decimal value to integer using a loop
 *  1. first calculate the first remainder which will be the last number
 *  2. create a string value and a while loop 
 *  3. In the while loop update num by dividing it by two and also create another 
 *     variable for the remainder of that division
 *  4. add the the remainder to the binary string
 *  5. flip the string around and then add the last number
 * Input parameters: int num
 * Output : none
 * Returns: result (binary)
*/

string decimalToBinaryIterative(int num) {
    
    
    int last = num % 2; // save the last num in a variable which is going
                        // to be needed later on 
    
    string binary;

    while(num > 1) {    // stop when it reaches 1
        
        num = num / 2;      // update num 
        
        int remain = num % 2;   // get remainder which is the binary value
        
        string bin = to_string(remain); // int --> string
        
        binary += bin;  // append to string
    }
    
    string result;
    for(int i = binary.length() - 1; i >= 0; i--) { // reverse the order of the numbers
        result = result + binary[i];
    }
    
    result = result + to_string(last);  // add the last variable
    return result;
}

int main() {
    
    // test case 1
    // expected output
    // 101
    cout << decimalToBinaryIterative(5) << endl;
    
    //test case 2
    // expected output
    // 11010
    cout << decimalToBinaryIterative(26);

    
}