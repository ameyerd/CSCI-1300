#include <iostream>
using namespace std;

int printCountriesInRange(string country[], int medal[], int size) {
    
    for (int i = 0; i <= size; i++) {
        if (medal[i] >= 10 && medal[i] <= 15) {
            cout << country[i] << " " << medal[i] << endl;
        }
    }
    
}

int main() {
    string countries[] = {"USA", "Mexico", "Norway", "Canada"};
    int medals[] = {14, 3, 10, 12};
    
    printCountriesInRange(countries, medals, 3);
    
}