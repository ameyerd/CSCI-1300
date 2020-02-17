// CS1300 Spring 2019
// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Project 3

#include <iostream>
#include <vector>
#include <fstream>
#include "Main.h"
#include "City.h"
#include "Hero.h"
#include "Warrior.h"
using namespace std;

// Split Helper Function
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

Main::Main() {
    username = "";
    answer;
    heroPoints = 0;
    
    hero = {};
    warrior;
    city;
}

// load and initialize all heroes
void Main::readHeroFile(string fileName) {
    
    // open and read heroesGOT.txt
    ifstream fp;
    fp.open(fileName.c_str());
    
    if (fp.is_open()) {
        
        //cout << "File is open!" << endl;
        string temp_array[11];
        string s = "";
        
        while(getline(fp,s)) {
            if (s.length() == 0) continue;
            
            split(s, ',', temp_array,11);
            
            string name = temp_array[0];
            int money = stoi(temp_array[1]);
            int influ = stoi(temp_array[2]);
            int army = stoi(temp_array[3]);
            /*
            vector<string> warrior1 = temp_array[4];
            vector<string> warrior2 = temp_array[5];
            vector<string> warrior3 = temp_array[6];
            vector<string> warrior4 = temp_array[7];
            */
            int row = stoi(temp_array[8]);
            int col = stoi(temp_array[9]);
            string ship = temp_array[10];
            
            
            string war1 = temp_array[4];
            string war2 = temp_array[5];
            string war3 = temp_array[6];
            string war4 = temp_array[7];
            
            hero.push_back(Hero(name, money, influ, army, war1, war2, war3, war4, row, col, ship));
            //cout << "File loaded successfully" << endl;
            
            
        }
        
        fp.close();
    }
    
    else {
        cout << "File could not be opened." << endl;
    }
    
    // split txt file by commas (,)
    
    // put each value into Hero vector
    
}
// load and initialize all warriors
void Main::readWarriorFile(string fileName) {
    
    // read warriorsGOT.txt
    ifstream fp;
    fp.open(fileName.c_str());
    
    if (fp.is_open()) {
        
        //cout << "File is open!" << endl;
        
        string temp_array[7];
        string s = "";
        
        while(getline(fp,s)) {
            
            split(s, ',', temp_array, 7);
            
            string name = temp_array[0];
            int strong = stoi(temp_array[1]);
            int loyal = stoi(temp_array[2]);
            int moral = stoi(temp_array[3]);
            string ifFree = temp_array[4];
            string ship = temp_array[5];
            string dragonglass = temp_array[6];
            
            warrior.push_back(Warrior(name, strong, loyal, moral, ifFree, ship, dragonglass));
            //cout << "File loaded successfully!" << endl;
        
        }
        
        fp.close();
    }
    else {
        cout << "File could not be opened." << endl;
    }
    
    // split txt file by commas (,)
    
    // put into warrior vector
    
    
}
// load and initialize all cities
void Main::readCityFile(string fileName) {
    
    // read citiesGOT.txt
    ifstream fp;
    fp.open(fileName.c_str());
    
    if (fp.is_open()) {
        
        //cout << "File is open!" << endl;
        
        string temp_array[5];
        string s = "";
        
        while(getline(fp,s)) {
            if (s.length() == 0) continue;
            
            split(s, ',', temp_array, 5);
            string letter = temp_array[0];
            string name = temp_array[1];
            int money = stoi(temp_array[2]);
            int army = stoi(temp_array[3]);
            int points = stoi(temp_array[4]);
            
            city.push_back(City(letter, name, money, army, points));
            //cout << "File loaded successfully" << endl;
            
        }
        
        fp.close();
    }
    
    else {
        cout << "File could not be opened." << endl;
    }
    
    
    // split txt file by commas (,)
    
    // put into city vector
    
}
// load the map
void Main::readMapFile(string fileName) {
    
    // open and read the mapGOT.txt
    
    ifstream fp;
    fp.open(fileName.c_str());
    
    if (fp.is_open()) {
        
        //cout << "File is open!" << endl;
        
        
        string s = "";
        
        int row = 0;
        while(getline(fp,s)) {
            
            string temp_array[16];
            
            split(s, ',', temp_array, 16);
            
            for(int i = 0; i < 16; i++) {
                
                temp_array[i][0];
                
                myMap[row][i] = temp_array[i][0];
                
            }
            row++;
        }
        
        fp.close();
        
    }
    else {
        cout << "File cout not be opened." << endl;
    }
    
    // other stuff..
}


// HERO --------

// return the name of the hero
string Main::getHeroName(int index) {
    
    string nameHero = hero[index].getName();
    
    return nameHero;
}
int Main::getHeroMoney(int index) {
    int moneyHero = hero[index].getMoney();
    
    return moneyHero;
}
int Main::getHeroInfluence(int index) {
    int influHero = hero[index].getInfluence();
    
    return influHero;
}
int Main::getHeroArmySize(int index) {
    int armySize = hero[index].getArmySize();
    
    return armySize;
}
int Main::getHeroStartRow(int index) {
    int rowHero = hero[index].getStartRow();
    
    return rowHero;
}
// setstart row
int Main::setHeroStartRow(int index, int num) {
    
    hero[index].setStartRow(num);
    
}
int Main::getHeroStartCol(int index) {
    int colHero = hero[index].getStartCol();
    
    return colHero;
}
// set start col
int Main::setHeroStartCol(int index, int num) {
    
    hero[index].setStartCol(num);
}
string Main::getHeroShip(int index) {
    string ship = hero[index].getHasShip();
    
    return ship;
}
// ---------------------


// WARRIOR -------------------------------------------

string Main::getWarriorName(int index) {
    string name = warrior[index].getWName();
    
    return name;
}
int Main::getWarriorStrength(int index) {
    int strength = warrior[index].getWStrength();
    
    return strength;
}

int Main::setWarriorStrength(int index, int num) {
    
    warrior[index].setWStrength(num);

}

int Main::getWarriorLoyalty(int index) {
    int loyal = warrior[index].getWLoyalty();
    
    return loyal;
}
int Main::getWarriorMorale(int index) {
    
    int morale = warrior[index].getWMorale();
    
    return morale;
    
}
int Main::setWarriorMorale(int index, int num) {
    
    warrior[index].setWMorale(num);
    
}

string Main::getWarriorFree(int index) {
    
    string wFree = warrior[index].getWFree();
    
    return wFree;
    
}

string Main::getWarriorShip(int index) {
    
    string ship = warrior[index].getWShip();
    
    return ship;
    
}

int Main::getWarriorRow(int index) {
     int row = warrior[index].getStartWRow();
     
     return row;
}
int Main::getWarriorCol(int index) {
    int col = warrior[index].getStartWCol();
    
    return col;
}
int Main::setWarriorStartRow(int index, int num) {
    
    warrior[index].setStartWRow(num);
    
}
int Main::setWarriorStartCol(int index, int num) {
    
    warrior[index].setStartWCol(num);
    
}

string Main::getWarrior1(int index) {
    string one = hero[index].getW1();
    
    return one;
}
string Main::getWarrior2(int index) {
    string two = hero[index].getW2();
    
    return two;
}
string Main::getWarrior3(int index) {
    string three = hero[index].getW3();
    
    return three;
}
string Main::getWarrior4(int index) {
    string four = hero[index].getW4();
    
    return four;
}



// ------------------------------------------------

// *******************************************************
/*      Random to-do thoughts

- have to triple check and see if the hero's warriors has a ship????




*/
// *******************************************************



void Main::placeDragonglass() {
    // using random seed generator pick 5 locations on land
    // and use those to place a dragonglass
    
    
    
}


// initially set warriors to a random location
bool Main::setWarriorsRandomLoc() {
    
    // check if they have ship, if the random location is a water tile
    for(int i = 0; i < warrior.size(); i++) {
        
        // generate random numbers
        srand(time(NULL));
        int randomRow = rand() % 25 + 1;
        int randomCol = rand() % 16 + 1;
        
        // check if the row and col is a water tile
        if (myMap[randomRow][randomCol] == 'w') {
            // check if warrior has a ship
            if(getWarriorShip(i) == "yes") {
                // set them to the water tile
                
                // need set row and col for warriors
                setWarriorStartRow(i, randomRow);
                setWarriorStartCol(i, randomCol);
                return true;
                
            }
            else {
                // get another location coordinates
                return false;
                
            }
    
        }
        else {
            // set them to that location
            setWarriorStartRow(i, randomRow);
            setWarriorStartCol(i, randomCol);
            return true;
        }
        
    }
    
}



// GAME START
int Main::startGame() {
    cout << "Welcome to the G A M E of T H R O N E S!" << endl;
    cout << endl;
    cout << "State your name, Your Grace: ";
    cin >> username;
    cout << endl;
    cout << "Would you like to choose a hero " << username << ", Your Grace? (Y/N): ";
    
    cin >> answer;
    if (answer == "Y" || answer == "y") {
        cout << "Please choose from the following heroes: " << endl;
        cout << "1. Cersei Lannister\n2. Stannis Baratheon\n3. Jon Snow\n4. Sansa Stark\n5. Euron Greyjoy\n6. Daenerys Targaryen" << endl;
        string herochoice;
        cin >> herochoice;
        
        heroChoice = stoi(herochoice) - 1;
        
        cout << "Good choice." << endl;
        
        cout << endl;
        return 0;
        
    }   
    else {
        cout << "Your Grace " << username << ", you have chosen to go on this journey alone. Please provide starting values for your adventure." << endl;
        
        //Hero player;
       // player.setHeroName(username);
        
        cout << "How much money do you have? (0-10000)" << endl;
        cin >> amount;
        if (amount < 0) {
            cout << "Invalid Amount! You're too poor!" << endl;
            return -1;
        }
        else if (amount > 10000) {
            cout << "Invalid Amount! You're too rich!" << endl;
            return -1;
        }
        //player.setHeroMoney(amount);
        
        cout << "How influential are you? (0-10000)" << endl;
        cin >> influ;
        if (influ < 0) {
            cout << "Invalid Amount! You are not influential enough! " << endl;
            return -1;
        }
        else if (influ > 10000) {
            cout << "Invalid Amount! You have too much ifluence! " << endl;
            return -1;
        }
        //player.setHeroInfluence(influ);
        
        cout << "How big is your army? (0-10000)" << endl;
        cin >> asize;
        if (asize < 0) {
            cout << "Invalid Amount! You have no army!" << endl;
            return -1;
        }
        else if (asize > 10000) {
            cout << "Invalid Amount! You're army is too big!" << endl;
            return -1;
        }
        //player.setArmySize(asize);
        
        cout << "Where would you like to start?" << endl;
        cout << "Row? (1-25)" << endl;
        cin >> r;
        if (r < 1 || r > 25) {
            cout << "Invalid Row! You cannot start there!" << endl;
            return -1;
        }
        //player.setStartingLocationRow(r);
        
        cout << "Column? (1-16)" << endl;
        cin >> c;
        if (c < 1 || c > 16) {
            cout << "Invalid Column! You cannot start there!" << endl;
            return -1;
        }
        //player.setStartingLocationCol(c);
        
        //no warriors
        string no = "NULL";
        
        
        // if user starts in the water give them a ship --------------------------
        string userShip = "no";
        
        // -----------------------------------------------------------------------
        
        hero.push_back(Hero(username, amount, influ, asize, no, no, no, no , r, c, userShip));
        
        
    }
    
    
}

/*
//helper function
void Main::checkIf(int index) {
    
    if(map.at(index) == "p") {
        cout << "*";
    }
    else if (map.at(index) == "w") {
        cout << "~";
    }
    else {
        cout << map.at(index);
    }
    
    
}
*/

void Main::displayStats() {
    
    cout << "======== Hero Stats ========" << endl;
    
    cout << "Hero Name: " << getHeroName(heroChoice) << endl;
    
    cout << "Hero's Money: " << getHeroMoney(heroChoice) << endl;
    
    cout << "Hero's Influence: " << getHeroInfluence(heroChoice) << endl;
    
    cout << "Hero's Army Size: " << getHeroArmySize(heroChoice) << endl;
    
    cout << "Hero's Warriors: " << "\n1. " << getWarrior1(heroChoice) 
    << "\n2. " << getWarrior2(heroChoice) << "\n3. " << getWarrior3(heroChoice) << "\n4. " << getWarrior4(heroChoice) << endl;
    
    cout << "Hero's Location: " << getHeroStartRow(heroChoice) << "," << getHeroStartCol(heroChoice) << endl;
    
    cout << "Ship: " << getHeroShip(heroChoice) << endl;
    
    cout << "===========================" << endl;
    
    cout << endl;
    
}

void Main::displayMap() {
    
    int row = getHeroStartRow(heroChoice);
    int col = getHeroStartCol(heroChoice);
    
    /*
    // display full map
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 16; j++) {
            cout << myMap[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    // 7x7
    // -3 (center) +3
    for(int i = row - 3; i < row + 4; i++) {
        for(int j = col - 3; j < col + 4; j++) {
            cout << myMap[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;

    
    
}

string Main::displayChoices() {
    
    Warrior wari;
    Hero her;
    
    // hero has 3 choices
    cout << "What would you like to do, your Grace?\n1. Travel\n2. Rest\n3. Consult with the gods" << endl;
    string turnchoice;
    cin >> turnchoice;
    
    turnChoice = stoi(turnchoice);
    
    
    if(turnChoice == 1) {
        //travel
        cout << "Which direction would you like travel? (N,S,E or W)?" << endl;
        cin >> travel;
        
        //cout << "here" << endl;
        // update hero's location
        if (travel == "N" || travel == "n") {
            //SETSTARTROW FUNCTION
            //cout << "here" << endl;
            // check if its a water tile, then check if hero has a ship
            if(myMap[(getHeroStartRow(heroChoice) - 1)][getHeroStartCol(heroChoice)] == 'w') {
                
                if(getHeroShip(heroChoice) == "yes") {
                    setHeroStartRow(heroChoice, getHeroStartRow(heroChoice) - 1);
                    //cout << "here" << endl;
                }
                else {
                    cout << "You don't have a ship! You cannot go that direction." << endl;
                    //cout << "here" << endl;
                }

            }
            else { // move north
                
                setHeroStartRow(heroChoice, getHeroStartRow(heroChoice) - 1);
                //cout << "here" << endl;
                
            }
            
            
        }
        
        else if (travel == "S" || travel == "s") {
            
            if(myMap[getHeroStartRow(heroChoice) + 1][getHeroStartCol(heroChoice)] == 'w') {
                if(getHeroShip(heroChoice) == "yes") {
                    setHeroStartRow(heroChoice, getHeroStartRow(heroChoice) + 1);
                }
                else {
                    cout << "You don't have a ship! You cannot go that direction." << endl;
                }
            }
            else { // move north
                
                setHeroStartRow(heroChoice, getHeroStartRow(heroChoice) + 1);
            }
            
        }
        
        else if (travel == "E" || travel == "e") {
            
            if(myMap[getHeroStartRow(heroChoice)][getHeroStartCol(heroChoice) + 1] == 'w') {
                if(getHeroShip(heroChoice) == "yes") {
                    setHeroStartCol(heroChoice, getHeroStartCol(heroChoice) + 1);
                }
                else {
                    cout << "You don't have a ship! You cannot go that direction." << endl;
                }
            }
            else { // move north
                
                setHeroStartCol(heroChoice, getHeroStartCol(heroChoice) + 1);
            }
        }
        
        
        else if (travel == "W" || travel == "w") {
            
            if (myMap[getHeroStartRow(heroChoice)][getHeroStartCol(heroChoice) - 1] == 'w') {
                if(getHeroShip(heroChoice) == "yes") {
                    setHeroStartCol(heroChoice, getHeroStartCol(heroChoice) - 1);
                }
                else {
                    cout << "You don't have a ship! You cannot go that direction." << endl;
                }
            }
            else {
                setHeroStartCol(heroChoice, getHeroStartCol(heroChoice) - 1);
            }
        }
        
        // else {
            
        //     return "Invalid input!";
        // }
        
        
        // N - row--
        // S - row++
        // E - col++
        // W - col--
        
        // check if location is in bounds
        
    
    
    }
    
    else if (turnChoice == 2) {
        // rest
        cout << "You have chosen to rest. Your warrior's strengths has increased by 1." << endl;
        // increase warrior's strength
        
        // WARRIOR 1
        string w1 = getWarrior1(heroChoice);
        
        int index1 = 0;
        for(int i = 0; i < 14; i++) {
            // compare the name to the list of warriors and find the index
            if (w1 == getWarriorName(i)) {
                index1 = i;
                break;
            }
            else {
                // do nothing
            }
        }
        
        //cout << "strength before: " << getWarriorStrength(index1) << endl;
        
        // check if there is a warrior
        if (w1 == "NULL") {
            //do nothing
        }
        else {
            
            // update the warrior's strength
            setWarriorStrength(index1, getWarriorStrength(index1) + 1);
            
        }
        
        //cout << "strength after: " << getWarriorStrength(index1) << endl;
        
        
        
        
        
        // WARRIOR 2
        string w2 = getWarrior2(heroChoice);
        
        int index2 = 0;
        for(int j = 0; j < 14; j++) {
            // compare the name to the list of warriors and find the index
            if (w2 == getWarriorName(j)) {
                index2 = j;
                break;
            }
            else {
                // do nothing
            }
        }

        // check if there is a warrior
        if (w2 == "NULL") {
            //do nothing
        }
        else {
            
            setWarriorStrength(index2, getWarriorStrength(index2) + 1);
        }
        
        
        // WARRIOR 3
        string w3 = getWarrior3(heroChoice);
        
        int index3 = 0;
        for(int k = 0; k < 14; k++) {
            // compare the name to the list of warriors and find the index
            if (w3 == getWarriorName(k)) {
                index3 = k;
                break;
            }
            else {
                // do nothing
            }
        }
        // check if there is a warrior
        if (w3 == "NULL") {
            //do nothing
        }
        else {
            
            setWarriorStrength(index3, getWarriorStrength(index3) + 1);
            
        }
        
        
        // WARRIOR 4
        string w4 = getWarrior1(heroChoice);
        
        int index4 = 0;
        for(int m = 0; m < 14; m++) {
            // compare the name to the list of warriors and find the index
            if (w4 == getWarriorName(m)) {
                index4 = m;
                break;
            }
            else {
                // do nothing
            }
        }
        
        if (w4 == "NULL") {
            //do nothing
        }
        else {
            setWarriorStrength(index4, getWarriorStrength(index4) + 1);
        }
        
    }
    
    
    // OPTION 3 -------------
    else if (turnChoice == 3) {
        // consult with the gods
        cout << "You have chosen to consult with the Gods. Your warrior's morales has increased by 1." << endl;
        // increase warrior's morale
        
        // WARRIOR 1
        string w1 = getWarrior1(heroChoice);
        
        int index1 = 0;
        for(int i = 0; i < 14; i++) {
            // compare the name to the list of warriors and find the index
            if (w1 == getWarriorName(i)) {
                index1 = i;
                break;
            }
            else {
                // do nothing
            }
        }
        
        //cout << "before: " << getWarriorMorale(index1) << endl;
        
        // check if there is a warrior
        if (w1 == "NULL") {
            //do nothing
        }
        else {
            setWarriorMorale(index1, getWarriorMorale(index1) + 1);
        }
        
        //cout << "after: " << getWarriorMorale(index1) << endl;
        
        // WARRIOR 2
        string w2 = getWarrior2(heroChoice);
        
        int index2 = 0;
        for(int j = 0; j < 14; j++) {
            // compare the name to the list of warriors and find the index
            if (w2 == getWarriorName(j)) {
                index2 = j;
                break;
            }
            else {
                // do nothing
            }
        }
        
        
        // check if there is a warrior
        if (w2 == "NULL") {
            //do nothing
        }
        else {
            setWarriorMorale(index2, getWarriorMorale(index2) + 1);
        }
        
        
        // WARRIOR 3
        string w3 = getWarrior3(heroChoice);
        
        int index3 = 0;
        for(int k = 0; k < 14; k++) {
            // compare the name to the list of warriors and find the index
            if (w3 == getWarriorName(k)) {
                index3 = k;
                break;
            }
            else {
                // do nothing
            }
        }
        // check if there is a warrior
        if (w3 == "NULL") {
            //do nothing
        }
        else {
            setWarriorMorale(index3, getWarriorMorale(index3) + 1);
        }
        
        
        // WARRIOR 4
        string w4 = getWarrior1(heroChoice);
        
        int index4 = 0;
        for(int m = 0; m < 14; m++) {
            // compare the name to the list of warriors and find the index
            if (w4 == getWarriorName(m)) {
                index4 = m;
                break;
            }
            else {
                // do nothing
            }
        }
        
        if (w4 == "NULL") {
            //do nothing
        }
        else {
            setWarriorMorale(index4, getWarriorMorale(index4) + 1);
        }

        
    }
    

}

// UDPATE LOCATION OF THE OTHER HEROS
void Main::updateLocOther() {
    // generate random location
    // if main hero's start row and col are equal to any others //
    
    // for every other hero in the vector
    
    int i = 0;
    while (getHeroName(i) != getHeroName(heroChoice) && i < hero.size()) {
        
        // generate random number between 1 and 4
        srand(time(NULL));
        int randomNum = rand() % 4 + 1;
        
         // N - row--
        // S - row++
        // E - col++
        // W - col--
        
        // random number = direction
        if (randomNum == 1) {
            // go north
            setHeroStartRow(i, getHeroStartRow(i) - 1);
            
        }
        else if (randomNum == 2) {
            // go south
            setHeroStartRow(i, getHeroStartRow(i) + 1);
            
        }
        else if (randomNum == 3) {
            // go east
            setHeroStartCol(i, getHeroStartCol(i) + 1);
        }
        else if (randomNum == 4) {
            // go west
            setHeroStartCol(i, getHeroStartCol(i) - 1);
        }
        
        i++;

    }
    
    int j = 0;
    // check if the warriors are free
    while(getWarriorFree(j) == "yes") {
        
        srand(time(NULL));
        int randomNum = rand() % 4 + 1;
        
        
        // N - row--
        // S - row++
        // E - col++
        // W - col--
        
        //same thing as heros
        
        if (randomNum == 1) {
            // go north
            setWarriorStartRow(i, getWarriorRow(i) - 1);
            
        }
        else if (randomNum == 2) {
            // go south
            setWarriorStartRow(i, getWarriorRow(i) + 1);
            
        }
        else if (randomNum == 3) {
            // go east
            setWarriorStartCol(i, getWarriorCol(i) + 1);
        }
        else if (randomNum == 4) {
            // go west
            setWarriorStartCol(i, getWarriorCol(i) - 1);
        }
        
        j++;
        
        
    }

}

bool Main::heroEncounter() {
    
    // check if another hero is nearby (within 2 tiles any direction)
        
    int row = getHeroStartRow(heroChoice);
    int col = getHeroStartCol(heroChoice);
    
    
    for(int i = row - 2; i < row + 3; i++) {
        for(int j = col - 2; j < col + 3; j++) {
            
            for(int k = 0; k < hero.size(); k++) {
                
                if(getHeroStartRow(k) == i && getHeroStartCol(k) == j) {
                    
                    return true;
                    //cout << "There is another hero nearby! What wil you do?" << endl;
                }
                
            }
            
            myMap[i][j];
            // read through map 
        }
    
    }
    
}


    
    
    
        //create another map and go throught that map to see if any heros r in there
        
        // getherostartrow(i) == getherstartrow(herochoice)
        
    
    // if encounter occurs
        // hero has 3 choices
        // give a speech
            // (1 - (opposing hero's 1st warrior morale/100)) * (main hero's influence / 16000)
        
            // if probability is less than or equal to 0, main hero loses encounter
            
            // if probability is equal to 1, main hero automatically wins encounter
            
            
            // if main hero wins, losing hero retires (remove from vector)
            // cout << hero_name << " has retired." << endl;
            
            // main hero acquires other hero's warriors (max 4)
                // check how many main hero has
            // money, influence, army size
            
            // if main hero loses
                // encounter ends,
                // main hero escapes
                // main hero loses half their influence value
            
        // buy them outright
            // (1 - (opposing hero's first warrior loyalty/100)) * (main hero's money/17800)
            // if probability is less than or equal to 0, main hero loses encounter
            
            // if probability is equal to 1, main hero automatically wins encounter
            
            // if main hero wins, losing hero retires (remove from vector)
            // cout << hero_name << " has retired." << endl;
            
            // main hero acquires other hero's warriors (max 4)
                // check how many main hero has
            // money, influence, army size
            
            // if main hero loses
                // encounter ends,
                // main hero escapes
                // main hero loses half their influence value
        
        // battle
            // check if one hero has a warrior and if the other doesn't , the one that doesn't automatically loses
            
            // check if main hero has more than 1 warrior
                // ask user to choose with warrior to represent them in battle
                
            // if opposing hero has more than 1 warrior
                // randomly choose one of their warriors to represent them in battle
                
            // hero with highest value wins
                // calculate for both warriors and see which is higher
                // (army size) * (strength of chosen warrior)
                
                
            // if main hero wins, losing hero retires (remove from vector)
            // cout << hero_name << " has retired." << endl;
            
            // main hero acquires other hero's warriors (max 4)
                // check how many main hero has
            // money, influence, army size
            
            // if main hero loses
                // encounter ends,
                // main hero escapes
                // main hero loses half their influence value
                
                
                
    // THERES MORE
                


void Main::randomEvent() {
    // at end of every turn, there is s 30% chance that one random event will occur
    // LOYALTY AND MORALE CANNOT EXCEED 100
    // STRENGTH CANNOT EXCEED 200
    
    // drought
        cout << "Oh no! There hasn't been rain in days and the army has very little food left!" << endl;
        // morale and strength of each of the warriors decrease by 10
    
    // deserters
        cout << "Come on! The campaign is taking a long time and the soldiers are tired and sad. ):" << endl;
        cout << "Some decided to leave." << endl;
        
        // army size goes down by 10
        // loyalty of each warrior goes down by 10
    
    // jackpot
        cout << "Your heroic cause has won the hearts of many noble and wealthy benefactor! They generously donate funds to your cause!" << endl;
        // main hero's money doubles
    
    // kindness
        cout << "You've come across some refugees and decide to off shelter." << endl;
        // army size goes up by 10
        // loyalty of each warrior goes up by 10
    
}

void Main::preconditionEvent() {
    // preconditioned events
    // Daenerys acquires Dragons as their warrior after 10 turns
        // check if main hero is Daenerys
        // other..
        
    // Stannis gets consumed by his demons and dies after 10 turns
        // check if main hero is Stannis
        // other..
        
    // Sansa
    
    // Cersei
    
    
}

void Main::endGame() {
    // loses if:
        // loses a battle with another hero
        // loses final battle with White Walkers
        // if user refuses to battle the White Walkers 5 times
    // wins if:
        // wins final battle against White Walkers
        
}
