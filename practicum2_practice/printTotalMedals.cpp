#include <iostream>
#include <string>
using namespace std;

void printTotalMedals(string disciplines[], int gold[], int silver[], int bronze[], int size) {
    
    if (size < 1) {
        cout << "Invalid size. Size must be at least 1.";
    }
    
    for(int i = 0; i < size; i++) {
        int total = gold[i] + silver[i] + bronze[i];
        cout << disciplines[i] << ": " << total << endl;
    }
    

}

int main() {
    const int SPORTS = 3; // number of sports/disciplines
    string disciplines[] =
    {
        "Figure Skating",
        "Speed Skating",
        "Short track"
    };
    
    int gold_medals[SPORTS] =   {1, 0, 0};
    int silver_medals[SPORTS] = {1, 0, 0};
    int bronze_medals[SPORTS] = {1, 2, 1};
    
    printTotalMedals(disciplines, gold_medals, silver_medals, bronze_medals, 3);

}