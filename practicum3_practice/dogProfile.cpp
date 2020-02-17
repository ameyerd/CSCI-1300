
class DogProfile {
    
    public:
        DogProfile();
        DogProfile(string,string,float);
        void setName(string);
        string getName();
        void setTemperament(string);
        string getTemperament();
        void setBitingProbability(float);
        float getBitingProbability();
        string goodBoy();
    
    private:
        string name;
        string temperament;
        float bitingProbability;
    
};

DogProfile::DogProfile() {
    name = "Fido";
    temperament = "always wags tail";
    bitingProbability = -100.0;
}
DogProfile::DogProfile(string dogName, string dogTemp, float bite) {
    name = dogName;
    temperament = dogTemp;
    bitingProbability = bite;
}
void DogProfile::setName(string dogName) {
    name = dogName;
}
string DogProfile::getName() {
    return name;
}
void DogProfile::setTemperament(string dogTemp) {
    temperament = dogTemp;
} 
string DogProfile::getTemperament() {
    return temperament;
}
void DogProfile::setBitingProbability(float bite) {
    bitingProbability = bite;
}
float DogProfile::getBitingProbability() {
    return bitingProbability;
}
string DogProfile::goodBoy() {
    if (bitingProbability <= 1000.0) {
        return "Good Boy";
    }
    else if (bitingProbability > 1000.0) {
        return "Bad Boy";
    }
}