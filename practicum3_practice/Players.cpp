#include <iostream>
#include <fstream>
using namespace std;

class Players {
    public:
        Players();
        void ReadFile(string);
        float MaxSalary();
        string MaxSalaryName();
    
    private:
        float salaries[50];
        string names[50];
    
};

Players::Players() {
    
    for(int i = 0; i < 50; i++) {
        salaries[i] = -1.0;
        names[i] = "";
    }
    
}

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

void Players::ReadFile(string fileName) {
    
    ifstream fp;
    fp.open(fileName);
    
    if(fp.is_open()) {
        
        string s;
        string temp_array[2];
        int i = 0;
        
        while(getline(fp,s)) {
            
            split(s, ',' , temp_array, 2);
            
            string name = temp_array[0];
            float sal = stof(temp_array[1]);
            
            salaries[i] = sal;
            names[i] = name;
            
            i++;
            
        }
    }
    
}

float Players::MaxSalary() {
    
    float highest = 0.0;
    
    for(int i = 0; i < 50; i++) {
        if(salaries[i] > highest) {
            highest = salaries[i];
        }
    }
    
    return highest;
}

string Players::MaxSalaryName() {
    
    float highest = MaxSalary();
    
    for (int i = 0; i < 50; i++) {
        if(salaries[i] == highest) {
            return names[i];
        }
    }

}

int main() {
    
    Players play;
    
    play.ReadFile("salary.txt");
    
    cout << play.MaxSalary();
    cout << play.MaxSalaryName();
}
