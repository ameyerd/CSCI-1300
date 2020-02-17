#include <iostream>
using namespace std;

double CoffeeCost(int num, double price) {
    int freecups = num / 12;
    double cost;
    
    if (num == 12) {
        cost = num * price;
    }
    
    else {
        num = num - freecups;
        cost = num * price;
    }
    return cost;
}

int main() {
    cout << CoffeeCost(7,2);
}