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
