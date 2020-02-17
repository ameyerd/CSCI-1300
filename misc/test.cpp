#include <iostream>
using namespace std;

void printOddNums(int max) {
    int num = 1;
   // if max is an even number
   if (max%2 == 0) {
       while (num <= max) {
           num++;
           cout << num << endl;
           num ++;
       }
   }
   // if max is an odd number
   else {
       if (max%2 != 0) {
       while (num <= max) {
           cout << num << endl;
           num += 2;
                }
            }
        }
}

int main() {
    // test 1
    // expected output
    // 2 4 6 8 10
    printOddNums(10);
    
    // test 2
    // expected output
    // 1 3 5 7 9 11
    printOddNums(11);
}