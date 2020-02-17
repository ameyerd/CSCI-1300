// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Hmwk 8 - Problem 1


#include <iostream>
#include <vector>
using namespace std;

/*
* Algorithm: takes two input vectors and returns a vector that combines the two vectors
*            by alternating between values
* 1. Create two new vectors both empty
* 2. If the sizes of the input vectors are the same return the empty vector
* 3. if the size of the first vector is larger start alternating with that vector, vice versa with the seconds vector
* 4. if one is shorter continue by adding the rest of the values of the other ones to the new vector
* Input parameters: vector v1, vector v2
* Output (prints to screen): none
* Returns: newvec (alternated newvector)
*/
vector<int> shuffle(vector<int> value1, vector<int> value2) {
    // two new vectors
    vector<int> empty;
    vector<int> newvec;
    
    // if both vectors are the same size
    if (value1.size() == 0 && value2.size() == 0) {
        return empty;
    }
    else if (value1.size() == value2.size()) {
        for (int i = 0; i < value1.size(); i++) {
            newvec.push_back(value1[i]); // add to new vector from v1
            newvec.push_back(value2[i]); // add to new vector from v2
        } 
    }
    else if (value1.size() > value2.size()) {
        int i;
        for (i = 0; i < value2.size(); i++) {
            newvec.push_back(value1[i]);
            newvec.push_back(value2[i]);
        }
        
        int remain = value1.size() - value2.size(); // calculate the remaining # of values
                                                    // of the two vectors
        
        for (int m = 0; m < remain; m++) {
            newvec.push_back(value1[i]);  // add the rest to the new vector
            i++;
        }
    }
    else if (value1.size() < value2.size()) {
        int j;
        for (j = 0; j < value1.size(); j++) {
            newvec.push_back(value2[j]);
            newvec.push_back(value1[j]);
        }
        
        int remain = value2.size() - value1.size();
        
        for (int k = 0; k < remain; k++) {
            newvec.push_back(value2[j]);
            j++;
        }
        
    }
    
    return newvec;
    
}


int main() {
    // test 1
    // expected outoput
    // 2 1 4 3 6 5 8 9 10 
    vector<int> v1{1,3,5,9};
    vector<int> v2{2,4,6,8,10};
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    
    cout << endl;
    
    // test 2
    // expected output
    // 1 5 3 -7
    vector<int> v4{1,3};
    vector<int> v5{5,-7};
    vector<int> v6 = shuffle(v4,v5);
    for (int i=0; i < v6.size(); i++) {
        cout << v6[i] << " ";
    }
    

}