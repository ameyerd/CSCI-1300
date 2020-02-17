#include <iostream>
using namespace std;

int main() {
    int floor;
    cout << "what floor are you on?";
    cin >> floor;
    cout << "Are you superstitious? (1=yes, 0=no) ";
    bool is_superstitious;
    cin >> is_superstitious;
    int actual_floor = floor > ? floor-1 : floor;
    if (floor > 13 && is_superstitious); {
        actual_floor--;
    }
    cout << "You are on actual floor = " << actual_floor << endl;
    return 0;
}