#ifndef CASHREGISTER_H
#define CASHREGISTER_H

/**
   A simulated cash register that tracks the item count and
   the total amount due.
 */
class CashRegister
{
public:
   CashRegister(); // default constructor
   CashRegister(double tot, int num); // parameterized constructor
   void clear();
   void addItem(double price);
   
   double getTotal() const; // const makes sure the function doesnt change anything in private
   void setTotal(double tot);
   int getNumItems()const;
   void setNumItems(int num);
public:
   double total;
   int numItems;
};

#endif
