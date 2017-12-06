#include "extrasrepository.h"
#include <fstream>
extrasRepository::extrasRepository()
{
    //ctor
}

extrasRepository::~extrasRepository()
{
    //dtor
}


void extrasRepository::writeSideOrder(SideOrders sideorder)
{
    ofstream fout;

    fout.open("Side_Order_List.dat", ios::binary|ios::app);

    fout.write((char*)(&sideorder), sizeof(SideOrders));

    fout.close();
}
///Might need to change that this function return a pointer , might not work
SideOrders* extrasRepository::readSOList()
{
    ifstream fin;

    SideOrders sideorder;
    fin.open("Side_Order_List.dat", ios::binary);

    if(fin.is_open())
    {
        fin.seekg(0,fin.end);
        int listSize = fin.tellg() / sizeof(SideOrders);
        fin.seekg(0,fin.beg);

        SideOrders sideorderArray[listSize];

        for(int i = 0; i < listSize;i++)
        {
            fin.read((char*)(&sideorder),sizeof(SideOrders));

            sideorderArray[i] = sideorder;
            cout << sideorder << endl << endl;
        }
        return sideorderArray;
    }
    else
    {
        cout << "Could not open file." << endl;
    }

    fin.close();
}

void extrasRepository::writeBeverageToList(Beverages beverage)
{
    ofstream fout;

    fout.open("Beverage_list.dat", ios::binary|ios::app);

    fout.write((char*)(&beverage),sizeof(Beverages));

    fout.close();
}

Beverages* extrasRepository::readBevergesList()
{
    ifstream fin;

    Beverages newBeverage;

    fin.open("Beverage_list.dat", ios::binary|ios::app);
        if(fin.is_open())
        {
            fin.seekg(0,fin.end);
            int listSize = fin.tellg() / sizeof(Beverages);
            fin.seekg(0, fin.beg);
            Beverages arrayOfBeverages[listSize];

            for(int i = 0; i < listSize;i++)
            {
                fin.read((char*)(&newBeverage),sizeof(Beverages));

                arrayOfBeverages[i] = newBeverage;
                cout << newBeverage;
            }
            return arrayOfBeverages;
        }
        else
        {
            cout << "Could not open file." << endl;
        }

    fin.close();
}
int extrasRepository::getBeverageSize()
{
    int listSize;
    ifstream fin;

    fin.open("Beverage_list.dat", ios::binary|ios::app);

    fin.seekg(0,fin.end);
    listSize = fin.tellg() / sizeof(Beverages);
    fin.seekg(0, fin.beg);

    fin.close();

    return listSize;
}

