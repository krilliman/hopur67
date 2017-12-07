#include "employeerepository.h"

EmployeeRepository::EmployeeRepository()
{
    //ctor
}


void EmployeeRepository::writeSalary(employee Employee)
{
    ofstream fout;

    fout.open("employee_list.dat", ios::binary|ios::app);

    fout.write((char*)(&Employee), sizeof(employee));

    fout.close();
}
void EmployeeRepository::readSalary()
{
    ifstream fin;
    employee printEmpoyee;

    fin.open("employee_list.dat", ios::binary);

    if(fin.is_open())
    {
        fin.seekg(0,fin.end);
        int listSize = fin.tellg() / sizeof(employee);
        fin.seekg(0, fin.beg);

        this->listLength = listSize;

        for(int i = 0; i < listSize;i++)
        {
            fin.read((char*)(&printEmpoyee), sizeof(employee));

            employeeArray.push_back(printEmpoyee);

        }
    }

    fin.close();
}
void EmployeeRepository::printSalaryVector()
{
    for ( vector<employee>::iterator i = employeeArray.begin(); i != employeeArray.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
void EmployeeRepository::checkHighestSalary(char year)
{

}
void EmployeeRepository::getTotalSalary(char SSN , char name)
{

}
