#include <iostream>
using namespace std;

int main()
{
    // multiplication table for 1 through 8
    // 1 2 3 ... 10
    // 2 4 6 ... 20
    // ...
    // 8 16 24 ...80
    
    // Option 2: multiplication
    int i = 1;
    int j = 1; /// 1, 2, ... 10
    while(j <= 8)
    {
        i = 1;
        while(i<=10)
        {
            cout << i * j << " ";
            i++;
        }
        cout << endl;
        j++;
    } 
    
    return 0;
}
