#include "adminui.h"
#include <stdlib.h>
#include <cstring>
AdminUI::AdminUI()
{
    //ctor
}


void AdminUI::startUI()
{
    char selection = '\0';
    while(selection != 'q')
    {
        cout << "** Menu **" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "1. Add new salary record" << endl;
        cout << "2. Get all salary records for given SSN" << endl;
        cout << "3. Get all salary records for given year and given SSN" << endl;
        cout << "4. Get employee with the highest salary for a given year" << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        cin >> selection;

        if(selection == '1')
        {
            EmployeeSalaray employeesalaray;
            int salaryInput;
            cout << "How many records would you like to add? ";
            cin >> salaryInput;

            for(int i = 0 ; i < salaryInput;i++)
            {
                employee newEmployee;
                cin >> newEmployee;

                cout << newEmployee << endl << endl;
                employeesalaray.writeSalary(newEmployee);
            }


        }
        else if(selection == '2')
        {
            char* SSN;
            system("CLS");
            cout << "Enter social security number: ";
            cin >> SSN;
            EmployeeSalaray employeesalaray;
            employeesalaray.readSalary(SSN);
        }
        else if(selection == '3')
        {
            string SSNstring;
            char SSN[32];
            char year[4];
            system("CLS");
            cout << "Enter social security number: ";
            cin >> SSN;

            cout << "Enter year: ";
            cin >> year;

            EmployeeSalaray employeesalaray;
            employeesalaray.getTotalSalary(year,SSN);
        }
        else if(selection == '4')
        {
            char year[20];
            system("CLS");
            cout << "Enter year: ";
            cin >> year;

            EmployeeSalaray employeesalaray;
            employeesalaray.checkHighestSalary(year);
        }
    }

}
