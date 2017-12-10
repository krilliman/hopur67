#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;


class employee
{
    public:
        employee();


        char* getName();
        char* getSSN();
        char* getYear();
        char* getMonth();
        char* getAmount();

        friend ostream& operator <<(ostream& out,const employee Employee);
        friend istream& operator >>(istream& in, employee& Employee);

    private:

        char name[32];
        char SSN[32];
        char year[32];
        char month[32];
        char amount[32];

};

#endif // EMPLOYEE_H
