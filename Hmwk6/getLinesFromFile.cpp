// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// hmwk6 - Problem 4

#include <iostream>
#include <fstream>
using namespace std;

/*
* Algorithm: write a function that reads from a text file and stores its contents in an array
* 1. create an int function that accepts a string, int and another int
* 2. declare file to be opened, and open the file
* 3. check if the file is open, if not return -1
* 4. declare string s and int i 
* 5. create a while loop that reads each line and puts them in the s string
* 6. If the length of s is 0 continue;
* 7. convert the string into and integer and stores it into the array, increment i
* 9. check if index is greater than length, if so decrement i and continue;
* 10. close the file and return index
* Input parameters: string fileName, int arr[], int length
* Output: none
* Returns: index
*/

int getLinesFromFile(string fileName, int arr[], int length) {
    
    ifstream fp;
    fp.open(fileName);
    if (fp.is_open()) {
        string s;
        int index = 0;
        while (getline(fp, s)) {
            //cout << "--" << s << "--" << endl;
            if (s.length() == 0) continue; // ignores the rest
            
            int number = stoi(s); // stoi = string to integer
            arr[index] = number; // store int into array
            
            index++;
            if (index > length) { // check if index is greater than length
                index--;
                continue;
            }
        }
        fp.close();
        return index;
    }
    
    else {
        return -1;
    }
}


int main(){
    
    // test 1
    // expected output
    // Function returned: 7
    int numArray[7];
    int x = getLinesFromFile("testFile.txt", numArray, 7);
    cout << "Function returned: " << x << "\n";
    for(int i = 0; i < 7; i++){
        cout << numArray[i] << "\n";
    }
    
    cout << endl;
    
    // test 2
    // expected output
    // Function returned: 3
    int y = getLinesFromFile("testFile.txt", numArray, 3);
    cout << "Function returned: " << y << "\n";
    for(int i = 0; i < 3; i++){
        cout << numArray[i] << "\n";
    }
    
    
    
    
    
}