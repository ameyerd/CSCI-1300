#include <iostream>
#include "Player.h"
using namespace std;

Player::Player() { // set name to "" and points value to 0
    name = "";
    points = 0.0;
}

Player::Player(string playername, double playerpoints) {
    name = playername; 
    points = playerpoints;
}

string Player::getName() {
    return name;
}

double Player::getPoints() {
    return points;
}

void Player::setName(string playername) {
    name = playername;
}

void Player::setPoints(double playerpoints) {
    points = playerpoints;
}