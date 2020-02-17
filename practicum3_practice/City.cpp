
class ChildGrowth {
    
    public:
        ChildGrowth();
        ChildGrowth(string);
        ChildGrowth(string,int);
        ChildGrowth(string,int,float,float);
        string getName();
        void setName(string);
        int getCurrentAge();
        void setCurrentAge(int);
        void setHeight(float);
        float getHeight();
        void setWeight(float);
        float getWeight();
        float feetToMeter(float);
        float poundToKg(float);
        float calculateBmi(int);
        string getCategory(int);
    
    private:
        string name;
        int currentAge;
        float height[];
        float weight[];
        float weightMetricConversion;
    
    
};