#include <iostream>
using namespace std;


void DayOfWeek(int day) {
    if (day == 1) {
        cout << "MONDAY";
    }
    else if (day == 2 || day == 3 || day == 4) {
        cout << "WORKDAY";
    }
    else if (day == 5) {
        cout << "FUNDAY";
    }
    else if (day == 6 || day == 0) {
        cout << "SLEEPDAY";
    }
    else {
        cout << "INVALID";
    }
    
}

int main() {
    DayOfWeek(2);
}