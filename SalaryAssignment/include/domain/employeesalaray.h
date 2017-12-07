#ifndef EMPLOYEESALARAY_H
#define EMPLOYEESALARAY_H

#include "employee.h"
#include "employeerepository.h"

class EmployeeSalaray
{
    public:
        EmployeeSalaray();

        void writeSalary(employee Employee);
        void readSalary();///b�ta vi� SSN sem parameter
        void checkHighestSalary(char year);
        void getTotalSalary(char SSN, char salary);

    private:
        employee Employee;
};

#endif // EMPLOYEESALARAY_H
