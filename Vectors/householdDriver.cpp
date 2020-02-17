#include <iostream>
#include <string>
#include <vector>
#include "household.h"
using namespace std;

int main() {

   // Testing the default constructor
   Household h1;
   h1.display();

   // Testing the setter functions
   h1.setName("Fleming");
   h1.setIncome(123.45);
   h1.display();

   // Testing the parameterized constructor
   Household h2("wong", 34);
   h2.display();

   // Building up methods for the Neighborhood class:  make a vector of Households
   vector<Household> hood;
   hood.push_back(h1);
   hood.push_back(h2);

   // give us a nice line to separate the makeshift Neighborhood
   cout << endl << "-----------------" << endl << endl;

   // Display -- this should be a member function of the Neighborhood class
   //            because IT IS ANNOYING to keep making for loops like a CHUMP.
   for (int i = 0; i < hood.size(); i++) {
      hood[i].display();
   }

   return 0;
}