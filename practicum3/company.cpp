#include <iostream>
using namespace std;


class Company {
    public:
        Company();
        Company(string);
        bool AddEmployee(string, int);
        double CalcAvgSalaries();
        int getMaxSalary();
        int CountSameNames(string);
    
    private:
        string companyName;
        vector<string> EmployeeNames;
        vector<int> EmployeeSalary;
};