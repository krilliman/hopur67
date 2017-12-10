#include "employee.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

employee::employee()
{
    name[0] = '\0';
    SSN[0] = '\0';
    year[0]= '\0';
    month[0] = '\0';
    amount[0] = '\0';
}


char* employee::getName()
{
    return this->name;
}

char* employee::getSSN()
{
    return this->SSN;
}
char* employee::getYear()
{
    return this->year;
}
char* employee::getMonth()
{
    return this->month;
}
char* employee::getAmount()
{
    return this->amount;
}



ostream& operator <<(ostream& out, const employee Employee)
{
    cout << "Name of the employee: ";
    out << Employee.name << endl;

    cout << "Employee's SSN: ";
    out << Employee.SSN << endl;

    cout << "-- Employees salary --" << endl;
    out << Employee.month << "." << Employee.year << ": " << Employee.amount << endl;

    return out;
}
istream& operator >>(istream& in, employee& Employee)
{

    string temp;
    cout << "Enter name of employee: ";
    in >> Employee.name;
    cout << endl;

    //Employee.name = (char *)malloc(temp.size() + 1);
    //memcpy(Employee.name, temp.c_str(), temp.size() + 1);

    cout << "Enter SSN of the employee: ";
    in >> Employee.SSN;
    cout << endl;

    cout << "Enter year for a given salary: ";
    in >> Employee.year;
    cout << endl;

    cout << "Enter the month for a given salary: ";
    in >> Employee.month;
    cout << endl;

    cout << "Enter the amount: ";
    in >> Employee.amount;
    cout << endl;

    return in;
}
