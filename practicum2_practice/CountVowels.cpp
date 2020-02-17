#include <iostream>
using namespace std;

int CountVowels(string s) {
    
    if (s == "") {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 65 || s[i] == 97 || s[i] == 69 || s[i] == 101 || s[i] == 79 || s[i] == 111 || s[i] == 73 || s[i] == 105 || s[i] == 85 || s[i] == 117) {
            count++;
        }
        else {
            count = count;
        }
    }
    return count;
}

int main() {
    
    cout << CountVowels("One1, Two2") << endl;
}