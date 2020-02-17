// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 5 - Problem 5

#include <iostream>
using namespace std;


/*
* Algorithm: encrypt or decrypt a message based on key
* 1. create a for loop and define two variables
* 2. create an if statement to check if j is greater than key length
*    if yes, then add 1 to j
* 3. create an if statement to check if j is eqal to key length
*     if yes, then j is equal to 0
* 4. create an if statement to check if the current index of i is a space
*    if yes, then decrement i
* 5. create an if-else statement that checks the value of flag
* 6. if flag is true check if the current index of i is between 65-90
*    if yes , then create another variable that calculates key[i] - 65
*    then, add that to message[i]
* 7. create an if statement to check if message[i] is greater than 90
*    if yes, then substract 26 from message[i]
* 8. if flag is false check if the current index of i is between 65-90
*    if yes , then create another variable that calculates key[i] - 65
*    then, subtract that to message[i]
* 9. create an if statement to check if message[i] is greater than 90
*    if yes, then add 26 to message[i]
*    
* Input parameters: string message, string key, bool flag
* Output: none
* Returns: encrypted or decrypted message
*/


string vigenereCipher(string message, string key, bool flag) {
    
    // true = encode
    // false = decode
    
    
    for (int i= 0,j=0; i < message.length(); i++, j++) {
        if (j > key.length())
        {
            j = 1;
        }
        if (j == key.length()) 
        {
            j = 0;
        }
        if (message[i] == 32) // if current of index of message is a space decrement j
        {
            j--;
        }
        
        if (flag == true) 
        {
            
            
            if (message[i] <= 90 && message[i] >= 65)
            {
                int diff = key[j] - 65; // calculate the difference
                
                message[i] = message[i] + diff; // add diff to message[i]
                
                
            }
            if (message[i] > 90)
            {
                
                message[i] = message[i] - 26;
            }
            
        }
        else
        {
            if (message[i] <= 90 && message[i] >= 65)
            {
                int diff = key[j] - 65; // calculate the difference
                
                message[i] = message[i] - diff; // subtract diff to message[i]
                
                
            }
            if (message[i] < 65)
            {
                
                message[i] = message[i] + 26;
            }
            
            
        }
}
    
        return message;
}


int main() {
    // test 1
    // expected output
    // UNICORNS
    cout << vigenereCipher("NVOGFKVY", "TIGER", false) << endl;
    
    // test 2
    // expected output
    // NVOGFKVY
    cout << vigenereCipher("UNICORNS", "TIGER", true);
}