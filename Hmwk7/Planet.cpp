// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 7 - Problem # 1

#include <iostream>
#include <cmath>
#include "Planet.h"
using namespace std;

Planet::Planet ()
{

}
Planet::Planet(string name, double planetRadius)
{
    planetName = name;
    this->planetRadius = planetRadius; // this--> differentiates variables
}
// --------
string Planet::getName() 
{
    return planetName;
}
void Planet::setName(string name)
{
    planetName = name;
}
double Planet::getRadius()
{
    return planetRadius;
}
void Planet::setRadius(double r)
{
    planetRadius = r;
}
double Planet::getVolume() 
{
    // volume of a sphere
    // 4/3 * pi * r^3
    double volume = (4/3.0) * 3.1415926535897 * pow(planetRadius, 3);
    return volume;

}





