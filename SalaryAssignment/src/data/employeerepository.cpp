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
    int counter = 0;
    int higestSalary = 0;
    char* name = '\0';
    readSalary();
    int newYear = atoll(year);
    for(int i = 0; i < employeeArray.size();i++)
    {
        int arrayYear =  atoll(employeeArray[i].getYear());
        if(newYear == arrayYear)
        {
            counter++;
            int arraySalary = atoll(employeeArray[i].getAmount());
            if(arraySalary > higestSalary)
            {
                name = '\0';
                name = employeeArray[i].getName();
                higestSalary = arraySalary;
            }
        }
    }
    if(counter == 0)
    {
        cout << "------------------------------------------------------------------" << endl;
        cout << "There are no records available for the year: " << newYear << endl;
        cout << "------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "------------------------------------------------------------------" << endl;
        cout << "The person with the highest total salary in " << newYear << " is: " << name << endl;
        cout << "------------------------------------------------------------------" << endl;
    }

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
            givenEmployee.push_back(employeeArray[i]);
        }
    }
    printSalaryVector(givenEmployee);

}
void EmployeeRepository::getTotalSalary(char year[] , char SSN[])
{

    int totalSalary = 0;
    readSalary();
    int newSSN = atoi(SSN);
    int newYear = atoll(year);

    for(int i = 0; i < employeeArray.size();i++)
    {
        int arrayYear = atoll(employeeArray[i].getYear());
        int arraySSN = atoi(employeeArray[i].getSSN());

        if(newSSN == arraySSN && newYear == arrayYear)
        {
            int arrayAmount = atoll(employeeArray[i].getAmount());
            totalSalary += arrayAmount;
        }

    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "Total salary is: " << totalSalary << endl;
    cout << "------------------------------------------------------------------" << endl;

}
