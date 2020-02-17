#include <iostream>
using namespace std;

int CountUpper(string s) {
    if (s == "") {
        return -1;
    }
    
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            count++;
        }
    }
    if (count == 0) {
        return -2;
    }
    else {
        return count;
    }
}

int main() {
    
    cout << CountUpper("ALL the BEST");
}