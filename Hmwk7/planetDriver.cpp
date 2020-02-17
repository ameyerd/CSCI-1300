// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 1

#include <iostream>
#include "Planet.h"
using namespace std;


int main() {
    
    // in bash:  g++ planetDriver.cpp Planet.cpp
    
    // test case 1
    // expected output
    // Planet A
    // 10
    // 4188.79
    Planet p1; // defining object
    p1.setName("Planet A");
    p1.setRadius(10.0);
    cout << p1.getName() << endl;
    cout << "Radius: " << p1.getRadius() << endl;
    cout << "Volume: " << p1.getVolume() << endl;
    
    cout << endl;
    
    // test case 2
    // expected output
    // Planet B
    // 8
    // 2144.66
    Planet p2 ("Planet B", 8.0);
    cout << p2.getName() << endl;
    cout << "Radius: " << p2.getRadius() << endl;
    cout << "Volume: " << p2.getVolume() << endl;
    
    cout << endl;
    
    
    
}