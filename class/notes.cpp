#include <iostream>
#include <math.h>
using namespace std;

int main() {
    /*cout << "How many sides does your polygon have? ";
    int n_sides;
    cin >> n_sides;
    // let the user know what that shape is called
    // define a boolean variable for whether it's a triangle
    bool is_triangle = n_sides==3;
    cout << is_triangle << endl;
    if (n_sides==3) {
        cout << "Triangle" << endl;
    }
    else {
        cout << "No triangle" << endl;
    }
    return 0;
    */
   
   
int i = 60;
int j = 50;
int count = 0;
while (count < 5)
{
   i = i + i;
   i = i + 1;
   j = j - 1;
   j = j - j;
   count++;
}
cout << i<< endl << j;

}