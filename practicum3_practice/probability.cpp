#include <iostream>
#include <fstream>
using namespace std;


class Probability {
    public:
        Probability();
        void ReadFile(string);
        string getMostLikelyEvent(float);
    
    private:
        float prob_values[50];
        string event[50];
    
};

//split function
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


Probability::Probability() {
    
    for (int i = 0; i < 50; i++) {
        prob_values[i] = 0.0;
    }
    for (int j = 0; j < 50; j++) {
        event[j] = "";
    }
    
}

void Probability::ReadFile(string fileName) {
    
    ifstream fp;
    fp.open(fileName);
    
    if (fp.is_open()) {
        
        string s;
        string temp_array[2];
        int i = 0;
        
        while(getline(fp,s)) {
            
            split(s, ',', temp_array, 2);
            
            string weather = temp_array[0];
            float prob = stof(temp_array[1]);
            
            prob_values[i] = prob;
            event[i] = weather;
            
            i++;
        }
    }
}

string Probability::getMostLikelyEvent(float threshold) {
    
    for(int i = 0; i < 50; i++) {
        if (prob_values[i] == 0.0) {
            break;
        }
        else if (prob_values[i] >= threshold) {
            return event[i];
        }
        else if (i == 49) {
            return "";
        }
        
    }
}

int main() {
    
    Probability prob;
    
    prob.ReadFile("weather.txt");
    
    cout << prob.getMostLikelyEvent(0.7);
    
}
