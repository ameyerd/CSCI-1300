#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    
    ofstream outfile;
    outfile.open("stuart.txt");
    
    int x = 10;
    string country = "United Statees";
    outfile << country << " has " << x << "people " << endl;
    
    outfile.close();
    
    
}