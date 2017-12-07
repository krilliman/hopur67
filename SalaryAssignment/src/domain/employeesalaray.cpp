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
void EmployeeSalaray::readSalary(char* SSN)
{
    ///validate salary

    EmployeeRepository employeeRepo;
    employeeRepo.readEmployeesSalary(SSN);

}

void EmployeeSalaray::checkHighestSalary(char* year)
{

    EmployeeRepository employeeRepo;
    employeeRepo.checkHighestSalary(year);

}
void EmployeeSalaray::getTotalSalary(char year[], char SSN[])
{

    ///need to validate the SSN and Year
    EmployeeRepository employeeRepo;
    cout << "In domain: " << SSN << endl << endl;
    employeeRepo.getTotalSalary(year , SSN);
}
void EmployeeSalaray::printSalary()
{
    EmployeeRepository employeeRepo;
    //employeeRepo.printSalaryVector();
}
