#include "checkIsEmployeeValid.h"
#include <string>
#include <cstdlib>

checkIsEmployeeValid::checkIsEmployeeValid()
{
    //ctor
}

bool checkIsEmployeeValid::checkEmployeeName(employee Employee)
{
    string newString;
    newString = Employee.getName();
    for(int i = 0; i < newString.size();i++)
    {
        if(isdigit(newString[i]))
        {
            return true;
        }
    }
    return false;

}
bool checkIsEmployeeValid::checkEmployeeSNN(employee Employee)
{
    char *SSN = Employee.getSSN();
    int newSSN = atoi(Employee.getSSN());

    string testSSN = SSN;


    int SSNsize = testSSN.size();
    if(SSNsize == 10)
    {
        for(int i = 0;i < 10;i++)
        {
            if(!isdigit(SSN[i]))
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}
bool checkIsEmployeeValid::checkSalary(employee Employee)
{
    int newInt = atoi(Employee.getAmount());
    if(newInt < 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool checkIsEmployeeValid::checkMonth(employee Employee)
{
    int newMonth = atoi(Employee.getMonth());
    if(newMonth < 1 || newMonth > 12)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkIsEmployeeValid::checkYear(employee Employee)
{
    int newYear = atoi(Employee.getYear());
    if(newYear > 2017 || newYear < 1000)
    {
        return true;
    }
    else
    {
        return false;
    }
}


