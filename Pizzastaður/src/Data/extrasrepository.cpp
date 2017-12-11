#include "extrasrepository.h"
#include <fstream>
extrasRepository::extrasRepository()
{
    //ctor
}


void extrasRepository::writeSideOrder(SideOrders sideorder)
{
    ofstream fout;

    fout.open("Side_Order_List.dat", ios::binary|ios::app);

    fout.write((char*)(&sideorder), sizeof(SideOrders));

    fout.close();
}
///Might need to change that this function return a pointer , might not work
void extrasRepository::readSOList()
{
    ifstream fin;

    SideOrders sideorder;
    fin.open("Side_Order_List.dat", ios::binary);

    if(fin.is_open())
    {
        fin.seekg(0,fin.end);
        int listSize = fin.tellg() / sizeof(SideOrders);
        fin.seekg(0,fin.beg);

        for(int i = 0; i < listSize;i++)
        {
            fin.read((char*)(&sideorder),sizeof(SideOrders));
            vectorSideOrders.push_back(sideorder);
        }
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
vector<SideOrders> extrasRepository::SOfunctionTest(int element)
{

    vector<SideOrders> store;
    ifstream fin;

    SideOrders sideorder;
    fin.open("Side_Order_List.dat", ios::binary);

    if(fin.is_open())
    {
        fin.seekg(0,fin.end);
        int listSize = fin.tellg() / sizeof(SideOrders);
        fin.seekg(0,fin.beg);

        for(int i = 0; i < listSize;i++)
        {
            if(i == element-1)
            {
                fin.read((char*)(&sideorder),sizeof(SideOrders));
                store.push_back(sideorder);
            }
        }
    }
    else
    {
        cout << "Could not open file." << endl;
    }

    fin.close();
    return store;

}

void extrasRepository::readBevergesList()
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

                vectorBeverages.push_back(newBeverage);
            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }

    fin.close();
}
void extrasRepository::printBevergesList(vector<Beverages> vectorBeverages)
{
    for ( vector<Beverages>::iterator i = vectorBeverages.begin(); i != vectorBeverages.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
void extrasRepository::printSOList(vector<SideOrders> vectorSideOrders)
{
    for ( vector<SideOrders>::iterator i = vectorSideOrders.begin(); i != vectorSideOrders.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
void extrasRepository::printBevergesListStandard()
{
    readBevergesList();

    for ( vector<Beverages>::iterator i = vectorBeverages.begin(); i != vectorBeverages.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
int extrasRepository::printSOListStandard()
{
    readSOList();
    int counter = 1,input;
    cout << "Pick a sideOrder: " << endl;

    for ( vector<SideOrders>::iterator i = vectorSideOrders.begin(); i != vectorSideOrders.end(); ++i)
    {
        cout <<counter << ": ";
        cout << *i << ' ' << endl;

        counter++;
    }
    cin >> input;
    return input;
}
