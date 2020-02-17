#include <iostream>
#include <string>
#include <ctime>

using namespace std;


bool is_palindrome(string str) {
    // simplest cases
	if (str.length() <= 1) {
        return true;
    }
	// reduction step
	char first = tolower(str[0]);
	char last  = tolower(str[str.length()-1]);
	if (first==last) {
	    string shorter = str.substr(1, str.length()-2);
	    return is_palindrome(shorter);
	} else {
		return false;
	}
}


bool is_palindrome_i(string str) {
    int beg = 0;
    int end = str.length() - 1;
    while (beg < end) {
        if (str[beg] != str[end]) {
            return false;
        }
        beg++;
        end--;
    }
    return true;
}


int main() {

    cout << boolalpha; // handy manipulator to print "true"/"false" instead of 1,0 for Booleans

    cout << is_palindrome("rotor") << endl;
    cout << is_palindrome("elvis") << endl;

    // timing estimates for recursive versus iterative solutions
    string str = "rotorotorotorotor";
    int n_iter = 10000000; // because a single function call is too fast, do a whole bunch of them!
    bool out;

    int t0 = time(0);  // current time since Jan 1 1970 in seconds...
	cout << "Recursive solution: " << is_palindrome(str) << endl;
	for (int i=0; i<n_iter; i++) {out = is_palindrome(str);}
	int t1 = time(0);
    cout << "Iterative solution: " << is_palindrome_i(str) << endl;
    for (int i=0; i<n_iter; i++) {out = is_palindrome_i(str);}
    int t2 = time(0);

    cout << "Recursive solution took " << t1-t0 << endl;
    cout << "Iterative solution took " << t2-t1 << endl;

    return 0;
}