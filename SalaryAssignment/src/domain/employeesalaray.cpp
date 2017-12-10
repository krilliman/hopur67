#include "employeesalaray.h"
#include <checkIsEmployeeValid.h>
#include <InvalidSSNException.h>
#include <InvalidSalaryExceptions.h>
#include <InvalidMonthExceptions.h>
#include <InvalidYearException.h>
#include <InvalidEmployeeName.h>
EmployeeSalaray::EmployeeSalaray()
{
}


void EmployeeSalaray::writeSalary(employee Employee)
{
    checkIsEmployeeValid validate;
    ///validate salary
    try
    {
        if(validate.checkEmployeeSNN(Employee))
        {
            throw InvalidSSNException();
        }
        else if(validate.checkSalary(Employee))
        {
            throw InvalidSalaryExceptions();
        }
        else if(validate.checkMonth(Employee))
        {
            throw InvalidMonthExceptions();
        }
        else if(validate.checkYear(Employee))
        {
            throw InvalidYearException();
        }
        else if(validate.checkEmployeeName(Employee))
        {
            throw InvalidEmployeeName();
        }
        else
        {
            EmployeeRepository employeeRepo;
            employeeRepo.writeSalary(Employee);
        }
    }
    catch(InvalidSSNException)
    {
        cout << "Invalid SSN! " <<  endl;
    }
    catch(InvalidMonthExceptions)
    {
        cout << "Invalid Month! " <<  endl;
    }
     catch(InvalidSalaryExceptions)
    {
        cout << "Invalid Salary! " <<  endl;
    }
     catch(InvalidYearException)
    {
        cout << "Invalid Year! " <<  endl;
    }
    catch(InvalidEmployeeName)
    {
        cout << "Invalid Name! " <<  endl;
    }


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
    employeeRepo.getTotalSalary(year , SSN);
}
