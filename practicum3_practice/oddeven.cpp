#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class OddEven {
    public:
        OddEven();
        void ReadFile(string);
        int getOddCount();
        int getEvenCount();
    private:
        int numbers[50];
    
};

OddEven::OddEven() {
    for(int i = 0; i < 50; i++) {
        numbers[i] = -1;
    }
}

void OddEven::ReadFile(string fileName) {
    
    ifstream fp;
    fp.open(fileName);
    
    string s;
    int i = 0;
    if(fp.is_open()) {
        
        while (getline(fp,s)) {
            
            numbers[i] = stoi(s);
            i++;
        }
    }
    
}

int OddEven::getOddCount() {
    
    int count = 0;
    
    for(int i = 0; i < 50; i++) {
        if (numbers[i] == -1) {
            break;
        }
        if (numbers[i] % 2 != 0) {
            count++;
        }
    }
    
    return count;
}

int OddEven::getEvenCount() {
    
    int count = 0;
    
    for(int i = 0; i < 50; i++) {
        if(numbers[i] % 2 == 0) {
            count++;
        }
    }
    
    return count;
    
}

int main() {
    
    OddEven test1;
    
    test1.ReadFile("oddeven1.txt");
    
     cout << test1.getOddCount() << endl;
     
     cout << test1.getEvenCount();
    
}