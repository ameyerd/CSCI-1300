// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//////////////////////////////////////////////////////////////////////////////////
// -- book class
//////////////////////////////////////////////////////////////////////////////////

class Book {
    public:
        Book();  // default constructor
        Book(string, string);  // parameterized constructor
        string getTitle();
        void setTitle(string);
        string getAuthor();
        void setAuthor(string);
    private: // cannot be accessed by outside
        string title;
        string author;

};

//book.cpp
Book::Book() {

}
Book::Book(string title, string author) {
    this->title = title;
    this->author = author;
}
void Book::setTitle(string title) {
    this->title = title;
}
string Book::getTitle() {
    return title;
}
void  Book::setAuthor(string author) {
    this->author = author;
}
string Book::getAuthor() {
    return author;
}



//////////////////////////////////////////////////////////////////////////////////
// -- user class
//////////////////////////////////////////////////////////////////////////////////

class User {
    public:
        User();  // default constructor
        User(string, int [], int);  // parameterized constructor
        string getUsername();
        void setUsername(string);
        int getRatingAt(int);
        bool setRatingAt(int, int);
        int getNumRatings();
        void setNumRatings(int);
        int getSize();
    private: // cannot be accessed by outside
        string username;
        int size;
        int ratings[50];
        int numRatings;

};

// user.cpp
User::User() {

}
User::User(string username, int rating[], int numRatings) {
    if (numRatings <= 50) {
        this->username = username;

        for (int i = 0; i < numRatings; i++) {
            ratings[i] = rating[i];
        }
        for (int i = numRatings; i < 50; i++) {
            ratings[i] = 0;
        }
        this->numRatings = numRatings;
    }

}
void User::setUsername(string name) {
    username = name;
}
string User::getUsername() {
    return username;
}
bool User::setRatingAt(int index, int value) {
    if ((value <= 5 && value >= 0) && (index < 50 && index >= 0)) {
        ratings[index] = value;
        return true;
    }
    else{
        return false;
    }

}
int User::getRatingAt(int index) {
    if (index >= 50) {
        return -1;
    }
    else {
        return ratings[index];
    }
}
void User::setNumRatings(int numRatings) {
    this->numRatings = numRatings;
}
int User::getNumRatings() {
    return numRatings;
}
int User::getSize() {
    return size;
}

//////////////////////////////////////////////////////////////////////////////////
// -- library class
//////////////////////////////////////////////////////////////////////////////////

class Library {
    public:
        Library();      // default constructor
        int getSizeBook();
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        int readBooks(string);
        void printAllBooks();
        int readRatings(string);
        int getRating(string,string);
        int getCountReadBooks(string);
        void viewRatings(string);
        double calcAvgRating(string);
        int addUser(string);
        int checkOutBook(string,string,int);
        void getRecommendations(string);
        int ssd(int,int);
    private:
        int const static sizeBook = 50;
        int const static sizeUser = 100;
        Book books[50];
        User users[100];
        int numBooks;
        int numUsers;


};

// library.cpp
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

// sets both numBooks and numUsers to value 0
Library::Library() {
    numBooks = 0;
    numUsers = 0;
}
// returns sizeBook as an integer
int Library::getSizeBook() {
    return sizeBook;
}
// returns sizeUser as an integer
int Library::getSizeUser() {
    return sizeUser;
}
// returns numBooks as an integer
int Library::getNumBooks() {
    return numBooks;
}
// returns numUsers as an integer
int Library::getNumUsers() {
    return numUsers;
}
// problem 1
// returns total number of books in book array as an integer
int Library::readBooks(string fileName) {

    ifstream fp;
    fp.open(fileName.c_str()); // open file

    if (numBooks == sizeBook) { // if array is full then return -2
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

            if (numBooks == sizeBook) { // if array is full
                break;
            }


        }


        fp.close();
        return numBooks;

        }
        else { // if file is not open
        return -1;

    }
}
// problem 2
// prints all the books stored in the books array
void Library::printAllBooks() {

    if (numBooks <= 0) { // if ther are no books in array
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

// problem 3
// Returns the total number of users in users array as an integer
int Library::readRatings(string fileName) {

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

// problem 4
// returns user’s rating for the specified book
int Library::getRating(string username, string title) {

    username = slower(username); // make username lowercase
    title = slower(title); // make title lowercase

    // if numBooks = 0 return -3;
    if (numBooks == 0) {
        return -3;
    }

    // if there are 0 usernames in the array return -3
    int user_count = 0;

    for (int i = 0; i < numUsers; i++) {

        // make a new variable making the user at index lowercase
        string newstr_user = slower(users[i].getUsername());

        if (newstr_user == username) { // if username is equal to user
            users[i].setUsername(username);
            user_count++;

            int j = 0;
            while ( j < numBooks) {

                string newstr = slower(books[j].getTitle()); // make title lowercase

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
            int rating = users[i].getRatingAt(j); // get rating
            return rating;
            }

        else {
            if (newstr_user != username) {  // loop through again
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

// problem 5
// returns the number of books read by user as an integer
int Library::getCountReadBooks(string username) {

    // go through ratings
    // if rating is not zero then increase count
    // if it is then don't do anything

    username = slower(username);
    int countbooks = 0;

    for (int i = 0; i < numUsers; i++) {

        string newstr = slower(users[i].getUsername());
        if(username == newstr) {

            for (int j = 0; j < numBooks; j++) {
                if (users[i].getRatingAt(j) != 0) { // if user has rated the book
                    countbooks++;
                }
            }
            return countbooks;
        }

        if (newstr != username) { // loop through again
                // do nothing
            }
        if (i == numUsers -1 && newstr != username) {
                return -3;
            }
    }
}

// problem 6
//prints all the books a user has provided ratings for
void Library::viewRatings(string username) {

    string username_new = slower(username);
    int countrating = 0;

    for (int i = 0; i < numUsers; i++) {

        string newstr = slower(users[i].getUsername());
        if(username_new == newstr) {

            for (int j = 0; j < numBooks; j++) {
                if (users[i].getRatingAt(j) != 0) { // if user has not rated the book
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
            if (countrating == 0) { // no rating
                cout << username << " has not rated any books yet." << endl;
            }

        }

        if (newstr != username_new) { // loop through again
                // do nothing
            }
        if (i == numUsers -1 && newstr != username_new) {
            if (countrating == 0) {
                cout << username << " does not exist." << endl;
            }
        }
    }


}

// problem 7
//returns the average rating of the specified book as a double
double Library::calcAvgRating(string title) {

    title = slower(title);

    double sum = 0;
    double readcount = 0;
    for (int i = 0; i < numBooks; i++) {

        string newstr = slower(books[i].getTitle());
        if (title == newstr) {
            // if the user rating is not equal to zero add them for that book
            for (int j = 0; j < numUsers; j++) {
                if (users[j].getRatingAt(i) != 0) {
                    sum += users[j].getRatingAt(i); // add it to sum
                    readcount++;
                }

            }
            if (readcount == 0) {
                return 0;
            }
            double avg = sum / readcount; // average calculation
            return avg;

        }
        if (title != newstr) {
            // do nothing
        }
        if (title != newstr && i == numBooks - 1) {
            return -3;
        }

    }
}

// problem 8
// returns an integer 1, if the user is successfully added, 0 if the username, already exists in the users array and -2 if the users
// array is already full
int Library::addUser(string username){

    int ratings[50];
// check if array is full first
    if (numUsers >= sizeUser) {
        return -2;
    }
    string username_new = slower(username);
    // check if user exists in the array, if so return 0
    for (int i = 0; i < numUsers; i++) {
        string newstr = slower(users[i].getUsername());
    if(username_new == newstr) {
        return 0;
    }
    }
    for (int k = 0; k < sizeBook; k++) {
        ratings[k] = 0;
    }
    users[numUsers]=User(username, ratings , sizeBook);
    numUsers++;
    return 1;
}

// problem 9
// Returns an integer 1 if the rating is
// successfully updated, -4 if the rating value is not
// valid and -3 if the rating value is valid, but the user
// or title does not exist in the database

int Library::checkOutBook(string username, string title, int new_rating) {
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

// helper function
// SSD function
// parameters: index of the two users
int Library::ssd(int user1, int user2) {
    int sum = 0;
    for(int i = 0; i < numBooks; i++) {
        int a = users[user1].getRatingAt(i); // rating 1
        int b = users[user2].getRatingAt(i); // rating 2
        int diff = (a - b) * (a - b);
        sum = sum + diff; // add diff to sum
    }
    return sum;

}

// problem 10
// prints the first 5 book
// recommendations from the most similar (other) user
void Library::getRecommendations(string username) {

    string username_new = slower(username);
    int user_index;
    int minspot;
    int min_ssd = 10000;
    int count = 0;
    int num = 5;

    // check if username exists
    for(int i = 0; i < numUsers; i++) {
        string newstr = slower(users[i].getUsername());

        if (username_new == newstr) {
            user_index = i;
            break;
        }
        if (username_new != newstr) {
            // do nothing
        }
        if (username_new != newstr && i == numUsers - 1) {
            cout << username << " does not exist." << endl;
            num++;
        }

    }

    //ssd
    if(num == 5) {
        for (int j = 0; j < numUsers; j++) {

            if (j == user_index) continue;

            if (getCountReadBooks(users[j].getUsername()) == 0) continue;

            int numb = ssd(user_index, j);

            if (numb < min_ssd) {
                min_ssd = numb;
                minspot = j; // user index


            }

        }
    }

    //reccomendations
    if (num == 5) {
        for (int k = 0; k < numBooks; k++) {

            // if user has not rated the book
            if (users[user_index].getRatingAt(k) == 0) {
                //check if the other user rating is 3,4 or 5
                if (users[minspot].getRatingAt(k) >= 3 && users[minspot].getRatingAt(k) <=5) {
                    if (count == 0) {
                        cout << "Here is the list of recommendations" << endl;
                        count++;
                    }
                    if (count > 0) {
                        cout << books[k].getTitle() << " by " << books[k].getAuthor() << endl;
                    }
                }
            }
            if (count == 0 && k == numBooks - 1) {
                cout << "There are no reccomendations for " << username << " at present" << endl;
            }

        }
    }


}
// -- library class: constructor

// -- library class: getters/setters

// -- library class: methods (and other functions)


// printAllBooks
// cout << "Here is a list of books" << endl;

// viewRatings
// cout << username << " does not exist." << endl;
// cout << username << " has not rated any books yet." << endl;
// cout << "Here are the books that "<< name << " rated" << endl;
// cout << "Title : " << title << endl;
// cout << "Rating : " << rating << endl;
// cout << "-----" << endl;

// getRecommendations
// cout << username << " does not exist." << endl;
// cout << "Here is the list of recommendations" << endl;
// cout << title << " by " << author << endl;
// cout << "There are no recommendations for " << username <<" at present."<<endl;



/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
	cout << "Select a numerical option:" << endl;
	cout << "======Main Menu=====" << endl;
	cout << "1. Read book file" << endl;
	cout << "2. Read user file" << endl;
	cout << "3. Print book list" << endl;
	cout << "4. Get rating" << endl;
	cout << "5. Find number of books user rated" << endl;
	cout << "6. View ratings" << endl;
	cout << "7. Get average rating" << endl;
	cout << "8. Add a user" << endl;
	cout << "9. Checkout a book" << endl;
	cout << "10. Get recommendations" << endl;
	cout << "11. Quit" << endl;
}


int main(int argc, char const *argv[]) {


	// temp variables
    string choice;
    string bookFileName;
    string userFileName;
    string userName, bookTitle;
    string strRating;
    Library myLib;

    // number of books and users stored in the arrays

    /*
    const static int  userArrSize = 100;
    const static int  bookArrSize = 50;

    User users[userArrSize];
    Book books[bookArrSize];
    */

    while (choice != "11") {
        displayMenu();

        // take a menu opton
        getline(cin, choice);

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);

        switch (menuChoice) {

            case 1:
                // Initialize library -- readBooks
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                //myLib.readBooks(bookFileName);

                switch(myLib.readBooks(bookFileName)) {
                    case -1: cout << "No books saved to the database." << endl;
                        break;
                    case -2: cout << "Database is already full. No books were added." << endl;
                        break;
                    case 50: cout << "Database is full. Some books may have not been added." << endl;
                        break;
                    default: cout << "Total books in the database: " << myLib.getNumBooks() << endl;
                        break;
                }


                // Use the below messages and match them to the return code.
                // readBooks returned -1
                // cout << "No books saved to the database." << endl;
                // readBooks returned -2
                // cout << "Database is already full. No books were added." << endl;
                // readBooks returned book arr size
                // cout << "Database is full. Some books may have not been added." << endl;
                // readBooks returned otherwise
                // cout << "Total books in the database: " << numBook << endl;



                cout << endl;
                break;

            case 2:
                //  Initialize user catalog -- readRatings

                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);


                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                //myLib.readRatings(userFileName);

                switch(myLib.readRatings(userFileName)) {
                    case -1: cout << "No users saved to the database." << endl;
                        break;
                    case -2: cout << "Database is already full. No users were added." << endl;
                        break;
                    case 100: cout << "Database is full. Some users may have not been added." << endl;
                        break;
                    default: cout << "Total users in the database: " << myLib.getNumUsers() << endl;
                        break;
                }


                // Use the below messages and match them to the return code.
                // readRatings returned -1
                // cout << "No users saved to the database." << endl;
                // readRatings returned -2
                // cout << "Database is already full. No users were added." << endl;
                // readRatings returned user arr size
                // cout << "Database is full. Some users may have not been added." << endl;
                // readRatings returned otherwise
                // cout << "Total users in the database: " << numUser << endl;

                cout << endl;
                break;

            case 3:
                // Display library -- printAllBooks

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                if (myLib.getNumBooks() == 0 && myLib.getNumUsers() == 0) {

                    cout << "Database has not been fully initialized." << endl;
                }
                else {
                    myLib.printAllBooks();
                }

                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;


                cout << endl;
                break;

            case 4:
                //  Get a rating -- getRating

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.

                if (myLib.getNumBooks() == 0 && myLib.getNumUsers() == 0) {
                    cout << "Database has not been fully initialized." << endl;
                }

                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		// take user name
        		else {
                    cout << "Enter username:" << endl;
                    getline(cin, userName);

                    // take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);

                    //myLib.getRating(userName, bookTitle);

                    switch( myLib.getRating(userName, bookTitle)) {
                        case 0: cout << userName << " has not rated " << bookTitle << endl;
                            break;
                        case -3: cout << userName << " or " << bookTitle << " does not exist." << endl;
                            break;
                        default: cout << userName << " rated " << bookTitle << " with " << myLib.getRating(userName, bookTitle) << endl;
                            break;
                    }
        		}


                // getRating returned 0
                // cout << userName << " has not rated " << bookTitle << endl;
                // getRating returned -3
                // cout << userName << " or " << bookTitle << " does not exist." << endl;
                // getRating returned other than 0 or -3
                // cout << userName << " rated " << bookTitle << " with " << rate << endl;

                cout << endl;
                break;

            case 5:
                // Get number of books the user has rated -- getCountReadBooks
                if (myLib.getNumBooks() == 0 && myLib.getNumUsers() == 0) {
                    cout << "Database has not been fully initialized." << endl;
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;
                else {
                    cout << "Enter username:" << endl;
                    getline(cin, userName);


                    //myLib.getCountReadBooks(userName);

                    switch(myLib.getCountReadBooks(userName)) {
                        case 0: cout << userName << " has not rated any books." << endl;
                            break;
                        case -3: cout << userName << " does not exist." << endl;
                            break;
                        default: cout << userName << " rated " << myLib.getCountReadBooks(userName) << " books." << endl;
                            break;
                    }
                }
                // getCountReadBooks returned 0
                // cout << userName << " has not rated any books." << endl;
                // getCountReadBooks returned -3
                // cout << userName << " does not exist." << endl;
                // getCountReadBooks returned other than 0 or -3
                // cout << userName << " rated " << numRated << " books." << endl;


            	cout << endl;
                break;

            case 6:
                // View user’s ratings -- viewRatings

                if (myLib.getNumBooks() == 0 && myLib.getNumUsers() == 0) {
                    cout << "Database has not been fully initialized." << endl;
                }

                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		// take user name
        		else {
                    cout << "Enter username:" << endl;
                    getline(cin, userName);

                    myLib.viewRatings(userName);
        		}
            	cout << endl;
                break;

            case 7:
                // Calculate the average rating for the book -- calcAvgRating

                if (myLib.getNumBooks() == 0 && myLib.getNumUsers() == 0) {
                    cout << "Database has not been fully initialized." << endl;
                }

                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

        		// take book title
        		else {
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);


                    //myLib.calcAvgRating(bookTitle);

                    if (myLib.calcAvgRating(bookTitle) == -3) {
                        cout << bookTitle << " does not exist." << endl;
                    }
                    else {
                        cout << "The average rating for " << bookTitle << " is " << myLib.calcAvgRating(bookTitle) << endl;
                    }

        		}
                // calcAvgRating returned -3
                // cout << bookTitle << " does not exist." << endl;
                // calcAvgRating returned other than -3
                // cout << "The average rating for " << bookTitle << " is " << avgRating << endl;

            	cout << endl;
                break;
            case 8:
                // Add a user to the database -- addUser
        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                //myLib.addUser(userName);

                switch(myLib.addUser(userName)) {
                    case 1: cout << "Welcome to the library " << userName << endl;
                        break;
                    case 0: cout << userName << " already exists in the database." << endl;
                        break;
                    case -2: cout << "Database is already full. " << userName << " was not added." << endl;
                        break;

                }
                // addUser returned 1
                // cout << "Welcome to the library " << userName << endl;
                // addUser returned 0
                // cout << userName << " already exists in the database." << endl;
                // addUser returned -2
                // cout << "Database is already full. " << userName << " was not added." << endl;

            	cout << endl;
                break;
            case 9:
                // Check out the book -- checkOutBook
                if (myLib.getNumBooks() == 0 && myLib.getNumUsers() == 0) {
                    cout << "Database has not been fully initialized." << endl;
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;
                else {
            		// take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);

                    // take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);

                    // take rating
                    cout<<"Enter rating for the book:"<<endl;
                    getline(cin, strRating);

                    int new_rating = stoi(strRating);

                    //myLib.checkOutBook(userName, bookTitle, new_rating);

                    switch(myLib.checkOutBook(userName, bookTitle, new_rating)) {
                        case 1: cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                            break;
                        case -4: cout << new_rating << " is not valid." << endl;
                            break;
                        case -3: cout << userName << " or " << bookTitle << " does not exist." << endl;
                            break;
                    }
                }
                // checkOutBook returned 1
                // cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                // checkOutBook returned -4
                // cout << strRating << " is not valid." << endl;
                // checkOutBook returned -3
                // cout << userName << " or " << bookTitle << " does not exist." << endl;

            	cout << endl;
                break;
            case 10:
                // get recommendations  -- getRecommendations
                if (myLib.getNumBooks() == 0 && myLib.getNumUsers() == 0) {
                    cout << "Database has not been fully initialized." << endl;
                }
                // If the database has not been initialized
                // cout << "Database has not been fully initialized." << endl;

                else {
            		// take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);

                    myLib.getRecommendations(userName);
                }

            	cout << endl;
                break;

            case 11:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
                cout << endl;
        }
    }

    return 0;
}
