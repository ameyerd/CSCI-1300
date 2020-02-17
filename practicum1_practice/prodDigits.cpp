#include <iostream>
using namespace std;

int prodDigits(int num) {
    
    int sum;
    int numd;

    if (num < 10) {
        numd = 1;
    }
    if (num >= 10 && num < 100) {
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

    
    
    
    if (numd == 1) {
        sum = num;
    }
    else if (numd == 2) {
        int b = num / 10 % 10;
        int a = num % 10;
        sum = a*b;
    }
    else if (numd == 3) {
        int c = num / 100 % 10;
        int b = num / 10 % 10;
        int a = num % 10;
        sum = a*b*c;
    }
    else if (numd == 4) {
        int d = num / 1000 % 10;
        int c = num / 100 % 10;
        int b = num / 10 % 10;
        int a = num % 10;
        sum = a*b*c*d;
    }
    else if (numd == 5) {
        int e = num / 10000 % 10;
        int d = num / 1000 % 10;
        int c = num / 100 % 10;
        int b = num / 10 % 10;
        int a = num % 10;
        sum = a*b*c*d*e;
    }
    else if (numd == 6) {
        int f = num / 100000 % 10;
        int e = num / 10000 % 10;
        int d = num / 1000 % 10;
        int c = num / 100 % 10;
        int b = num / 10 % 10;
        int a = num % 10;
        sum = a*b*c*d*e*f;
    }
  
    return sum;
}



int main() {
    cout << prodDigits(1456);
}