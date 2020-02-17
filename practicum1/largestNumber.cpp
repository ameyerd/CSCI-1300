#include <iostream>
using namespace std;

double largestNumber(double a, double b, double c) {
    
    double largest;
    
    if (a > b && a > c)
    {
        largest = a;
    }
    else if (b > a && b > c)
    {
        largest = b;
    }
    else if (c > a && c > b)
    {
        largest = c;
    }
    else if (a > b && a == c)
    {
        largest = a;
    }
    else if (b > c && b == a)
    {
        largest = b;
    }
    else if (c > a && c == b)
    {
        largest = c;
    }
    else if (a == b && b == c)
    {
        largest = a;
    }
    
    return largest;
}


int main() {
    cout << largestNumber(1,16,16.0);
}