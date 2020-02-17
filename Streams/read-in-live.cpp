#include <iostream>
#include <fstream> // header to read/write files
#include <string>
using namespace std;




int main() {
    
    ifstream in_file;
    in_file.open("input.txt"); // opens file
    
    //in_file can be treated just like cin >>
    //cin >> name >> value;
    string name;
    int value;
    
    in_file >> name >> value;
    cout << name << " has value " << value << endl;
    // knows when it ends, start on next line,, dont need to increment
    in_file >> name >> value;
    cout << name << " has value " << value << endl;
    
    return 0;
    
}