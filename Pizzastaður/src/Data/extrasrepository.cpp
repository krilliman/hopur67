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


void extrasRepository::writeSideOrder(SideOrderList sideorderlist)
{
    ofstream fout;

    fout.open("Side_Order_List.dat", ios::binary|ios::app);
    sideorderlist.writeList(fout);
    fout.close();
}

SideOrderList extrasRepository::readSOList()
{
    ifstream fin;


    fin.open("Side_Order_List.dat", ios::binary|ios::app);
    SideOrderList SOList;

    SOList.readList(fin);

    fin.close();
}

void extrasRepository::writeBeverageToList(Beverages beverage)
{
    ofstream fout;

    fout.open("Beverage_list.dat", ios::binary|ios::app);

    fout.write((char*)(&beverage),sizeof(Beverages));

    fout.close();
}

Beverages extrasRepository::readBevergesList()
{
    ifstream fin;

    Beverages newBeverage;

    fin.open("Beverage_list.dat", ios::binary|ios::app);
        if(fin.is_open())
        {
            fin.seekg(0,fin.end);
            int listSize = fin.tellg() / sizeof(Beverages);
            fin.seekg(0, fin.beg);

            //setlistSize(listSize);
            for(int i = 0; i < listSize;i++)
            {
                fin.read((char*)(&newBeverage),sizeof(Beverages));

                return newBeverage;
            }
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

