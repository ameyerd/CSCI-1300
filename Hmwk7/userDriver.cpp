// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 4

#include <iostream>
#include "User.h"
using namespace std;

int main() {
    
    // test 1
    // expected output
    // set/get setRatingAt(40,3) [numRating=45]
    // Setting rating at 40 to 3
    // setRatingAt(40,3) returned: true
    // getRatingAt(40) returned: 3
    
    User u1 = User();
    int nRating = 45;
    u1.setNumRatings(nRating);
    int rating = 3;
    int idx = 40;
    cout << "set/get setRatingAt(" << idx << "," << rating << ") [numRating=" << nRating  << "]" << endl;
    cout << "Setting rating at " << idx << " to " << rating << endl;
    string ratingset = u1.setRatingAt(idx,rating) ? "true": "false";
    cout << "setRatingAt(" << idx << "," << rating << ") returned: " << ratingset << endl;
    cout << "getRatingAt(" << idx << ") returned: " << u1.getRatingAt(idx) << endl;
    
    cout << endl;
    // test 2
    // expected output
    // set/get setRatingAt(23,-2) invalid rating
    // Setting rating at 23 to -2
    // setRatingAt(23,-2) returned: false
    // getRatingAt(23) returned: 0
    User u2 = User();
    int nRatings = 45;
    u2.setNumRatings(nRatings);
    int ratings = -2;
    int indx = 23;
    cout << "set/get setRatingAt(" << indx << "," << ratings << ") invalid rating" << endl;
    cout << "Setting rating at " << indx << " to " << ratings << endl;
    string  ratingsets = u2.setRatingAt(indx,ratings) ? "true": "false";
    cout << "setRatingAt(" << indx << "," << ratings << ") returned: " << ratingsets << endl;
    cout << "getRatingAt(" << indx << ") returned: " << u2.getRatingAt(idx) << endl;
        
}