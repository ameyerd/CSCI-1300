#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in_file;               // for reading
    string filename = "input.txt";  // input file name - path is RELATIVE to current directory
    in_file.open(filename);         // open file for reading

    // check if the file opened correctly using the .fail() method
    if (in_file.fail()) {
        cout << "Failed to open file stream for input file " << filename << endl;
        return 0;                   // need to bail out here, because without an open file stream the rest of the code doesn't make any sense!
    }

    string name;
    int value;

    in_file >> name >> value;
    cout << name << " has value " << value << endl;

    cout << "---------------------" << endl;

    // "not-failed" condition lets us know when we hit the end!
    while (in_file >> name >> value) {
        cout << name << " has value " << value << endl;
    }

    cout << "---------------------" << endl;

    // I don't believe me - "not-failed" condition has an actual value??
    bool success = in_file >> name >> value;
    cout << success << endl;
                // ... totes!

    in_file.close();

   return 0;
}