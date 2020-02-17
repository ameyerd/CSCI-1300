#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   //int size = 100;
   //double values[size]
   const int CAPACITY = 10;
   double values[CAPACITY]; // declaration
   values[4] = 17.7;
   // double values[10]; 
   // double values[] = {32, 54, 57, 29, 35, 115, 44.5}
   // cout << values << ednl; WONT WORK! (use loop)
   // for (int i= 0; i < 10; i++)
   //    {
   //       cout << values [i] << endl;
   //    }

   for (int i = 0; i < CAPACITY; i++)
   {
      values[i] = (i + 1) * (i + 1);
      cout << setw(4) << i << setw(4) << values[i] << endl;
   }
   return 0;
}

// an array is a collection of data of the same type, referenced as different elements
// of the same name