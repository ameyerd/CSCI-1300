
class InvestmentProfile {
    public:
        InvestmentProfile();
        InvestmentProfile(string,float);
        void setCompanyName(string);
        string getCompanyName();
        void setSharesHeld(float);
        float getSharesHeld();
        string influence();
    
    
    private:
        string companyName;
        float sharesHeld;
    
    
};

InvestmentProfile::InvestmentProfile() {
    companyName = "Company co.";
    sharesHeld = 100.0;
}
InvestmentProfile::InvestmentProfile(string name, float shares) {
    companyName = name;
    sharesHeld = shares;
}
void InvestmentProfile::setCompanyName(string name) {
    companyName = name;
}
string InvestmentProfile::getCompanyName() {
    return companyName;
}
void InvestmentProfile::setSharesHeld(float shares) {
    sharesHeld = shares;
}
float InvestmentProfile::getSharesHeld() {
    return sharesHeld;
}
string InvestmentProfile::influence() {
    
    if (sharesHeld < 50.0) {
        return "Minority Shareholder";
    }
    else if(sharesHeld >= 50.0 && sharesHeld < 100.0) {
        return "Majority Shareholder";
    }
    else if (sharesHeld >= 100.0) {
        return "Sole Shareholder";
    }
}