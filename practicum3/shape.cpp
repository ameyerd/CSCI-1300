#include <iostream>
using namespace std;

class Shape {
    
    public:
        Shape();
        Shape(string,int);
        string getName();
        void setName(string);
        int getSides();
        void setSides(int);
        string getShapeType();
    
    private:
        string name;
        int sides;
};

Shape::Shape() {
    name = "";
    sides = 3;
}
Shape::Shape(string nam, int sid) {
    name = nam;
    sides = sid;
}
string Shape::getName() {
    return name;
}
void Shape::setName(string nam) {
    name = nam;
}
int Shape::getSides() {
    return sides;
}
void Shape::setSides(int sid) {
    sides = sid;
}
string Shape::getShapeType() {
    if(sides == 3) {
        return "Triangle";
    }
    else if (sides == 4) {
        return "Rectangle";
    }
    else if (sides == 5) {
        return "Pentagon";
    }
    else if (sides >= 6) {
        return "Polygon";
    }
}
