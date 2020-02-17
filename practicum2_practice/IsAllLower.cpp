#include <iostream>
using namespace std;


bool IsAllLower(string s) {
    if (s == "") {
        return true;
    }
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 97 && s[i] <= 122) {
            j++;
        }
        else {
            return false;
        }
    }
    if (j == s.length()) {
        return true;
    }
    
}

int main() {
    
    cout << IsAllLower("OneTwo") << endl;
    cout << IsAllLower("onetwo") << endl;
    cout << IsAllLower("onetwoT") << endl;
    cout << IsAllLower("$@#$@#") << endl;
}