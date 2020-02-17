#include <iostream>
#include "Player.h"
using namespace std;

int main() {
    
    // g++ playerDriver.cpp Player.cpp
    
    Player stella;
    cout << stella.getName() << endl;
    cout << stella.getPoints() << endl;
    stella.setName("Stella");
    stella.setPoints(13.1);
    cout << stella.getName() << endl;
    cout << stella.getPoints() << endl;
    
    cout << "-----------" << endl;
    
    Player hector("Hector", 6.2);
    cout << hector.getName() << endl;
    cout << hector.getPoints() << endl;
    
}