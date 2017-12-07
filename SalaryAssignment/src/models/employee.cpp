#include "employee.h"

employee::employee()
{
    name[0] = '\0';
    SSN[0] = '\0';
    year[0] = '\0';
    month[0] = '\0';
    amount[0] = '\0';

}


char* employee::getName()
{
    return this->name;
}
/*
char employee::getSSN()
{
    return (SSN&);
}
*/
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
    cout << "Enter name of employee: ";
    in >> Employee.name;
    cout << endl;
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