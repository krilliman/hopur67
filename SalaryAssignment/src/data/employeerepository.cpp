#include "employeerepository.h"
#include <algorithm>
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
void EmployeeRepository::printSalaryVector(vector<employee> employeeVector)
{
    for ( vector<employee>::iterator i = employeeVector.begin(); i != employeeVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}


void EmployeeRepository::checkHighestSalary(char* year)
{
    int higestSalary = 0;
    char* name = '\0';
    readSalary();
    int newYear = atoll(year);
    for(int i = 0; i < employeeArray.size();i++)
    {
        int arrayYear =  atoll(employeeArray[i].getYear());
        if(newYear == arrayYear)
        {
            int arraySalary = atoll(employeeArray[i].getAmount());
            if(arraySalary > higestSalary)
            {
                name = '\0';
                name = employeeArray[i].getName();
                higestSalary = arraySalary;
            }
        }
    }
    cout << "Name of the person with the Highest total salary in " << newYear << " is: " << name << endl;
}

void EmployeeRepository::readEmployeesSalary(char* SSN)
{
    vector<employee> givenEmployee;
    readSalary();
    int value1 = atoll(SSN);
    for(int i = 0; i < employeeArray.size();i++)
    {
        int value2 = atoll(employeeArray[i].getSSN());
        if(value1 == value2)
        {
            cout << "match " << endl;
            givenEmployee.push_back(employeeArray[i]);
        }
    }
    printSalaryVector(givenEmployee);

}
void EmployeeRepository::getTotalSalary(char year[] , char SSN[])
{

    int totalSalary = 0;
    readSalary();
    cout << "before atoll" << SSN << endl << endl << endl;
    int newSSN = atoi(SSN);
    int newYear = atoll(year);

    for(int i = 0; i < employeeArray.size();i++)
    {
        int arrayYear = atoll(employeeArray[i].getYear());
        int arraySSN = atoi(employeeArray[i].getSSN());
        cout << "test SSN: " << newSSN << endl;
        cout << "test year: " << newYear << endl;
        cout << "file SSN: " << arraySSN << endl;
        cout << "file year: " << arrayYear << endl << endl;

        if(newSSN == arraySSN && newYear == arrayYear)
        {
            cout << "match" << endl;
            int arrayAmount = atoll(employeeArray[i].getAmount());
            totalSalary += arrayAmount;
        }

    }
    cout << "Total salary is: " << totalSalary << endl;

}
