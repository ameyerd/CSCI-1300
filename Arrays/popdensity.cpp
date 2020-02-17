#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    
    ifstream infile;
    infile.open("worldpop.txt");
    // throw an error conndition if we dint not read it successfully
    if (infile.fail()) {return -1;}

    string line;
    int i;
    const int CAPACITY = 300;
    string countries[CAPACITY];
    int populations[CAPACITY];
    
    int cnt = 0; // to count up the # of countries
    
    while(getline(infile, line)) {
        cout << line << endl;
        for (i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                break;
            }
        }
        populations[cnt] = stoi(line.substr(i));
        
        int j;
        for (j = i-1; j >= 0; j--) {
            if (!isspace(line[j])) {
                break;
            }
            
        }
        countries[cnt] = line.substr(0, j+1);
        cnt++;
    }

    
}
