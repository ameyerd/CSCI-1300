#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include <iostream>
#include <string>
using namespace std;

class Household {
   public:
      Household();               // default constructor
      Household(string, double); // parameterized constructor
      double getIncome();        // returns the household income
      string getName();          // returns the household name
      void setIncome(double);    // sets the household income
      void setName(string);      // sets the household name
      void display();            // display the household details
   private:
      string name;               // household name
      double income;             // household income
};

#endif
