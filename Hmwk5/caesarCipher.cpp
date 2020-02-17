// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 5 - Problem 4

#include <iostream>
#include <string>
using namespace std;


/*
* Algorithm: write a function that either encrypts or decrypts 
*            a message 3 position foward in the alphabet
* 1. check if key is between 0-25, if not return ERROR
* 2. create a for loop setting i = 0 and checking if i is less than message length
* 3. create an if statement to check if flag is true
* 4. if flag is true add key to the current index of i 
* 5. check if message[i] is more than 90 or less than 60
        if yes, then subtract 26
* 6. also check if the character is a space if it is then keep it as a space
* 7. if flag is false then subtract the key from message[i] 
* 8. if message[i] is less than 65 then add 26
* 9. also check if the character is a space if it is then keep it as a space
* Input parameters: string message, int key, bool flag
* Output: none
* Returns: encrypted or decrypted message
*/


string caesarCipher(string message, int key, bool flag){
    
    
    if (key < 0 || key > 25)
    {
        return "ERROR";
    }
    
    for (int i = 0; i < message.length(); i++)
    {
        
        if (flag == true)
        {
            message[i] = message[i] + key; // encode = add key
            if (message[i] > 90 || message[i] < 65)
            {
                    message[i] = message[i] - 26;
                    if (message[i] - key + 26 == 32) // check if current index is a space
                {
                    message[i] = 32; // if yes, then keep it as a space
                }
            }
        }
        else 
        {
            message[i] = message[i] - key; // decode = substract key
            if (message[i] < 65)
            {
                message[i] = message[i] + 26;
                if (message[i] + key - 26 == 32)
                {
                    message[i] = 32;
                }
            }
            
        }
        
    }
    return message;
    
}


int main() {
    // test 1
    // expected output
    // VJH CQN OXALN KN FRCQ HXD
    cout << caesarCipher("MAY THE FORCE BE WITH YOU", 9, true) << endl;
    
    // test 2
    // expected output
    // YZAB
    cout << caesarCipher("ABCD", 2, false);
}