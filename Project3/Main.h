#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include "Hero.h"
#include "Warrior.h"
#include "City.h"
using namespace std;


class Main {
    public:
        Main();     // default constructor
        
        // HERO FUNCTION CALLS AT CERTAIN INDX
        string getHeroName(int);
        int getHeroMoney(int);
        int getHeroInfluence(int);
        int getHeroArmySize(int);
        
        int getHeroStartRow(int);
        int getHeroStartCol(int);
        int setHeroStartRow(int,int);
        int setHeroStartCol(int,int);
        string getHeroShip(int);
        
        // WARRIOR FUNCTION CALLS AT CERTAIN INDX
        string getWarriorName(int);
        int getWarriorStrength(int);
        int setWarriorStrength(int,int);
        int getWarriorLoyalty(int);
        int getWarriorMorale(int);
        int setWarriorMorale(int,int);
        
        string getWarriorFree(int);
        string getWarriorShip(int);
        
        int getWarriorRow(int);
        int getWarriorCol(int);
        int setWarriorStartRow(int,int);
        int setWarriorStartCol(int,int);
        
        
        string getWarrior1(int);
        string getWarrior2(int);
        string getWarrior3(int);
        string getWarrior4(int);

        
        // load text files to set up the game
        // initializing all heroes and warriors
        void readHeroFile(string);
        void readWarriorFile(string);
        void readCityFile(string);
        void readMapFile(string);
        
        void checkIf(int);
        
        //int userChoiceStartRow(int);
        //int userChoiceStartCol(int);
        // place dragonglass in 5 random locations
        
        void placeDragonglass();
        
        bool setWarriorsRandomLoc();
        
        // start game function
        int startGame();
        
        void displayStats();
        void displayMap();
        
        // display choices
        string displayChoices();
        
        void updateLocOther();
        
        // if the hero encounters another hero, the main hero has 3 choices
        bool heroEncounter();
        void heroEncounterChoices();
        
        
        void randomEvent();
        void preconditionEvent();
        
        // end game function
        void endGame();
        
        //void heroChoice();
        
        
    private:
        // private variables
        string username;
        string answer;
        int heroChoice;
        int turnChoice;
        string travel;
        int encounterChoice;
        
        int amount;
        int influ;
        int asize;
    
        int r;
        int c;
        int heroPoints;

        vector<Hero> hero;
        vector<Warrior> warrior;
        vector<City> city;
        
        char myMap[25][16];
        
};

#endif