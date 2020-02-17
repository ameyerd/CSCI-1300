// Author: Amey Erdenebileg
// Recitation: 304 - Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
// Homework 4 - Problem 7

#include <iostream>
using namespace std;

/* 
 * Algorithm: determine if given year is a leap year
 *  1. Create a bool function with an int parameter (num)
 *  2. Define bool variable leapyear and set equal to false
 *  3. If statement - if num is greater than 1582 AND is divisble by both 100 and 400, redefine leapyear as true
 *     OR if num is greater than 1582 AND is divisible by 4 but not divisible by 100, redefine leapyear as true
 *     OR if num is less than 1582 AND num is divisible by 4, redefine leapyear as true
 * Input parameters: int num
 * Output : none
 * Returns: leapyear (0 (false), 1 (true))
*/

bool checkLeapYear(int num) {
    // define leapyear as a bool data type and set = false
    bool leapyear = false;
    
    // checks if leapyear = (greater than or equal to 1582 AND divisible by both 100 and 400), OR
    // (less than 1582 AND divisible by 4) OR (greater than or equal to 1582 AND not divisible by 100 AND divisible by 4)
   if ((num >= 1582 && (num%100 == 0 && num%400 == 0)) || (num < 1582 && num%4 == 0) || (num >= 1582 && num%100 != 0 && num%4 == 0)) {
        // if any one of those cases are true, redefine leapyear as true
        leapyear = true;
    }
    return leapyear;
}

int main() {
    // test 1
    // expected output
    // 0 (false)
    cout << checkLeapYear(1900) << endl;
    
    // test 2
    // expected output
    // 1 (true)
    cout << checkLeapYear(1616);
}