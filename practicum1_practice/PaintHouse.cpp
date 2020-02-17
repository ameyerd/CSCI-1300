#include <iostream>
using namespace std;

float PaintHouse(int width, int depth, int door) {
    float cost_door = 6.75 * door;
    float perimeter = 2 * (width + depth);
    float totalcost;
    
    
    if (perimeter <= 100) 
    {
        totalcost = (perimeter * 8) + cost_door;
    }
    else if (perimeter <= 200 && perimeter > 100)
    {
        totalcost = (100 * 8) + ((perimeter - 100) * 10) + cost_door;
    }
    else if (perimeter > 200) 
    {
        
        totalcost = (100 * 8) + (100 * 10) + ((perimeter -200) * 15) + cost_door;
    }
    
    
    if (width < 0 || depth < 0 || door < 0)
    {
        totalcost = -1;
    }
    
    return totalcost;

    
    
    
  
   // Total cost of painting of house = cost of painting wall + cost of painting doors and windows
}

int main() {
    cout << PaintHouse(28,48,12);
    
}