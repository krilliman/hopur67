#include "adminui.h"

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
        cout << "4. To print a name of a person with the highest salary for a given month: " << endl;

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
            EmployeeSalaray employeesalaray;
            employeesalaray.readSalary();
        }
        else if(selection == '3')
        {

        }
        else if(selection == '4')
        {

        }
    }

}
