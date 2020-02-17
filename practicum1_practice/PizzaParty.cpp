#include <iostream>
using namespace std;


double PizzaParty(int pizzas, double cost, double discount) {
    if (pizzas < 10) {
        cost = (pizzas * cost) + 10;
    }
    else {
        cost = pizzas * (cost - (discount * cost));
    }
    return cost;
}



int main() {
    cout << PizzaParty(10, 10, 0.1);
}