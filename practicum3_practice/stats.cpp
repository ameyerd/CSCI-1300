#include <iostream>
#include <fstream>
using namespace std;

class Stats {
    public:
        Stats();
        void ReadFile(string);
        float getAvgStringLength();
        string getLongestString();
    
    private:
        string data[50];
        int dataSize;
    
};

Stats::Stats() {
    
    data;
    dataSize = 50;
    
}

void Stats::ReadFile(string fileName) {
    
    ifstream fp;
    fp.open(fileName);
    
    if(fp.is_open()) {
        
        string s;
        int i = 0;
        
        while(getline(fp,s)) {
            
            data[i] = s;
            
            i++;
        }
        
        dataSize = i;
    }
}

float Stats::getAvgStringLength() {
    
    float sum = 0.0;
    
    for(int i = 0; i < dataSize; i++) {
        sum += data[i].length();
    }
    
    float avg = sum / dataSize;
    
    return avg;
}

string Stats::getLongestString() {
    
    int longest = 0;
    
    int i;
    for(i = 0; i < dataSize; i++) {
        if(data[i].length() > longest) {
            longest = data[i].length();
        }
    }
    
    for(int j = 0; j < dataSize; j++) {
        if(data[j].length() == longest) {
            return data[j];
        }
    }
    
}

int main() {
    
    Stats stat;
    
    stat.ReadFile("stat.txt");
    
    cout << stat.getAvgStringLength() << endl;
    
    cout << stat.getLongestString();
}