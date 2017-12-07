#include "adminui.h"
#include <stdlib.h>
AdminUI::AdminUI()
{
    //ctor
}


void AdminUI::startUI()
{
    char selection = '\0';
    while(selection != 'q')
    {
        cout << "1. To add salary: " << endl;
        cout << "2. To print info for a given SSN: " << endl;
        cout << "3. To print total salary for a given month and SSN: " << endl;
        cout << "4. To print a name of a person with the highest salary for a given year: " << endl;

        cin >> selection;

        if(selection == '1')
        {
            EmployeeSalaray employeesalaray;
            int salaryInput;
            cout << "How many salary's would you like to add ? ";
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
            cout << "Enter a SSN: ";
            cin >> SSN;
            EmployeeSalaray employeesalaray;
            employeesalaray.readSalary(SSN);
        }
        else if(selection == '3')
        {
            char SSN[10];
            char year[4];
            system("CLS");
            cout << "Enter a given SSN: ";
            cin >> SSN;

            cout << "Enter a given Year: ";
            cin >> year;

            EmployeeSalaray employeesalaray;
            employeesalaray.getTotalSalary(year,SSN);
        }
        else if(selection == '4')
        {
            char year[20];
            system("CLS");
            cout << "Enter a year: ";
            cin >> year;

            EmployeeSalaray employeesalaray;
            employeesalaray.checkHighestSalary(year);
        }
    }

}
