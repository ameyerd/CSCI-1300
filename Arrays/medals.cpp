#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int N_COL = 3;  // THE DREADED GLOBAL VARIABLE - set as const so we don't eff it up.

/*
   Computes the total of a row in a table.
   @param table: a table with N_COL number of columns
   @param row: the row that needs to be totaled
   @return the sum of all elements in the given row
*/

int row_total(int table[][N_COL], int row) {
   int total = 0;
   for (int j = 0; j < N_COL; j++)
   {
      total = total + table[row][j];
   }
   return total;
}

int main() {
   const int COUNTRIES = 7;
   const int MEDALS = 3;

   string countries[] = {  "Canada", "China", "Germany", "Korea",
                           "Japan", "Russia", "United States"};

   int counts[COUNTRIES][MEDALS] = {   { 1, 0, 1 },
                                       { 1, 1, 0 },
                                       { 0, 0, 1 },
                                       { 1, 0, 0 },
                                       { 0, 1, 1 },
                                       { 0, 1, 1 },
                                       { 1, 1, 0 }};

   cout << "        Country    Gold  Silver  Bronze   Total" << endl;

   // Print countries, counts, and row totals
   for (int i = 0; i < COUNTRIES; i++)
   {
      cout << setw(15) << countries[i];
      // Process the ith row
      for (int j = 0; j < MEDALS; j++)
      {
         cout << setw(8) << counts[i][j];
      }
      int total = row_total(counts, i);
      cout << setw(8) << total << endl;
   }

   return 0;
}
