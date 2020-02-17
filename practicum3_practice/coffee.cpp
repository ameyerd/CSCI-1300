
class Coffee {
    
    public:
        Coffee();
        Coffee(string,float);
        string getRoastType();
        void setRoastType(string);
        float getTemp();
        void setTemp(float);
        string drinkability();
        
    
    private:
        string roastType;
        float temp;
    
    
};

Coffee::Coffee() {
    roastType = "";
    temp = 180.0;
    
}
Coffee::Coffee(string roast, float temper) {
    roastType = roast;
    temp = temper;
}
string Coffee::getRoastType() {
    return roastType;
}
void Coffee::setRoastType(string type) {
    roastType = type;
}
float Coffee::getTemp() {
    return temp;
}
void Coffee::setTemp(float temper) {
    temp = temper;
}
string Coffee::drinkability() {
    
    if (temp < 100.0) {
        return "Too Cold";
    }
    else if (temp >= 100.0 && temp < 160.0) {
        return "Just Right";
    }
    else if (temp >= 160.0 && temp < 180.0) {
        return "Hot";
    }
    else if (temp >= 180.0) {
        return "Too Hot";
    }
    
}