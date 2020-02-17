#include <iostream>
#include <string>
using namespace std;

int main()
{
    string my_str;
    cout << "Enter a string plz: ";
    cin >> my_str;

    string char_to_find = "f";
    bool found = false;
    int position = 0;
    while (position < my_str.length())
    {
       string ch = my_str.substr(position, 1);
       if (ch == char_to_find)
       {
          found = true;
          break;
       }
       else
       {
          position++;
       }
    }

    if (found) {
        cout << "Found! At position: " << position << endl;
    } else {
        cout << "Not found. Womp womp. Position is " << position << endl;
    }

    return 0;
}