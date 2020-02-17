// C L A S S E S        3/4/19
// Objects have their own data associated with them, and their own functions
#include <iostream>
#include <string>
using namespace std;

class Jedi {
    // functions associated with Jedi
    public:
        void rest();    // increase the hit_points by 1
        void train();   // increase the attack strenth by 1
        int get_hit_points(); // return the Jedi's hit_points
    
    // data assocaiated with Jedi
    private;
        int hit_points;
        int attack_strength;
        double mana;
        string lightsabeer_color;
};  // SEMICOLON AFTER CLASS

// define your functions here!


int main() {
    
    
    
    return 0;
}