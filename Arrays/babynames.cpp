#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    
    ifstream infile;
    infile.open("babynames.txt");
    // since we know how the file is formualated, we can use infile >> .. to 
    // grab successive inputs
    int rank;
    string boyname, girlname;
    int number;
    double percent;
    infile >> rank >> boyname >> number >> percent;
    cout << rank << " " << boyname << " " << number << " " << percent << endl;
    
    infile >> rank >> girlname >> number >> percent;
    cout << rank << " " << girlname << " " << number << " " << percent << endl;
    
    
}