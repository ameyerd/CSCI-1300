#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Please enter your name (first, then last): ";
    string fname, lname;
    cin >> fname >> lname;
    cout << "The name you entered was " << fname << " " << lname << ", right?" << endl;

    // Try again!
    /*
    cout << "Name plz: ";
    string fname, lname;
    cin >> fname >> lname;
    cout << "The name you entered was " << fname << " " << lname << ", right?" << endl;
    */

    return 0;
}
