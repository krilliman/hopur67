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
        void readSalary();///b�ta SSN h�rna vi�
        void checkHighestSalary(char year);
        void getTotalSalary(char SSN , char name);
        void printSalaryVector();


    private:

        vector <employee> employeeArray;
        int listLength;
};

#endif // EMPLOYEEREPOSITORY_H
