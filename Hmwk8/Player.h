#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player {
    
    public:
        Player();       // default constructor
        Player(string,double);  //parameterized constructor
        string getName();
        double getPoints();
        void setName(string);
        void setPoints(double);
    private:
        string name;
        double points;
};

#endif