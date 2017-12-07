#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include "employee.h"
#include <fstream>
#include <vector>
class EmployeeRepository
{
    public:
        EmployeeRepository();

        void writeSalary(employee Employee);
        void readSalary();
        void readEmployeesSalary(char* SSN);
        void checkHighestSalary(char* year);
        void getTotalSalary(char year[] , char SSN[]);
        void printSalaryVector(vector<employee> employeeVector);


    private:

        vector <employee> employeeArray;
        int listLength;
};

#endif // EMPLOYEEREPOSITORY_H
