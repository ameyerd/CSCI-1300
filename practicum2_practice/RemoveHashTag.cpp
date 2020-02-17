#include <iostream>
#include <string>
using namespace std;

string RemoveHashTag(string s) {
    
    string r = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 35) {
            r = r + s[i];
        }
    }
    return r;
    
}

int main() {
    
    cout << RemoveHashTag("#Sko buffs, #lol");
}