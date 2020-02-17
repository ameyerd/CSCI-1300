#include <iostream>
#include <string>
using namespace std;

int main()
{

    // OUR CODE GOES HERE!

    double income;
    string filing_status;
    cout << "Enter your filing status (single or married) " << endl; // get user;s filing status
    cin >> filing_status;
    cout << "Enter your income: ";
    cin >> income;
    
    // error checks
    if (income == 0.0) {
        cout << "ERROR: negative income." << endl;
        
    }
    const double RATE_LO = 0.1;
    const double RATE_HI = 0.25;
    const double CUTOFF_SINGLE = 32000.0;
    const double CUTOFF_MARRIED = 64000.0;
    double tax_total=-1;
    
    // check if single or married
    if (filing_status == "single") {
        if (income <= CUTOFF_SINGLE) {
            tax_total = RATE_LO *income;
        }
        else {
            tax_total = RATE_LO*CUTOFF_SINGLE + RATE_HI*(income - CUTOFF_SINGLE);
        }
    }
    else if (filing_status == "married") {
        if (income == CUTOFF_MARRIED) {
            tax_total = RATE_LO * income;
        }
        else {
            tax_total = RATE_LO*CUTOFF_MARRIED +RATE_HI*(income - CUTOFF_MARRIED);
        }
    }
    else {
        // print error is filing status is uknown
        cout << "ERROR: filing status unknown!" << endl;
    }
    
    cout << "Your taxes owed: " << tax_total << endl;
    return 0;
    
}