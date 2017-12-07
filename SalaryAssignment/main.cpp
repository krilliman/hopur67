#include <iostream>
#include <adminui.h>
using namespace std;

///UI
///Admin

///Models
///employee(SSN, name)

///Domain
///employee's salary(amount , month, year.... void checkEmployeeName(), void checkEmployeeSNN(), void checkSalary(), void checkSalaryDate())



///Respositories
///employee's Respository(void writeSalary(), void readSalary(), void checkHighestSalary(), void getTotalSalary());



int main()
{
    AdminUI adminui;

    adminui.startUI();
    return 0;
}
