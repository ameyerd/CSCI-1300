#include <iostream>
using namespace std;

string foo(int pos,string input) {
    if (pos < 0) 
        return "";
    return input[pos] + foo(pos -1, input);
}

int main() {
    string input = "Hello, World!";
    cout << foo(input.length() - 1, input) << endl;
    return 0;
}