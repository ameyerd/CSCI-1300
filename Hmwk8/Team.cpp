#include <iostream>
#include <vector>
#include <fstream>
#include "Team.h"
using namespace std;

// split function
int split(string str, char c, string array[], int num) {
    
    if (str.length() == 0) {
        return 0;
    }
    int a = 0;
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
        	array[a] = word; 
        	a++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j ;
    
}

// Team implementation

Team::Team() { // set teamName = "" and an empty vector of players
    teamName = "";
    players;
}
Team::Team(string team) {
    teamName = team;
    players;
}
void Team::setTeamName(string name) {
    teamName = name;
}
void Team::readRoster(string fileName) {
    /*
    Reads from the input file name (a string) a list of player names​ 
    and their ​points​ values, separated by a comma, and appends the 
    players (in order) to the players​ vector for this team
    */
    ifstream fp;
    fp.open(fileName.c_str());
    string s;
    string tempArray[2];
    Player tempPlayer;
    
    if (fp.is_open()) {
        // split the words
        // first column is player names
        // append playernames into player vector (push_back)
        
        while(getline(fp,s)) {
            //split
            split(s, ',', tempArray,2);
            
            string playerNames = tempArray[0];
            double playerPoints = stod(tempArray[1]);
            
            players.push_back(Player(playerNames,playerPoints));
            
        }
    }
}

string Team::getPlayerName(int index) {
    // returns name of the player at position i
 
    
    if (index < players.size()) { // if less than # of players
        string playerName = players[index].getName();  
        return playerName;
    }
    else {
        return "ERROR";
    }
    
}
double Team::getPlayerPoints(int index) {
    // returns points of player at position i 

    
    if (index < players.size()) {
        double playerPoints = players[index].getPoints();
        return playerPoints;
    }
    else {
        return -1;
    }
    
}
int Team::getNumPlayers() {
    // return the number of players on this team
    return players.size();
}
string Team::getTeamName() {
    // return the name of this team
    return teamName;
}
