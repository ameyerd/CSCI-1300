#include <iostream>
#include <fstream>
using namespace std;


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

float maxTemp(string fileName) {
    
    ifstream fp;
    fp.open(fileName);
    
    int max_temp = 0;
    string s;
    int size = 50;
    int i = 0;
    string temp_array[size];
    if (fp.is_open()) {
        // here
        
        while(getline(fp, s)) {
            if (s.length() == 0) continue;
            
            split(fileName, ',', temp_array, size);
            string day = temp_array[0];
            string temp = temp_array[1];
            
            float maxtemp = stof(temp);  // ??????
            
            if (maxtemp > max_temp) {
                max_temp = maxtemp;
            }
            
            i++;
        }

        fp.close();  
        return max_temp;
    }
    else {
        return -1;
    }
    
}

int main() {
    
    maxTemp("temp.txt");
    
}

