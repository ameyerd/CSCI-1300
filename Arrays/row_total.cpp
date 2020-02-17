#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
   Computes the total of a row in a table.
   @param table: a table with N_COL number of columns
   @param row: the row that needs to be totaled
   @return the sum of all elements in the given row
*/

const int N_COL = 3;


int row_total(int table[][N_COL], int row)
{
   int total = 0;
   for (int j = 0; j < N_COL; j++)
   {
      total = total + table[row][j];
   }
   return total;
}

int main()
{
   int arr[4][3] = { { 1, 2, 3 },
                     { 5, 7, 9 },
                     { 2, 0,-1 },
                     { 4, 4, 4 }};

   // how could we print out the whole array?

   // TODO

   
   
   // and add up everything in a given row?
   int tot = row_total(arr, 1);
   cout << tot;

   // TODO
   /*
   int tot = 0;
   // say we want row = 1
   int row = 1; // <- probs an input to the function
   for (int ic = 0; ic < 3; ic++) {
      tot += arr[row][ic];  // the ic(th) element in row
   }
   cout << tot << endl;
   */

   return 0;
}
