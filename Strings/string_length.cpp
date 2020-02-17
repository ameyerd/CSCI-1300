#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "hello";
    // count how many 'l's

    int i = 0;
    int count  = 0;
    while (i < s1.length())
    {
        if (s1[i] == 'l') // or if(s1[i] == 108)
        {
            count ++;
        }
        cout << s1[i] << endl;
        i++;
    }
    // for loop equivalent
    for (i=0; i < s1.length(); i++)
    {
        cout << s1[i];
    }
    cout << "\nthe number of occurences of the letter 'l' is: " << count << endl;
    return 0;
}