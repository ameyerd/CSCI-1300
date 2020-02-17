#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


const int N_COL = 3;

int column_total(int table[][N_COL], int rows, int col) {
   int total = 0;
   for (int i = 0; i < rows; i++) {
      total = total + table[i][col];
   }
   return total;
}

int main()
{
   int arr[4][3] = { { 1, 2, 3 },
                     { 5, 7, 9 },
                     { 2, 0,-1 },
                     { 4, 4, 4 }};

   // Can we add up everything in a given column?

   // TODO
   int tot = column_total(arr, 4, 2);
   cout << tot << endl;

   return 0;
}
