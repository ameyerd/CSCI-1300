// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// hmwk6 - Problem 5

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//split function
int split(string str, char c, string array[], int num) {
    
    if (str.length() == 0) {
        return 0;
    }
    int a = 0;
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
        	array[a] = word; 
        	a++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j ;
    
}


// read Books

/*
* Algorithm: populates a pair of arrays with titles and authors in a text file
* 1. create an int function that accepts five input arguments
* 2. declare file to be opened, and open the file
* 3. check if numBookStores is equal to size, if so return -2
* 4. check if the file is open, if it's not open return -1
* 5. declare an array and string
* 6. create a while loop that reads each line and puts them in the s string
* 7. check if the length of s is equal to 0, if so contiue
* 8. use the split fucntion and split the file by commas
* 9. store the first column of the array into author variable
* 10. store the second column of the array into the title variable
* 11. if numBookStored is equal to the size then break from loop
* 12. close the file and return numBookStored
* Input parameters: string fileName, string titles[], string authors[], int numBookStored, int size
* Output: none
* Returns: numBookStored
*/

int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size) {
    
    ifstream fp;
    fp.open(fileName);
    
    if (numBookStored == size) {
        return -2;
    }
    
    
    if (fp.is_open()) {
        string temp_array[size];
        string s = "";
        int i = numBookStored;
        while (getline(fp, s)) { // read line
            if (s.length() == 0) continue;
            
            split(s, ',', temp_array, size); // use split function
            string author = temp_array[0]; // first column is the author
            string title = temp_array[1]; // second column is the title of book
            
            authors[i] = author; // store into authors array
            titles[i] = title; // store into title array
            
            i++;
            
            if (i == size) {
                break;
            }
            
                
        }
        
        
        fp.close();
        return i;
        
        }
        else {
        return -1;
        
    }
    
}



int main() {
    
    string authors[10] = {};
    string titles[10] = {};
    
    // test 1
    // expected ouput
    // 2
    cout << readBooks("fileName.txt",titles,authors, 0, 10) << endl;
    
    // test 2
    // expected output
    // 2
    cout << readBooks("fileName.txt", titles, authors, 0, 5);
    
}