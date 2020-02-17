#include <iostream>
using namespace std;


void LeavesPerTree(double pounds) {
    double lastyear = 10000;
    
    double currentyear = (pounds / .001) / 1031;
    cout << currentyear << endl;
    
    if (currentyear > lastyear) {
        cout << "More leaves than last year";
    }
}


int main() {
    LeavesPerTree(10000);
}