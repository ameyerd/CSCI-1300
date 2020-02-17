// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// hmwk6 - Problem 1

#include <iostream>
using namespace std;


int main() {
    
    float temps[10] = {-459.67,-459.67,-459.67,-459.67,-459.67,-459.67,-459.67,-459.67,-459.67,-459.67};
    
    // temps test
    
    for (int i = 0; i < 10; i++) 
    {
        cout << temps[i] << endl;
    }
    
    cout << endl;
    
    string colors[] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
    
    // colors test
    
    for (int i = 0; i < 5; i++) 
    {
        cout << colors[i] << endl;
    }
    
    cout << endl;
    
    int sequence[100];
    
    // sequence test 
    
    for (int i = 1; i <= 100; i++) {
        sequence[i] = i; // store i into sequence array
        cout << sequence[i] << endl;
    }
    
    cout << endl;
    
    char letters[26][2];  // 2D array
    
    // letters test
    
    for (int i = 0; i < 26; i++) 
    {
        char a = 65;
        char letter = a + i; 
        for (int j = 0; j < 2; j++) {
            letters[i][j] = letter;
            cout << letters[i][j] << " ";
            letter += 32;
        }
        cout << endl;
    }
    
}