#include "userInputCheck.h"

userInputCheck::userInputCheck()
{
    //ctor
}


bool userInputCheck::checkIfDigit(string input)
{
    int inputLength = input.length();
    for(int i = 0; i < inputLength;i++)
    {
        if(isdigit(input[i]))
        {
            return true;
        }
    }
    return false;
}
bool userInputCheck::checkIfAscci(string input)
{
    int inputLength = input.length();
    for(int i = 0; i < inputLength;i++)
    {
        if(!(isdigit(input[i])))
        {
            return true;
        }
    }
    return false;
}

bool userInputCheck::checkInRangeAlegg(string input)
{
    ifstream fin;

    fin.open("Topping_list.dat", ios::binary);

    if(fin.is_open())
    {
        int sizeOfList;
        fin.seekg(-4,fin.end);
        fin.read((char*)(&sizeOfList), sizeof(sizeOfList));
        fin.seekg(0,fin.beg);


        int newInput = stoi(input);
        if(newInput-1 <= sizeOfList && newInput > 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    fin.close();
}
bool userInputCheck::checkInRangeMenu(string input)
{

    ifstream fin;

    fin.open("Menu_list.dat", ios::binary);
    fin.seekg(-4,fin.end);

    if(fin.is_open())
    {
        int sizeOfList;
        fin.seekg(-4,fin.end);
        fin.read((char*)(&sizeOfList), sizeof(sizeOfList));
        fin.seekg(0,fin.beg);


        int newInput = stoi(input);
        if(newInput <= sizeOfList && newInput > 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }


        fin.close();


}
bool userInputCheck::checkInRangeCustomOrder(string input)
{
    ifstream fin;

    fin.open("Order_list.dat", ios::binary);
    fin.seekg(-4,fin.end);

    if(fin.is_open())
    {
        int sizeOfList;
        fin.seekg(-4,fin.end);
        fin.read((char*)(&sizeOfList), sizeof(sizeOfList));
        fin.seekg(0,fin.beg);


        int newInput = stoi(input);
        if(newInput-1 <= sizeOfList && newInput > 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }


    fin.close();
}
bool userInputCheck::checkInRangeBeverages(string input)
{
    ifstream fin;

    fin.open("Beverage_list.dat", ios::binary);
    fin.seekg(-4,fin.end);

    if(fin.is_open())
    {
        int sizeOfList;
        fin.seekg(-4,fin.end);
        fin.read((char*)(&sizeOfList), sizeof(sizeOfList));
        fin.seekg(0,fin.beg);


        int newInput = stoi(input);
        if(newInput-1 <= sizeOfList && newInput > 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    fin.close();
}
bool userInputCheck::checkInRangeSideOrder(string input)
{
    ifstream fin;


    fin.open("Side_Order_List.dat", ios::binary);
    if(fin.is_open())
    {
        int sizeOfList;
        fin.seekg(-4,fin.end);
        fin.read((char*)(&sizeOfList), sizeof(sizeOfList));
        fin.seekg(0,fin.beg);


        int newInput = stoi(input);
        if(newInput-1 <= sizeOfList && newInput > 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        cout << "could not open file " << endl;
    }


    fin.close();
}
bool userInputCheck::checkInRangeMenuOrder(string input)
{
    ifstream fin;


    fin.open("Order_fromMenu_list.dat", ios::binary);
    if(fin.is_open())
    {
        int sizeOfList;
        fin.seekg(-4,fin.end);
        fin.read((char*)(&sizeOfList), sizeof(sizeOfList));
        fin.seekg(0,fin.beg);


        int newInput = stoi(input);
        if(newInput-1 <= sizeOfList && newInput > 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    else
    {
        cout << "could not open file " << endl;
    }


    fin.close();
}
bool userInputCheck::checkInRangePizzaPlace(string input)
{
    ifstream fin;


    fin.open("Side_Order_List.dat", ios::binary);

    if(fin.is_open())
    {
        int sizeOfList;
        fin.seekg(-4,fin.end);
        fin.read((char*)(&sizeOfList), sizeof(sizeOfList));
        fin.seekg(0,fin.beg);


        int newInput = stoi(input);
        if(newInput-1 <= sizeOfList && newInput > 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    else
    {
        cout << "could not open file " << endl;
    }
    fin.close();
}


