#include "extrasrepository.h"
#include <fstream>
#include <userInputCheck.h>
extrasRepository::extrasRepository()
{
    //ctor
}


void extrasRepository::writeSideOrder(SideOrders sideorder)
{
    readSOList();
    ofstream fout;

    fout.open("Side_Order_List.dat", ios::binary|ios::app);

    int sideOrderVectorSize = this->vectorSideOrders.size() + 1;

    sideorder.writeSideOrder(fout);

    fout.write((char*)(&sideOrderVectorSize),sizeof(sideOrderVectorSize));

    fout.close();
}


void extrasRepository::readSOList()
{
    ifstream fin;

    fin.open("Side_Order_List.dat", ios::binary);

    if(fin.is_open())
    {

        fin.seekg(0,fin.end);
        int testSize = fin.tellg();
        fin.seekg(0,fin.beg);
        if(testSize == 0)
        {

        }
        else
        {

          int listSize;
          fin.seekg(-4,fin.end);
          fin.read((char*)(&listSize), sizeof(listSize));
          fin.seekg(0,fin.beg);

            //cout << "List Size: " << listSize << endl;
            for(int i = 0; i < listSize;i++)
            {
                SideOrders sideorder;

                sideorder.readSideOrder(fin);

                int sideorderNum;
                fin.read((char*)(&sideorderNum), sizeof(sideorderNum));

                this->vectorSideOrders.push_back(sideorder);

            }
        }
    }
    else
    {
        //cout << "Could not open file." << endl;
    }

    fin.close();
}

void extrasRepository::writeBeverageToList(Beverages beverage)
{
    readBevergesList();
    ofstream fout;

    fout.open("Beverage_list.dat", ios::binary|ios::app);

    int beverageVectorSize = this->vectorBeverages.size()+1;

    beverage.writeBeverage(fout);

    fout.write((char*)(&beverageVectorSize), sizeof(beverageVectorSize));


    fout.close();
}
SideOrders extrasRepository::getSideOrderFromList(int element)
{
    SideOrders newSideorder;
    newSideorder = this->vectorSideOrders[element-1];
    return newSideorder;

}
Beverages extrasRepository::getBeverageFromList(int element)
{
    Beverages newBeverage;
    newBeverage = this->vectorBeverages[element-1];
    return newBeverage;
}

void extrasRepository::readBevergesList()
{
    ifstream fin;

    fin.open("Beverage_list.dat", ios::binary|ios::app);
        if(fin.is_open())
        {
            fin.seekg(0,fin.end);
            int testSize = fin.tellg();
            fin.seekg(0,fin.beg);
            if(testSize == 0)
            {

            }
            else
            {

              int listSize;
              fin.seekg(-4,fin.end);
              fin.read((char*)(&listSize), sizeof(listSize));
              fin.seekg(0,fin.beg);

                for(int i = 0; i < listSize;i++)
                {
                    Beverages newBeverage;

                    newBeverage.readBeverage(fin);
                    int beverageNum;
                    fin.read((char*)(&beverageNum), sizeof(beverageNum));

                    this->vectorBeverages.push_back(newBeverage);

                }
            }
        }
        else
        {
            //cout << "Could not open file." << endl;
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
int extrasRepository::printBevergesListStandard()
{
    userInputCheck newuserInput;
    readBevergesList();

    string input;
    int newInput;
    int newCounter = 0;
    while(newCounter == 0)
    {
        int counter = 1;
        cout << "Please choose a beverage: " << endl;
        cout << "-------------------------------------------------------" << endl;
        for ( vector<Beverages>::iterator i = vectorBeverages.begin(); i != vectorBeverages.end(); ++i)
        {
            cout << " * " << counter << " * : ";
            cout << *i << ' ' << endl;
            cout << "-------------------------------------------------------" << endl;
            counter++;
        }
        cin >> input;
        cout << "-------------------------------------------------------" << endl;
        if(newuserInput.checkInRangeBeverages(input) == true)
        {
            newInput = stoi(input);
            newCounter++;
        }
        else
        {
          //cout << "invalid input " << endl;
        }


    }
    return newInput;

}
int extrasRepository::printSOListStandard()
{
    userInputCheck newuserInput;
    readSOList();

    string input;
    int newInput;
    int newCounter = 0;
    while(newCounter == 0)
    {
        int counter = 1;
    cout << "Please choose a side: " << endl;
    cout << "-------------------------------------------------------" << endl;

    for ( vector<SideOrders>::iterator i = vectorSideOrders.begin(); i != vectorSideOrders.end(); ++i)
    {
        cout << " * " <<counter << " * : ";
        cout << *i << ' ' << endl;
        cout << "-------------------------------------------------------" << endl;

        counter++;
    }
    cin >> input;
    cout << "-------------------------------------------------------" << endl;
        if(newuserInput.checkInRangeSideOrder(input) == true)
        {
            newInput = stoi(input);
            newCounter++;
        }
        else
        {
          cout << "invalid input " << endl;
        }
    }
    return newCounter;
}
