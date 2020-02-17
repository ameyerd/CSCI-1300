#include <iostream>
#include <string>
using namespace std;

string ReplaceHashTag(string s) {
    
    for (int i= 0; i < s.length(); i++) {
        if (s[i] == 35) {
            s[i] = 64;
        }
    }
    return s;
    
}

int main() {
    
    cout << ReplaceHashTag("#Skobuffs, #lol");
}