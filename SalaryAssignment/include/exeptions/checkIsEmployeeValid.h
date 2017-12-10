#ifndef CHECKISEMPLOYEEVALID_H
#define CHECKISEMPLOYEEVALID_H
#include <employee.h>

class checkIsEmployeeValid
{
    public:
        checkIsEmployeeValid();

        bool checkEmployeeName(employee Employee);
        bool checkEmployeeSNN(employee Employee);
        bool checkSalary(employee Employee);
        bool checkMonth(employee Employee);
        bool checkYear(employee Employee);

    private:
};

#endif // CHECKISEMPLOYEEVALID_H
