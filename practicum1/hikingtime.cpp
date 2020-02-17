#include <iostream>
using namespace std;

// the function will calculate the number of hours it takes to hike the distance, and will return that time, as type double
double hikingTime(double distance, double elevation)
 {
     //hours = (1/3.0)*distance + (1/2000)*(elevation change
     
     double hours = (distance * 1/3) + ((0.0005) * elevation);
     
     if (hours < 0.0)
     {
         hours = distance / 5;
         
     }
     
     return hours;
 }


int main() 
{
    cout << hikingTime(4.1,1300.0);
}