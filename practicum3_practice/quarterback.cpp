class Quarterback {
    public:
        Quarterback();
        Quarterback(string,int,int,int,int,int);
        Quarterback(string);
        void setName(string);
        string getName();
        void setComp(int);
        int getComp(int);
        void setAtt(int);
        int getAtt();
        void setYards(int);
        int getYards();
        void setTD(int);
        int getTD();
        void setPick(int);
        int getPick();
        void PassCompleted(int);
        void PassAttempted();
        void Interception();
        float PasserRating();
        void Touchdown(int);
        
    private:
        string name;
        int pass_completes;
        int pass_attempts;
        int total_yards;
        int touchdowns;
        int intercepts;
    
    
};