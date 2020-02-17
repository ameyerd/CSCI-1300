#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Check on how the numerical values of characters compare!
    char c1 = 'a';
    char c2 = 'b';
    if (c1 > c2) {
        cout << "c1 > c2" << endl;
    } else if (c2 > c1) {
        cout << "c2 > c1"  << endl;
    }

    // Can we confirm that they have the proper numerical values?
    // --> confirm this with the ASCII table in the slides!
    int num = 0;
    cout << c1 + num << endl;
    cout << static_cast<int>(c1) << endl;

    return 0;
}