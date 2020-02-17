#include <iostream>
using namespace std;

string removeStars(string s) {
    
    string r = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 42) {
            r = r + s[i];
        }
    }
    return r;
}

int main() {
    cout << removeStars("HelloWorld***");
}