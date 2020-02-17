#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Book.h"
#include "Library.h"
using namespace std;


int main () {
    
    //g++ libraryDriver.cpp Library.cpp User.cpp Book.cpp -std=c++11
    
    // g++ libraryDriver.cpp LibraryTWO.cpp User.cpp Book.cpp -std=c++11
    
    // g++ libraryDriver.cpp LibraryTHREE.cpp User.cpp Book.cpp -std=c++11
    
    /*
    // make library object
    Library myLibrary;
    // call readBooks
    int rv = myLibrary.readBooks("fileName.txt");
    // print values
    cout << "rv = " << rv << endl;
    cout << "numBooks = ";
    cout << myLibrary.getNumBooks() << endl;
    // print books
    myLibrary.printAllBooks();
    */
    
    /*
    // make library obj
    Library lib;
    // read book file
    lib.readBooks("bookFile.txt");
    // call readRatings and check return values
    int rv1 = lib.readRatings("ratings.txt");
    cout << "rv1 = ";
    cout << rv1 << endl;
    // check value of getNumUsers
    cout << "numUsers = ";
    cout << lib.getNumUsers() << endl;
    // print user’s ratings
    
    string name = "Ninja";
    cout << lib.getRating(name, "book1") << endl;
    cout << lib.getRating(name, "book2") << endl;
    cout << lib.getRating(name, "book3") << endl;
    cout << lib.getRating(name, "book4") << endl;
    cout << lib.getRating(name, "book5") << endl;
    */
    
    
    /*
    // make library obj
    Library lib;
    // call readRatings and check return values
    int rv1 = lib.readRatings("ratings.txt");
    cout << "rv1 = " << rv1 << endl;
    int rv2 = lib.readRatings("ratingFile2.txt");
    cout << "rv2 = " << rv2 << endl;
    // check value of getNumBooks
    cout << "numUsers = ";
    cout << lib.getNumUsers() << endl;
    */
    
    
    /*  testing getrating
    Library myLibrary;
    myLibrary.readBooks("bookFile.txt");
    
    myLibrary.readRatings("ratingsFile.txt");
    
    cout << myLibrary.getRating("User4", "Title1") << endl;
    */
    
    /*
    Library myLibrary;
    //add books to Library
    myLibrary.readBooks("bookFile.txt");
    //add users
    myLibrary.readRatings("ratingFile.txt");
    // viewRatings for User2
    cout << myLibrary.getCountReadBooks("User1") << endl;
    */
    /*
    //Create a new Library
    Library myLibrary;
    //add books to Library
    myLibrary.readBooks("bookFile.txt");
    //add users
    myLibrary.readRatings("ratingFile.txt");
    myLibrary.viewRatings("User2");
    */
    
    /*
    //Create a new Library
    Library myLibrary;
    //add books to Library
    myLibrary.readBooks("bookFile.txt");
    //add users
    myLibrary.readRatings("ratingFile.txt");
    // calcAvgRating for Title2
    cout << myLibrary.calcAvgRating("Title4") << endl;
    // calcAvg test
    cout << myLibrary.calcAvgRating("Title2") << endl;
    */
    
    /*
    //Create a new Library
    Library myLibrary;
    myLibrary.readRatings("ratingFile.txt");
    // checking the user count
    cout << "numUsers = " << myLibrary.getNumUsers() << endl;
    //add users
    cout << myLibrary.addUser("User4") << endl;
    // checking the user count
    cout << "numUsers = " << myLibrary.getNumUsers() << endl;
   */
    
    /*
    //Create a new Library
    Library myLib;
    myLib.readBooks("bookFile.txt");
    myLib.readRatings("ratingFile.txt");
    
    /*
    int oldRating = myLib.getRating("User2", "Title1");
    int rv = myLib.checkOutBook("User2", "Title1", 2);
    int newRating = myLib.getRating("User2", "Title1");
    cout << "rv = " << rv << endl;
    cout << "oldRating = " << oldRating << endl;
    cout << "newRating = " << newRating << endl;
    */
    /*
    int oldRating = myLib.getRating("User2", "Title1");
    int rv = myLib.checkOutBook("User2", "Title1", 10);
    int newRating = myLib.getRating("User2", "Title1");
    cout << "rv = " << rv << endl;
    cout << "oldRating = " << oldRating << endl;
    cout << "newRating = " << newRating << endl;
    */
    /*
    int rv = myLib.checkOutBook("noUser", "Title1", 2);
    cout << "rv = " << rv << endl;
    */
    
   //Create a new Library
    Library myLib;
    myLib.readBooks("bookFile.txt");
    myLib.readRatings("ratingFile.txt");
    
    myLib.getRecommendations("User5");
    
    
    
}