#include "employeesalaray.h"

EmployeeSalaray::EmployeeSalaray()
{
}


void EmployeeSalaray::writeSalary(employee Employee)
{
    ///validate salary

    EmployeeRepository employeeRepo;

    employeeRepo.writeSalary(Employee);
}
void EmployeeSalaray::readSalary()///bæta við SSN sem parameter hérna
{
    ///validate salary

    EmployeeRepository employeeRepo;
    employeeRepo.readSalary();
    employeeRepo.printSalaryVector();
}

void EmployeeSalaray::checkHighestSalary(char year)
{



}
void EmployeeSalaray::getTotalSalary(char SSN, char salary)
{

}
