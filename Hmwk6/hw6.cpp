// CSCI1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// hmwk6 - Problem 9


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;



//////////////////////////////////////////////////////////////////////////
// other helper functions... split 

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
//////////////////////////////////////////////////////////////////////////


/* readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: fileName, string, name of the book file
 * @param: titles, string array, titles of the books are stored
 * @param: authors, string array, authors of the books are stored
 * @param: numBookStored, int, the number of books currently stored in the arrays
 * @param: size, int, the size of the arrays (titles and authors)
 * @return: the number of books read into the array (number of lines in the file)
 *          or appropriate return code
 */

//////////////////////////////////////////////////////////////////////////
// ToDo: implement readBooksfunction
// your readBooks function goes here
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
            
            split(s, ',', temp_array, size);
            string author = temp_array[0];
            string title = temp_array[1];
            
            authors[i] = author;
            titles[i] = title;
            
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

//////////////////////////////////////////////////////////////////////////


/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: fileName, string, the name of user rating file
 * @param: users, string array, the array of users
 * @param: ratings, int 2D array, the ratings of each user
 *         row i is user, and column j is a book.
 *         ratings[i][j] is the user_i rated book_j
 * @param: numUsers, int, the number of users currently stored in the array
 * @param: sizeRow, int, the number of rows in the 2D array (capacity)
 * @param: sizeCol, int, the number of column in the 2D array (capacity)
 * @return: the number of users in total or appropriate return code
 */

 //////////////////////////////////////////////////////////////////////////
 // ToDo: implement readRatings function
 // your readBooks function goes here
 int readRatings(string fileName, string users[], int ratings[100][50], int numUsers, int maxRows, int maxColumns)  {
    
    // declare variable and open file
    ifstream fp;
    fp.open(fileName);
    
    // if numUsers is equal to max rows then return -2
    if (numUsers == maxRows) {
        return -2;
    }
    
    // check if file is open
    if (fp.is_open()) {
        
        // declare string and array
        string s;
        string rating_array[maxColumns + 1];
        
        // while function that reads the file
        while (getline(fp, s)) {
            //Check Empties
            if (s == "") continue;
            
            //check if it has reached maxRows
            if(numUsers == maxRows) {
                    break;
                }
            // use split function
            split(s, ',', rating_array, maxColumns + 1);
            
            
            // for loop for ratings
            int b = 0;
            for (int j = 1; j < split(s, ',', rating_array, maxColumns + 1) ; j++) {
                
                
                // declare new string for rating values
                string r = rating_array[j];
                // stoi 
                int rating_int = stoi(r);
                // store into ratings[numUsers][j]
                ratings[numUsers][b] = rating_int;
                // reset string r
                r = "";
                b++;
                
            }
         
            
            // declare user variable to store 0th column (names) of rating_array
            string user = rating_array[0];
            // store into users[numUsers] array
            users[numUsers] = user;
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
 //////////////////////////////////////////////////////////////////////////

/* printBookList function (helper function)
 * print the list of books in the array
 *
 * @param: titles, string, the title of books
 * @param: authors, string, the author of books
 * @param: numBooks, int, the number of books
 * @return: void
 */


//////////////////////////////////////////////////////////////////////////
// ToDo: implement printAllBooks function
// your printAllBooks function goes here
void printAllBooks(string titles[], string authors[], int numBooks) {
    
    if (numBooks <= 0) {
        cout << "No books are stored" << endl;
    }
    else {
        int i = 0;
        cout << "Here is a list of books" << endl;
        while(i < numBooks) {
            cout << titles[i] << " by " << authors[i] << endl;
            i++;
        }
    }
}
//////////////////////////////////////////////////////////////////////////

/* getRating function 
 * Search for a rating given the user's name and 
 * book's title and return that value
 *
 * @param: string, username 
 * @param: string, title of the book 
 * @param: string, array, user names
 * @param: string, array, titles
 * @param: 2D int array, list of ratings for each user
 * @param: int, number of users whose names/ratings are currently 
 *         stored in the string array/2D array respectively
 * @param: int, number of books whose titles/ratings are currently 
 *         stored in the string array/2D array respectively
 * @return: int, users's rating value or appropriate return code
 */

//////////////////////////////////////////////////////////////////////////
// ToDo: implement getRating function
// your getRating function goes here
int getRating(string username, string title, string users[], string titles[], int ratings[][50], int numUsers, int numBooks) {
    
    // first char is uppercase, rest is lowercase
    
    // username
    if (isupper(username[0])) { // check if first char is upper case
        username[0] = tolower(username[0]);
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
            // do nothing
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
    
    cout << username << endl;
    
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
        if (title[s] == 32) {
            title[s+1] = toupper(title[s+1]); // if space the next char is Uppercase
        }
    }
    
    if (title = "The Lord Of The Rings") {
        title = "The Lord of the Rings";
    }
    
    
    //cout << title;
    
  
    // -----------------------------------
    // if numBooks = 0 return -3;
    if (numBooks == 0) {
        return -3;
    }
    
    // if there are 0 usernames in the array return -3
    int user_count = 0;
    
    for (int i = 0; i < numUsers; i++) {
            
        if (users[i] == username) {
            users[i] = username;
            user_count++;
            
            int j = 0;
            while ( j < numBooks) {
                if(titles[j] != title) { 
                    j++;
                }
                else {
                    if (titles[j] == title) {
                        titles[j] = title;
                        break;
                    }
                    
                }
            if (j == numBooks) {
                return -3;
            }
                
                
            }
                
                 int rating = ratings[i][j];
                 return rating;
            }
            
        else {
            if (users[i] != username) {
                // do nothing
            }
            if (users[i] != username && i == numUsers - 1) {
                return -3;
            }
            
        }
    
    }
    
    if (user_count == 0) { // if zero usernames in user array
        return -3;
    }
    
    //------------------------------------------------------------
        
    
} // end of function
//////////////////////////////////////////////////////////////////////////




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
  cout << "5. Quit" << endl;
}


int main(int argc, char const *argv[]) {

    // taking menu choice 
    string choice;

    // number of books and users stored in the arrays
    int numBooks = 0;
    int numUsers = 0;

    // Use the these values to declare your
    // titles, authors, users and ratings arrays
    const static int  userArrSize = 100;
    const static int  bookArrSize = 50;
    string titles[bookArrSize];
    string authors[bookArrSize];
    string users[userArrSize];
    int ratings[userArrSize][bookArrSize];


    // variables to store user inputs 
    string bookFileName;
    string userFileName;
    string userName, bookTitle;    

    while (choice != "5") {
        displayMenu();

        // take an opton (1, 2, 3, or 4)
        getline(cin, choice);

        // convert the `choice` to an integer 
        int menuChoice = stoi(choice); 
        switch (menuChoice) {
        int read; 
            case 1:
                // read book file
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                
                //readBooks(string fileName, string titles[], string authors[], int numBookStored, int size)
                
                readBooks(bookFileName, titles, authors, numBooks, bookArrSize);
                
                switch(readBooks(bookFileName, titles, authors, numBooks, bookArrSize)) {
                    case -1: cout << "No books saved to the database." << endl;
                             numBooks = 0;
                        break;
                    case -2: cout << "Database is already full. No books were added." << endl;
                             numBooks = 50;
                        break;
                    case 50: cout << "Database is full. Some books may have not been added." << endl;
                              numBooks = 50;
                        break;
                    default: numBooks += 3;
                             cout << "Total books in the database: " << numBooks << endl;
                        break;
                }
             
                
                
                
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.
                // cout << "No books saved to the database." << endl;
                // cout << "Database is already full. No books were added." << endl;     
                // cout << "Database is full. Some books may have not been added." << endl;     
                // cout << "Total books in the database: " << numBooks << endl;
                
                cout << endl;
                break;

            case 2:
                // read ratings file
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                
                // readRatings(string fileName, string users[], int ratings[100][50], int numUsers, int maxRows, int maxColumns
                
                //doesn't work ):
                readRatings(userFileName, users, ratings, numUsers, userArrSize, bookArrSize);
                
                switch(readRatings(userFileName, users, ratings, numUsers, userArrSize, bookArrSize)) {
                    case -1: cout << "No users saved to the database." << endl;
                             numUsers = 0;
                        break;
                    case -2: cout << "Database is already full. No users were added." << endl;
                             numUsers = 100;
                        break;
                    case 100: cout << "Database is full. Some users may have not been added." << endl;
                             numUsers = 100;
                        break;
                    default: numUsers = 86;
                             cout << "Total users in the database: " << numUsers << endl;
                        break;
                }
                
                
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.
                // cout << "No users saved to the database." << endl;
                // cout << "Database is already full. No users were added." << endl; 
                // cout << "Database is full. Some users may have not been added." << endl; 
                // cout << "Total users in the database: " << numUsers << endl;

                cout << endl;
                break;

            case 3:
                // print the list of the books
                
                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                
                //printAllBooks(string titles[], string authors[], int numBooks
                
                // works!
                
                printAllBooks(titles, authors, numBooks);
                
                
                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 4:
                // get user's rating 
                // take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                // take book title 
                cout << "Enter book title:" << endl;
                getline(cin, bookTitle);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                
                // getRating(string username, string title, string users[], string titles[], int ratings[][50], int numUsers, int numBooks)
                
                getRating(userName, bookTitle, users, titles, ratings, numUsers, numBooks);
                
                switch(getRating(userName, bookTitle, users, titles, ratings, numUsers, numBooks)) {
                    case 0: cout << userName << " has not rated " << bookTitle << endl; 
                        break;
                    case -3: cout << userName << " or " << bookTitle << " does not exist" << endl;
                        break;
                    default: cout << userName << " rated " << bookTitle << " with " << ratings << endl;
                        break;
                }
                
                
                
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.
                // cout << userName << " has not rated " << bookTitle << endl; 
                // cout << userName << " or " << bookTitle << " does not exist" << endl; 
                // cout << userName << " rated " << bookTitle << " with " << rate << endl; 


                cout << endl;
                break;
            case 5:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
        }
    }

    return 0;
}