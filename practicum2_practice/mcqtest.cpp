#include <iostream>
using namespace std;

int main() {
    
    int mymarks[10];
    int total;
    for (int cnt = 1; cnt <= 10; cnt++)
    {
      cout << "Enter the marks: ";
      cin >> mymarks[cnt];
      total = total + mymarks[cnt];
    }
    cout << total;
        
}




