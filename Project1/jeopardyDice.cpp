// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project1 - Jeopardy Dice




///////////////////////////////////////////////////////////////////////////////////////////////////
// Step1: Steps to solve this problem
// write an algorithm in pseudocode explaining how you are approaching the problem, step by step 
///////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Algorithm: player competes against computer to get 80 points by rolling dice
*   1. Create first function, playerAnswer() which asks the user if they want to roll a dice
*		a. Takes user input and returns the answer
*   2. Create the second function playerAnswer2() which in the case of the user rolling a 1,3 
		or 6 the function
*		asks if they want to roll again.
*   3. Create the third function, playerTurn() that takes 1 parameter string, ans which is the 
		return from the 1st function
		a. Define the playerturnTotal as zero
		b. Create an if statement with the condition of the user input being Y or y
		c. Within the if statement create a while loop with the conditions: user input being Y/y 
			AND playerTotal is less than 80
		d. Within the while loop, roll the die and if roll is:
			i. a 2 or 5, playerturnTotal is 0 and end turn
			ii. a 4, playerturnTotal is 15 and end turn
			iii. a 1,3, or 6 playerturnTotal the user is prompted if they want to roll again, if yes
					then it loops again, if not then end turn
		e. At the end of the while loop, display both human and computer totals and return playerTotal
*   4. Create the fourth function, computerTurn() that takes no parameters
		a. Display message showing its the computer's turn
		b. Define computerturnTotal variable to 0 
		c. create a while loop with the condition that computerturnTotal is less than 10 
		d. create an if statment for rolls similar to playerTurn()
		e. display computer turn total after each roll
		f. After the while loop, display both computer and human totals and return computerTotal
	5. Create a void function game()
		a. Display game message "Welcome to Jeopardy! "
		b. create a while loop witht the conditions: playerTotal and computer Total is less than 80
		c. In the while loop, display human turn message and define playerAnswer variable to use as a parameter
			in the playerTurn() fucntion
		d. Call playerTurn() function
		e. create an if statement, if playerTotal is less than 80, then call the computerTurn() function
		f. Create an if statement for conditions to end the game
			i. if playerTotal is greater than or equal to 80 then print congrats human message
			ii. else if computerTotal is greater than or equal 80 then print congrats computer message
* Output: Congratulations! (human/computer) won this round of Jeopardy Dice!
*/




///////////////////////////////////////////////////////////////////////////////////////////////////
// Step2: Code it up! 
// After finishing up your pseudocode, translate them into c++ 
// IMPORTANT: rollDie() and main() are already written for you.
// You need to complete game function as well as at least 3 other additional functions
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 

/**
 * rollDie 
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
 */

int rollDie()
{
	return random() % 6 + 1; 
}

// your 3 + functions go in here

// define overall computer and player total outside of functions
int computerTotal = 0;
int playerTotal = 0;

// This function asks for user input if they want to roll the dice
// Return: answer
string playerAnswer() {
	string answer = " ";
	cout << "Do you want to roll a dice (Y/N)?: " << endl;
	cin >> answer;
	return answer;
}

// This function asks the user for input if they want to roll the dice again
// Return: answer2
string playerAnswer2() {
    string answer2 = " ";
    cout << "Do you want to roll again (Y/N)?: " << endl;
    cin >> answer2;
    return answer2;
}

// This function is for the players turn
// Return: playerTotal
int playerTurn(string ans) {
    int playerturnTotal = 0;
    
    if (ans == "Y" || ans == "y") {
    	// while loop rolls die if ans is Y and playerTotal is less than 80
		while ((ans == "Y" || ans == "y") && playerTotal < 80) {
			int roll = rollDie();
			cout << "You rolled a " << roll << endl;
			if (roll == 2 || roll == 5) {
				playerturnTotal = 0;
				
				cout << "Your turn total is " << playerturnTotal << endl;
				break; // end turn
			}
			else if (roll == 4) {
				playerturnTotal =  15;
				
				cout << "Your turn total is " << playerturnTotal << endl;
				break;
			}
			else if (roll == 1 || roll == 3 || roll == 6) {
				playerturnTotal = playerturnTotal + roll;
				
				cout << "Your turn total is " << playerturnTotal << endl;
				ans = playerAnswer2();
			}
    }
}
	playerTotal = playerTotal + playerturnTotal; // adds turn total to overall Player total
    cout << "computer: " << computerTotal << endl;
	cout << "human: " << playerTotal << endl;
	return playerTotal;
}

int computerTurn() {
    cout << "It is now computer's turn " << endl;
    cout << " " << endl;
    
    int computerturnTotal = 0;
    
    // while loop rolls die if computer turn total is less than 10
    while (computerturnTotal < 10) {
        int roll = rollDie();
		cout << "Computer rolled a " << roll << endl;
		if (roll == 2 || roll == 5) {
			computerturnTotal = 0;
			break; 
		}
		else if (roll == 4) {
			computerturnTotal = 15;
			break; 
		}
		else if (roll == 1 || roll == 3 || roll == 6) {
			computerturnTotal = computerturnTotal + roll;
		}
	    cout << "Computer turn total is " << computerturnTotal << endl;
		 
    }
    // adds turntotal to overall computer total
    computerTotal = computerTotal + computerturnTotal;
    cout << "computer: " << computerTotal << endl;
    cout << "human: " << playerTotal << endl;
    return computerTotal;
}

/**
 * game 
 * driver function to play the game
 * the function does not return any value
 */

void game()
{

	// your solution goes here
	cout << "Welcome to Jeopardy Dice!" << endl;
	cout << " " << endl;
	// while loop for turns if both overall totals are less than 80
	while (playerTotal < 80 && computerTotal < 80) {
		cout << "It is now human's turn " << endl;
		cout << " " << endl;
		string ans = playerAnswer();
		playerTurn(ans); // takes input from playerAnswer()
		cout << " " << endl;
		if (playerTotal < 80) {
		    computerTurn();
		    cout << " " << endl;
		}
		
	}
	if (playerTotal >= 80) {
	    cout << "Congratulations! human won this round of Jeopardy Dice! " << endl;
	}
	else if (computerTotal >= 80) {
		cout << "Congratulations! computer won this round of Jeopardy Dice! " << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// don't change the main. 
// Once you finished please paste your code above this line 
///////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	// start the game! 
	game();
	return 0;
}