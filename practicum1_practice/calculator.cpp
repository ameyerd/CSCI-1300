#include <iostream>
#include <iomanip>
using namespace std;


void calculator(double a, double b, char c) {
    
    switch(c) {
        case '+': cout << a << " + " << b << " = " << a+b;
        break;
        case '-': cout << a << " - " << b << " = " << a-b;
        break;
        case '*': cout << a << " * " << b << " = " << a*b;
        break;
        case '/': cout << a << " / " << b << " = " << fixed << setprecision(2) << a/b;
        break;
        default: cout << "Invalid Operator!";
    }

}

int main() {
    calculator(2,5,'+');
}