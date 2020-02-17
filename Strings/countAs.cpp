#include <iostream>
#include <string>
using namespace std;

// how many As, Bs, and Cs and ... Ps are in total in a given string?
int countAs(string s)
{
    int count = 0;
    if (s.length() == 0) // empty string. if (s == "")
    {
        count = -1;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 65 && s[i] <= 80) // recall the ASCII values for characters
            {
                count++;
            }
        }
    }
    return count;

}

int main()
{
    string str = "AAABBBttjtkgDHFGIERHDF";
    cout << countAs(str);
    return 0;
}






// int countAs(string x)
// {
//     if (x.length() == 0)
//     {
//         return -1;
//     }
//     int count = 0;

//     for(int i=0; i < x.length();i++)
//     {
//         if (x[i] == 'A')
//         {
//             count++;
//         }
//     }
//     return count;
// }