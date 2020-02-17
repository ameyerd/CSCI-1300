// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project1 - Problem 2

#include <iostream>
using namespace std;

/* rollDie
* returns a random integer between 1 and 6,
* works as rolling a die.
* return value, int number (1-6)
*/

int rollDie()
{
    return random() % 6 + 1;
}

/*
* Algorithm: repeatedly roll two dice until their sum is the desired sum
*   1. Create a void function that accepts 1 paramenter (int, dsum)
*   2. Define sum and number as int variables and set them equal to 0
*   3. Create an if statement to check if dsum is between 2-12, if not display error message
*   4. Create a while loop that rolls the two dice and outputs the sum of the two and adds 1 to the number
*      variable, keep repeating if the sum doesn't equal the dsum
*   5. Create an if statement that checks when sum is equal to dsum output dsum and number variable
* Input parameters: int dsum
* Output: Got a <dsum> in <number> rolls!
* Returns: none
*/

void diceSum(int dsum) {
    
    int sum = 0;
    int number = 0;
    if (dsum <= 12 && dsum >=2) {
        while (sum != dsum) {
            int die1 = rollDie();
            int die2 = rollDie();
            sum = die1 + die2;
            cout << "You rolled a " << die1 << " and a " << die2 << endl;
            number++;
        }
        if (sum == dsum) {
            cout << "Got a " << dsum << " in " << number << " rolls!" << endl;
        }
    }
    else {
        cout << "The desired sum should be between 2 and 12";
    }
}


int main() {
    // test 1
    // expected output
    // Got a 10 in _ rolls!
    diceSum(10);
    
    // test 2
    // expected output
    // Got a 3 in _ rolls!
    diceSum(3);
}