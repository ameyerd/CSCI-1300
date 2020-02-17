// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 1

#include <string>
using namespace std;

// Planet class definition
class Planet {
    public:
        Planet();   // default constructor - same name as the class
        Planet(string, double); // parameterized constructor
        string getName();
        void setName(string);
        double getRadius();
        void setRadius(double);
        double getVolume();
    private: // cannot be accessed by outside
        string planetName; 
        double planetRadius;
};