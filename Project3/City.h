#ifndef CITY_H
#define CITY_H
#include <iostream>
using namespace std;

class City {
    public:
        City();     // default constructor
        City(string,string,int,int,int);  // parameratized constructor
        string getCityLetter();
        string getCityName();
        int getCityMoney();
        int getCityArmySize();
        int getCityPoints();
    private:
        string cityLetter;
        string cityName;
        int cityMoney;
        int cityArmy_size;
        int cityPoints;
};

#endif