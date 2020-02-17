/*  CS1300 Spring 2019
    Author: Amey Erdenebileg
    Recitation: 304 - Shudong Hao
    Cloud 9 Workspace Editor Link: https://ide.c9.io/ameyerd/csci1300
    Homework 3 - Problem 8
*/

#include <iostream>
using namespace std;

/* 
 * Algorithm: Create a function that calculates the new population after a year
 *  1. Create an int function that has an int parameter for initial population
 *  2. Create int variables for births, deaths, immigrants and seconds in a year
 *  3. Create int variables that calculates births, deaths, and immigrants in one year
 *  4. Create int variable for new population that calculates the new population after a year
 *  5. Return answewer
 * Input parameters: int, pop (initial population)
 * Output : none
 * Returns: new_population
*/

int population(int pop) {
    // define all variables first
    int birth = 8;
    int death = 12;
    int immigrant = 27;
    int sec_one_year = 365*24*60*60;
    // These variables calculate the births, deaths and immigrants in one year
    int births_one_year = sec_one_year / birth;
    int deaths_one_year = sec_one_year / death;
    int immigrant_one_year = sec_one_year / immigrant;
    // This variable adds the births and immigrants then subtracts the death to get the new population
    int new_population = pop + births_one_year + immigrant_one_year - deaths_one_year;
    //return new population
    return new_population;

}

int main() {
    // test 1
    // expected output
    // 3482000
    cout << population(1000000) << endl;
    
    // test 2
    // expected output
    // 203821383
    cout << population(201339383);
}