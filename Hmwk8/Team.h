#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

class Team {
    public:
        Team();     // defualt constructor
        Team(string);     // parameterized constructor
        void setTeamName(string);
        void readRoster(string);     
        string getPlayerName(int);
        double getPlayerPoints(int);
        int getNumPlayers();
        string getTeamName();
    private:
        string teamName;
        vector<Player> players;
};

#endif