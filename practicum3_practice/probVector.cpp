#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Probability {
    public:
        Probability();
        void ReadFile(string);
        string getMostLikelyEvent(float);
    
    private:
        vector<float> prob_values;
        vector<string> event;
    
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
    
    prob_values = {};
    event = {};
    
}

void Probability::ReadFile(string fileName) {
    
    ifstream fp;
    fp.open(fileName.c_str());
    
    if (fp.is_open()) {
        
        string s;
        string temp_array[2];
        
        while(getline(fp,s)) {
            
            split(s, ',', temp_array, 2);
            
            string weather = temp_array[0];
            
            float prob = stof(temp_array[1]);
            
            prob_values.push_back(prob);
            event.push_back(weather);
        
        }
    }
}

string Probability::getMostLikelyEvent(float threshold) {
    
    for(int i = 0; i < prob_values.size(); i++) {
        if (prob_values.at(i) == 0.0) {
            break;
        }
        else if (prob_values.at(i) >= threshold) {
            return event.at(i);
        }
        else if (i == prob_values.size() - 1) {
            return "";
        }
        
    }
}

int main() {
    
    Probability prob;
    
    prob.ReadFile("weather.txt");
    
    cout << prob.getMostLikelyEvent(0.7);
    
}
