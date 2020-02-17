#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"
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

string slower(string s) {
    string slow = "";
    for (int r = 0; r < s.length(); r++) {
        slow += tolower(s[r]);
    }
    return slow;
}

// --------------------------

Library::Library() {
    numBooks = 0;
    numUsers = 0;
}
int Library::getSizeBook() {
    return sizeBook;
}
int Library::getSizeUser() {
    return sizeUser;
}
int Library::getNumBooks() {
    return numBooks;
}
int Library::getNumUsers() {
    return numUsers;
}
int Library::readBooks(string fileName) {
    
    ifstream fp;
    fp.open(fileName.c_str());
    
    if (numBooks == sizeBook) {
        return -2;
    }
    
    
    if (fp.is_open()) {
        string temp_array[2];
        string s = "";
        while (getline(fp, s)) { // read line
            if (s.length() == 0) continue;
            
            split(s, ',', temp_array, 2); // use split function
            string author = temp_array[0]; // first column is the author
            string title = temp_array[1]; // second column is the title of book
            
            books[numBooks].setAuthor(author); // store into authors array
            books[numBooks].setTitle(title); // store into title array
            
            numBooks++;
            
            if (numBooks == sizeBook) {
                break;
            }
            
                
        }
        
        
        fp.close();
        return numBooks;
        
        }
        else {
        return -1;
        
    }
    /*Takes a string (the name of the file to be read) and
populates the books array. Returns the total
number of books in books array as an integer */
}

void Library::printAllBooks() {
    // prints all books stored in books array
    
    if (numBooks <= 0) { 
        cout << "No books are stored" << endl;
    }
    else {
        int i = 0;
        cout << "Here is a list of books" << endl;
        while(i < numBooks) {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
            i++;
        }
    }
    
}

int Library::readRatings(string fileName) {
    /* Takes a string (the name of the file to be read) and
populates the users array. Returns the total
number of users in users array as an integer */

    // declare variable and open file
    ifstream fp;
    fp.open(fileName.c_str());
    
    // if numUsers is equal to max rows then return -2
    if (numUsers == sizeUser) {
        return -2;
    }
    
    // check if file is open
    if (fp.is_open()) {
        
        // declare string and array
        string s;
        string rating_array[51];
        
        // while function that reads the file
        while (getline(fp, s)) {
            //Check Empties
            if (s == "") continue;
            
            //check if it has reached maxRows
            if(numUsers == sizeUser) {
                    break;
                }
            // use split function
            split(s, ',', rating_array, 51);
            
            
            // for loop for ratings
            int b = 0;
            for (int j = 1; j < split(s, ',', rating_array, 51) ; j++) {
                
                
                // declare new string for rating values
                string r = rating_array[j];
                // stoi 
                int rating_int = stoi(r);
                // store into ratings[numUsers][j]
                users[numUsers].setRatingAt(b, rating_int); // if not j then b
                // reset string r
                r = "";
                b++;
                
            }
         
            
            // declare user variable to store 0th column (names) of rating_array
            string user = rating_array[0];
            // store into users[numUsers] array
            users[numUsers].setUsername(user);
            // increment i
            numUsers++;
            
        }
        
        // close file
        fp.close();
        // return numUsers;
        return numUsers;
        
    }
    // else statement if file isn't open
    else {
        return -1;
    }


} 


int Library::getRating(string username, string title) {
    /* Takes two strings (username and book title) and
returns that user’s rating for the specified book */
    // first char is uppercase, rest is lowercase

    // username
    if (isupper(username[0])) { // check if first char is upper case
        for (int i = 1; i < username.length(); i++) {
            if (islower(username[i])) { // check if the next chars are lower case
                // do nothing
            }
            else {
                // to lower
                username[i] = tolower(username[i]); // make char lowercase
            }
        }
    }
    else { // if first char is not uppercase
        if(islower(username[0])) {
            // change to upper case
            username[0] = toupper(username[0]);
        }
        for (int i = 1; i < username.length(); i++) {
            if (islower(username[i])) { // check if the next chars are lower case
                // do nothing
            }
            else {
                // to lower
                username[i] = tolower(username[i]); // make char lowercase
            }
        }
        
    }
    
    //cout << username << endl;
    
    // after every space char is capital~!!
    // title
    if (isupper(title[0])) { // check if first letter of 
        for (int j = 1; j < title.length(); j++) {
            if (islower(title[j])) { // check if next chars are lowercase
                // do nothing
            }
            else {
                title[j] = tolower(title[j]);
            }
        }
    }
    else { // if first char of title is not capital
        if (islower(title[0])) {
            title[0] = toupper(title[0]);
        }
        for (int j = 1; j < title.length(); j++) {
            if (islower(title[j])) { // check if next chars are lowercase
                    // do nothing
                }
            else {
                title[j] = tolower(title[j]);
            }
        }
        
    }
    // check if there is spaces
    for (int s = 1; s < title.length(); s++) {
        if (title[s] == ' ') {
            title[s+1] = toupper(title[s+1]); // if space the next char is Uppercase
        }
    }
    
    //cout << title;
    
  
    // -----------------------------------
    // if numBooks = 0 return -3;
    if (numBooks == 0) {
        cout << "aaa" << endl;
        return -3;
    }
    
    // if there are 0 usernames in the array return -3
    int user_count = 0;
    
    for (int i = 0; i < numUsers; i++) {
        
        string original_user = users[i].getUsername();
                string newstr_user = "";
                for (int m = 0; m < original_user.length() ; m ++) {
                    newstr_user += tolower(original_user[m]);
                }    
            
            
        if (newstr_user == username) { // here
            users[i].setUsername(username); // here
            user_count++;
            
            int j = 0;
            while ( j < numBooks) {
                
                string original = books[j].getTitle();
                string newstr = "";
                for (int k = 0; k < original.length() ; k ++) {
                    newstr += tolower(original[k]);
                }
                
                
                if(newstr != title) {  // here
                    j++;
                }
                else {
                        break;

                }
            if (j == numBooks) {
                cout << "bbb" << endl;
                return -3;
            }
                
                
            }
            
            // getRating at index i
            int rating = users[i].getRatingAt(j); // here
            return rating;  
            }
            
        else {
            if (newstr_user != username) {  // here
                // do nothing
            }
            if (newstr_user != username && i == numUsers - 1) {  // here
                cout << "ccc" << endl;
                return -3;
            }
            
        }
    
    }
    
    if (user_count == 0) { // if zero usernames in user array
        cout << "ddd" << endl;
        return -3;
    }


}


/*
int Library::getCountReadBooks(string s) {
    /* Takes a string (username) and returns the number
of books read by that user as an integer. 



}
void Library::viewRatings(string s) {
    /*  Takes a string (username) and prints all the books
a user has provided ratings for. 
}
double Library::calcAvgRating(string s) {
    /* Takes a string (the title of a book) and returns the
average rating of the specified book as a double 
}
int Library::addUser(string s) {
    /*  Takes a string (username) and returns an integer 1
if the user is successfully added, 0 if the username
already exists in the users array and -2 if the users
array is already full.  
}
int Library::checkOutBook(string s, string t, int a) {
    /*  Takes two strings and an integer for username, title
of book, and a new rating, respectively (in this
order). Returns an integer 1 if the rating is
successfully updated, -4 if the rating value is not
valid and -3 if the rating value is valid, but the user
or title does not exist in the database.
}
void Library::getRecommendations() {
    /*Takes a string username and prints the first 5 book
recommendations from the most similar (other)
user. 
}
*/