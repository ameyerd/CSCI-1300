// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Hmwk 8 - Problem 4

#include <iostream>
#include <vector>
#include <fstream>
#include "Team.h"
#include "Player.h"
using namespace std;

/*
* Algorithm: returns the name of the winning team
* 1. check first if each team has 4 or more players
* 2. calculate the total points of each team
* 3. compare the two total points and the team with the most points is the winner
* 4. if they have the same # of points then return draw
* Input parameters: team team1, team team2
* Output (prints to screen):  none
* Returns: winner
*/
string game(Team team1, Team team2) {
    // check if teams have 4 or more players
    if (team1.getNumPlayers() < 4 || team2.getNumPlayers() < 4) { 
        return "forfeit";
    }
    else{
        string winner;
        double team1Total = 0;
        double team2Total = 0;
    
        for(int i = 0; i < 4; i++) {
            double tPoints = team1.getPlayerPoints(i); // get player points
            team1Total += tPoints; // add them
        }
        
        for (int k = 0; k < 4; k++) {
            double t2Points = team2.getPlayerPoints(k);
            team2Total += t2Points;
        }
        
        if (team1Total > team2Total) {
            winner = team1.getTeamName(); //if team1 has more points
        }
        else if (team2Total > team1Total) { 
            winner = team2.getTeamName(); // if team2 has moree points
        }
        else if (team2Total == team1Total) { // if both teams havee the same # of points
            return "draw";
        }
        return winner;
    }
}

int main() {
    // g++ gameDriver.cpp Team.cpp Player.cpp -std=c++11
    
    // test 1
    // expected output
    // The winner is: Seg Faultline
    // Using roster1.txt and roster2.txt from Moodle
    Team team1("Seg Faultline");
    team1.readRoster("roster1.txt");
    Team team2("Team Maim");
    team2.readRoster("roster2.txt");
    string winner = game(team1, team2);
    cout << "The winner is: " << winner << endl;
    
    cout << endl;
    
    // test 2
    // expected output
    // The winner is: forfeit
    // Using roster2.txt from Moodle
    Team team3("Hurt Shoebox");
    team3.readRoster("roster00.txt");
    Team team4("Team Maim");
    team2.readRoster("roster2.txt");
    string winer = game(team3, team4);
    cout << "The winner is: " << winer << endl;
}