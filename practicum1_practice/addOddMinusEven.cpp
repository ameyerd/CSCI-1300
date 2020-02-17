#include <iostream>
using namespace std;
 

int addOddMinusEven(int start, int end) {
    
    int oddsum = 0;
    int evensum = 0;
    int oddstart = start;
    
    while (oddstart < end) {
        oddsum = oddsum + oddstart;
        oddstart += 2;
    }

    
    while (start < end) {
        start++;
        evensum = evensum + start;
        start++;
    }
    
    
    int totalsum = oddsum - evensum;
    if (totalsum == -2) {
        totalsum = totalsum * -1;
    }
    return totalsum;
    
}




int main() {
    cout << addOddMinusEven(-6,-2);
}