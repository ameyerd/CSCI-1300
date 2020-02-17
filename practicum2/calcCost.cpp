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
    if (fp.is_open()) {
        
        // read lines
        while(getline(fp, r)) {
            int max_words = r.length() + 1;
            string temp_array[max_words];
            split(r, ',', temp_array, max_words);
            
            double arr1 = stod(temp_array[1]);
            double arr2 = stod(temp_array[2]);
            double cost = arr1 * arr2;
            
            
            for (int i = 0; i < 1; i++) {
                cout << temp_array[0] << ": " << cost << endl;
                total = total + cost;
            }
        }
        cout << total;
    }
    else {
        return -1;
    }
    
}

int main() {
    calcCost("calc.txt");
    
    
}