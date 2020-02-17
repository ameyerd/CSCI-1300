#include <iostream>
#include <iomanip>
using namespace std;

void fillup(int arr[], int size) {  // first argument is an array, second argument is its size (length)
   for (int i=0; i < size; i++) {
      arr[i] = i*2;
   }
}                                   // no return, because arrays are passed by memory reference

int main()
{
   int score[] = { -1, -1, -1, -1, -1 };
   int numberOfScores = 5;
   fillup(score, numberOfScores);

   for (int k=0; k<numberOfScores; k++) {
      cout << setw(4) << k << setw(4) << score[k] << endl;  // note that score is no longer so negative
   }

   cout << "-------------------------" << endl;

   // do a similar thing for time[] here!

   // TODO...

   return 0;
}
