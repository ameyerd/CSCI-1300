#include <iostream>
#include <iomanip>
#include "cashregister.h"
using namespace std;

// the implementation file
CashRegister::CashRegister()
{
   total = 0;
   numItems = 0;
}
CashRegister::CashRegister(double tot, int num)
{
   total = tot;
   numItems = num;
}
double CashRegister::getTotal() const
{
   return total;
}
void CashRegister::setTotal(double tot)
{
   total = tot;
}
int CashRegister::getNumItems() const
{
   return numItems;
}
void CashRegister::setNumItems(int num)
{
   if (num >= 0)
      numItems = num;
}
void CashRegister::clear()
{
   total = 0;
   numItems = 0;
}
void CashRegister::addItem(double price)
{
   numItems++;
   total = total + price;
}