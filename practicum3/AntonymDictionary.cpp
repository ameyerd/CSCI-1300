#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class AntonymDictionary {
    public:
        AntonymDictionary();
        int LoadWords(string);
        int SearchForWord(string);
        string GetAntonym(string);
    
    private:
        string words[50];
        string antonyms[50];
    
};

AntonymDictionary::AntonymDictionary() {
    
    for (int i = 0; i < 50; i++) {
        words[i] = "";
        antonyms[i] = "";
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


int AntonymDictionary::LoadWords(string fileName) {
    
    ifstream fp;
    fp.open(fileName);
    
    if(fp.is_open()) {
        
        string s;
        string temp_array[2];
        int i = 0;
        
        while(getline(fp,s)) {
            
            split(s, ',', temp_array, 2);
            
            words[i] = temp_array[0];
            antonyms[i] = temp_array[1];
            
            
            i++;
            
        }
        
        return 0;
        
    }
    else {
        return -1;
    }
    
}

int AntonymDictionary::SearchForWord(string wordName) {
    
    int i;
    for(i = 0; i < 50; i++) {
        if(words[i] == wordName) {
            return i;
        }
    }
    
    if(i == 50) {
        return -1;
    }
}

string AntonymDictionary::GetAntonym(string wordName) {
    
    int index = -1;
    int i;
    for(i = 0; i < 50; i++) {
        if(words[i] == wordName) {
            index = i;
        }
        
        if(i == 50) {
            return "";
        }
    }
    
    return antonyms[index];
}

int main() {
    
    AntonymDictionary ant;
    
    ant.LoadWords("words.txt");
    
    cout << ant.SearchForWord("up") << endl;
    
    cout << ant.GetAntonym("slow");
    
}