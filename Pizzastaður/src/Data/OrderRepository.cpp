#include "OrderRepository.h"
#include <fstream>
OrderRepository::OrderRepository()
{
    //ctor
}


void OrderRepository::writeOrder(newOrder neworder)
{
    ofstream fout;

    fout.open("Order_list.dat", ios::binary|ios::app);

    fout.write((char*)(&neworder), sizeof(newOrder));

    fout.close();

}
void OrderRepository::readOrder()
{
    ifstream fin;

    newOrder neworder;
    fin.open("Order_list.dat", ios::binary);

    if(fin.is_open())
    {
        fin.seekg(0,fin.end);
        int listSize = fin.tellg() / sizeof(newOrder);
        fin.seekg(0,fin.beg);

        for(int i = 0; i < listSize;i++)
        {
            fin.read((char*)(&neworder),sizeof(newOrder));
            orderVector.push_back(neworder);
        }
    }
    else
    {
        cout << "Could not open file." << endl;
    }

    fin.close();
}
void OrderRepository::printOrderList()
{
    readOrder();
    for ( vector<newOrder>::iterator i = orderVector.begin(); i != orderVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
