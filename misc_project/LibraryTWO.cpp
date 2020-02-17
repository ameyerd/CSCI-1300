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

// to lower function
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
  
    username = slower(username);
    title = slower(title);
    // -----------------------------------
    // if numBooks = 0 return -3;
    if (numBooks == 0) {
        return -3;
    }
    
    // if there are 0 usernames in the array return -3
    int user_count = 0;
    
    for (int i = 0; i < numUsers; i++) {
        
        string newstr_user = slower(users[i].getUsername());

        if (newstr_user == username) { // here
            users[i].setUsername(username); // here
            user_count++;
            
            int j = 0;
            while ( j < numBooks) {
                
                string newstr = slower(books[j].getTitle());

                if(newstr != title) {  // here
                    j++;
                }
                else {
                        break;

                }
            if (j == numBooks) {
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
                return -3;
            }
            
        }
    
    }
    
    if (user_count == 0) { // if zero usernames in user array
        return -3;
    }


}


int Library::getCountReadBooks(string username) {
    /* Takes a string (username) and returns the number
of books read by that user as an integer. */
    //string username1 = slower(username);
    
    // go through ratings
    // if rating is not zero then increase count
    // if it is then don't do anything
    
    username = slower(username);
    int countbooks = 0;
    
    for (int i = 0; i < numUsers; i++) {
        
        string newstr = slower(users[i].getUsername());
        if(username == newstr) {
            
            for (int j = 0; j < numBooks; j++) {
                if (users[i].getRatingAt(j) != 0) {
                    countbooks++;
                }
            }
            return countbooks;
        }
        
        if (newstr != username) {
                // do nothing
            }
        if (i == numUsers -1 && newstr != username) {
                return -3;
            }
    }
}

void Library::viewRatings(string username) {
    /*  Takes a string (username) and prints all the books
a user has provided ratings for. */
    string username_new = slower(username);
    int countrating = 0;
    
    for (int i = 0; i < numUsers; i++) {
        
        string newstr = slower(users[i].getUsername());
        if(username_new == newstr) {
            
            for (int j = 0; j < numBooks; j++) {
                if (users[i].getRatingAt(j) != 0) {
                    if (countrating == 0) {
                        cout << "Here are the books that " << username << " rated." << endl;
                        cout << "Title: " << books[j].getTitle() << endl;
                        cout << "Rating: " << users[i].getRatingAt(j) << endl;
                        cout << "-----" << endl;
                    }
                    else if (countrating > 0) {
                        cout << "Title: " << books[j].getTitle() << endl;
                        cout << "Rating: " << users[i].getRatingAt(j) << endl;
                        cout << "-----" << endl;
                    }
                    countrating++;
                    
                }
            }
            if (countrating == 0) {
                cout << username << " has not rated any books yet." << endl;
            }

        }
        
        if (newstr != username_new) {
                // do nothing
            }
        if (i == numUsers -1 && newstr != username_new) {
            if (countrating == 0) {
                cout << username << " does not exist." << endl;
            }
        }
    }
    

}


double Library::calcAvgRating(string title) {
    /* Takes a string (the title of a book) and returns the
average rating of the specified book as a double */
    title = slower(title);
    
    double sum = 0;
    double readcount = 0;
    for (int i = 0; i < numBooks; i++) {
        
        string newstr = slower(books[i].getTitle());
        if (title == newstr) {
            // if the user rating is not equal to zero add them for that book
            for (int j = 0; j < numUsers; j++) {
                if (users[j].getRatingAt(i) != 0) {
                    sum += users[j].getRatingAt(i);
                    readcount++;
                }
                
            }
            if (readcount == 0) {
                return 0;
            }
            double avg = sum / readcount;
            return avg;
   
        }
        if (title != newstr) {
            
        }
        if (title != newstr && i == numBooks - 1) {
            return -3;
        }

    }
}


int Library::addUser(string username) {
    /*  Takes a string (username) and returns an integer 1
if the user is successfully added, 0 if the username
already exists in the users array and -2 if the users
array is already full.  */
    int ratings[50];
    // check if array is full first
    if (numUsers == sizeUser) {
        return -2;
    }
    string username_new = slower(username);
    // check if user exists in the array, if so return 0
    if (numUsers == 0) {
        for (int k = 0; k < numBooks; k++) {
                    ratings[k] = 0;
                }
                
        users[numUsers]=User(username, ratings , sizeBook);
        numUsers++;
        return 1;
    }
    for (int i = 0; i < numUsers; i++) {
        string newstr = slower(users[i].getUsername());
        
        if(username_new == newstr) {
            return 0;
        }
        if (username_new != newstr) {
            
            }
        if (username_new != newstr && i == numUsers - 1) {
            for (int k = 0; k < numBooks; k++) {
                    ratings[k] = 0;
                }
                
            users[numUsers]=User(username, ratings , sizeBook);
            numUsers++;
            return 1;
        }
            
    }
        
}
  


int Library::checkOutBook(string username, string title, int new_rating) {
    /*  Takes two strings and an integer for username, title
of book, and a new rating, respectively (in this
order). Returns an integer 1 if the rating is
successfully updated, -4 if the rating value is not
valid and -3 if the rating value is valid, but the user
or title does not exist in the database. */
    // check if rating is valid
    
    username = slower(username);
    title = slower(title);
    if (new_rating >= 0 && new_rating <= 5) {
        for (int i = 0; i < numUsers; i++) {
            
            // check if username exists
            string newstr = slower(users[i].getUsername());
            if (username == newstr) {
                // check if title exists
                for (int j = 0; j < numBooks; j++) {
                    string new_title = slower(books[j].getTitle());
                    if (title == new_title) {
                        // here
                        users[i].setRatingAt(j, new_rating);
                        return 1;
                        
                    }
                    if (title != new_title) {
                        // do nothing
                    }
                    if (title != new_title && j == numBooks -1) {
                        return -3;
                    }
                }

            }
            if (username != newstr) {
                // do nothing
            }
            if (username != newstr && i == numUsers - 1) {
                return -3;
            }
            
        }
        
    }
    else {
        return -4;
    }

}

// SSD function
// parameters: index of the two users
int Library::ssd(int user1, int user2) {
    int sum = 0;
    for(int i = 0; i < numBooks; i++) {
        int a = users[user1].getRatingAt(i);
        int b = users[user2].getRatingAt(i);
        int diff = (a - b) * (a - b);
        sum = sum + diff;
    }
    return sum;
    
}


void Library::getRecommendations(string username) {
    /*Takes a string username and prints the first 5 book
recommendations from the most similar (other) user.  */
    string username_new = slower(username);
    int count = 0;
    int minspot = 0;
    
    int min_ssd; // here
    for(int i = 0; i < numUsers; i++) {
        string newstr = slower(users[i].getUsername());
        
        if (username_new == newstr) 
        {
            cout << "YESS USER EXISTS!!" << endl;
            int user_index = i; // index of given username
            // here
            // go through each user and calculate the ssd compared to give user
            // make a variable and update it each time it's lower than or equal to the ssd
            // of the given user
            int j;
            for(j = 0; j < numUsers; j++) {
                 // here
                if (j == user_index) continue;
                
                if (getCountReadBooks(users[j].getUsername()) == 0) continue;
                
                int num = ssd(user_index, j);
                
                if (num < min_ssd) {
                    min_ssd = num;
                    minspot=j;
                
                    cout << "ssd: " << min_ssd << endl;
                    break;
                }
                cout << minspot << endl;
            }
            
            // get user of index j ratings that are either 3, 4 or 5 that user1 has not rated (0)
            for (int k = 0; k < numBooks; k++) {
            
                if (users[user_index].getRatingAt(k) == 0) {
        
                    if (count == 0) {
                        if (users[minspot].getRatingAt(k) == 3 || users[minspot].getRatingAt(k) == 4 || users[minspot].getRatingAt(k) == 5) {
                            cout << "Here are the list of recommendations" << endl;
                            //cout << books[k].getTitle() << " by " <<  books[k].getAuthor() << endl;
                            count ++;
                        }
                    }
                    if (count > 0) {
                        if (users[minspot].getRatingAt(k) == 3 || users[minspot].getRatingAt(k) == 4 || users[minspot].getRatingAt(k) == 5) {
                            cout << books[k].getTitle() << " by " <<  books[k].getAuthor() << endl;

                        }
                    }
                    if (count == 5) {
                        break;
                    }
                    
                    
                    
                }
                //if (users[i].getRatingAt(k) != 0) {
                    // do nothing
                //}
                if (count ==0 && k == numBooks - 1) {
                    cout << "There are no recommendations for " << username << " at present" << endl;
                }
            }

        }
        
        if (username_new != newstr) {
            // do nothing
        }
        if (username_new != newstr && i == numUsers) {
            cout << username << " does not exist." << endl;
        }
        
        
    }
    
    
    

}
