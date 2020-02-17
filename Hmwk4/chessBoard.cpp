// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 4 - Problem 4

#include <iostream>
using namespace std;

/* 
 * Algorithm: determine if square is black or white
 *  1. Create a void function with 2 parameters (char character and int num)
 *  2. If statement = if character is a,c,e,g and num is an odd number then output black
 *  3. If statement - if character is b,d,f,h and num is an even number then output black
 *  4. Else if statement = if character is a,c,e,g and num is an even number then output white
 *  5. Else if statement = if character is b,d,f,g and num is an odd number then output white
 * Input parameters: char character, int num
 * Output : black, white
 * Returns: none
*/

void chessBoard(char character, int num) {
    // check if character and num is in range a-h, 1-9
    if ((character == 'a' || character == 'b' || character == 'c' || character == 'd' || character == 'e' || character == 'f' || character == 'g' || character == 'h') && num <= 8 && num >=1 ) {
        // for characters a,c,e,g and num 1,3,5,7, square is black
        if ((character == 'a' || character == 'c' || character == 'e' || character == 'g') && (num == 1 || num == 3 || num == 5 || num == 7)) {
            cout << "black" << endl;
        }
        // for characters b,d,f,h and num 2,4,6,8, square is black
        if ((character == 'b' || character == 'd' || character == 'f' || character == 'h') && (num == 2 || num == 4 || num == 6 || num == 8)) {
            cout << "black" << endl;
        }
        // for characters a,c,e,g and num 2,4,6,8, square is white
        else if ((character == 'a' || character == 'c' || character == 'e' || character == 'g') && (num == 2 || num == 4 || num == 6 || num == 8)) {
            cout << "white" << endl;
        }
        // for characters b,d,f,h and num 1,3,5,7, square is white
        else if ((character == 'b' || character == 'd' || character == 'f' || character == 'h') && (num == 1 || num == 3 || num == 5 || num == 7)) {
            cout << "white" << endl;
        }
    }
    else {
        cout << "Chessboard squares can only have letters between a-h and numbers between 1-8";
    }
}

int main() {
    // test 1
    // expected output
    // white
    chessBoard('d',3);
    
    // test 2
    // expected output
    // black
    chessBoard('g',5);
}