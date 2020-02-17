#include <iostream>
using namespace std;

void numberDigits(int num) {
    
    int numd;
    
    if (num < 0) {
        num = num * -1;
    }


    if (num < 10) {
        numd = 1;
    }
    else if (num >= 10 && num < 100) {
        numd = 2;
    }
    else if (num >= 100 && num < 1000) {
        numd = 3;
    }
    else if (num >= 1000 && num < 10000) {
        numd = 4;
    }
    else if (num >= 10000 && num < 100000) {
        numd = 5;
    }
    else if (num >= 100000 && num < 1000000) {
        numd = 6;
    }
    else if (num >= 1000000 && num < 10000000) {
        numd = 7;
    }
    else if (num >= 10000000 && num < 100000000) {
        numd = 8;
    }
    else if (num >= 1000000000 && num < 10000000000) {
        numd = 9;
    }
    else if (num >= 10000000000 && num < 100000000000000) {
        numd = 10;
    }
    
    cout << "The number " << num << " has " << numd << " digits." << endl;
}


int main() {
    numberDigits(-99999);
}