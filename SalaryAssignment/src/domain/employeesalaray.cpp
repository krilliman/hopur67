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
void EmployeeSalaray::readSalary()///b�ta vi� SSN sem parameter h�rna
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
