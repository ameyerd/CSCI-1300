#include <iostream>
using namespace std;

double GasBill(int num) {
    double cost;
    
    if (num < 0) {
        cout << "Incorrect input" << endl;
        return 0;
    }
    
    if (num < 100) {
        cost = num * 1.23;
    }
    else if (num >= 100 && num < 200) {
        int c = num - 100;
        cost = 100 * 1.23 + c * 1.14;
    }
    else if (num >= 200) {
        int d = num - 200;
        cost = 100 * 1.23 + 100 * 1.14 + d * 1.08;
    }
    return cost;
    
}

int main() {
    cout << GasBill(150);
}