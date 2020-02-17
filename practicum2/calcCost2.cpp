#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// split

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
// --------

int calcCost(string fileName) {
    
    ifstream fp;
    fp.open(fileName);
    
    string r;
    double total = 0;
    int count = 0;
    if (fp.is_open()) {
        // read lines
        while(getline(fp, r)) {
            string temp_array[3];
            split(r, ',', temp_array, 3);
            
            double arr1 = stod(temp_array[1]);
            double arr2 = stod(temp_array[2]);
            double cost = arr1 * arr2;
            
            cout << temp_array[0] << ": " << cost << endl;
            total = total + cost;
            
            count++;
            
        }
        cout << "Total: " << total;
        return count;
    }
    else {
        return -1;
    }
    
}

int main() {
    calcCost("calc.txt");
    
    int a = 14 + 18 + 18 + 30;
    cout << endl;
    cout << a << endl;
    
    int b = 30 - 12;
    cout << b << endl;
    
    cout << a - b << endl;
    
    cout << b / a;
    
    
    
}