#ifndef EMPLOYEESALARAY_H
#define EMPLOYEESALARAY_H

#include "employee.h"
#include "employeerepository.h"

class EmployeeSalaray
{
    public:
        EmployeeSalaray();

        void writeSalary(employee Employee);
        void readSalary(char* SSN);///bæta við SSN sem parameter
        void checkHighestSalary(char *year);
        void getTotalSalary(char year[], char SSN[]);

    private:
        employee Employee;
};

#endif // EMPLOYEESALARAY_H
