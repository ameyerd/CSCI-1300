// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 3

#include <iostream>
#include <vector>
#include "Main.h"
#include "City.h"
using namespace std;


int main() {
    // g++ gameDriver.cpp Main.cpp Hero.cpp Warrior.cpp City.cpp -std=c++11
    
    Main game;  // define Main object
    City city;
    //Hero hero;
    // load the text files (heroes, warriors, cities)
    // update the hero's points at the beginning
    
    game.readHeroFile("heroesGOT.txt");
    game.readWarriorFile("warriorsGOT.txt");
    game.readCityFile("citiesGOT.txt");
    game.readMapFile("mapGOT.txt");

    // game.placeDragonglass();
    
    //set warriors at random locations

    while(game.setWarriorsRandomLoc() == false) {
        game.setWarriorsRandomLoc();
    }
    
    // start the game
    game.startGame();
    
    // WHILE LOOP
    // show map to the user (7x7)
    //game.displayStats();
    
    game.displayMap();
    
    // Hero's 3 choices : Travel, Rest, Consult with the gods
    // after each turn
    // using while loop

        
    game.displayChoices();

    game.updateLocOther();
    
    
    // Other hero encounter
    // if another hero is within main hero's proximity run function
    game.heroEncounter();
    
    // chances for random event
    // game.randomEvent();
    
    // end game
    // game.endGame();
    // game ends when:
    // 1. The user loses a battle with another hero
    // 2. The user fights the final battle with the White Walkers and either 
    //    wins or loses the battle. If won then they win the game, if they lose the 
    //    the battle then they lose the game

    
    
    
    
}