#include <iostream>
#include <vector>
using namespace std;


// helper function to display a vector
void display_vec(vector<int> vec) {
    
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    
}


int main() {
    /*
    vector<int> numbers(10); // variable name data is an EMPTY
                            // vecotr of doubles
    
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] = i + 1;
    }
    
    // display numbers vector to verify things are working
    display_vec(numbers);
    
    
    vector<int> papers;     // empty vector
    papers.push_back(3);    // pushed a 3 onto the stack of papers
    display_vec(papers);    // output : 3    
    papers.push_back(5);
    papers.push_back(1);
    papers.push_back(8);
    display_vec(papers);    // output:  3 5 1 8
    cout << papers.size() << endl;  //output : 4
    /// remove the last element using .pop_back()
    papers.pop_back();
    display_vec(papers);    // output: 3 5 1
    */
    
    // filling up vectors
    vector<int> values;
    int input;
    cout << "Enter some input: ";
    while (cin >> input) {
        values.push_back(input);
    }
    
    display_vec(values);
    
    
    return 0;
}