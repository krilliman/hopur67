#include "sideorderlist.h"
#include "sideorders.h"
SideOrderList::SideOrderList()
{

        //SOList = NULL;
            //listLength = 0;
}

SideOrderList::~SideOrderList()
{/*
    if(SOList != 0)
    {
        delete[] SOList;
    }
*/
}

void SideOrderList::setSideOrderToAdd(SideOrders sideorder)
{
    sideorderToAdd = sideorder;
}

/*
void SideOrderList::setlistSize(int listSize)
{
    SOList = new SideOrders[listSize];
    listLength = listSize;
}
*/
void SideOrderList::writeList(ofstream& fout)
{
    /*
    fout.write((char*)(&listLength), sizeof(int));
    fout.write((char*)SOList, sizeof(SideOrders)*listLength);
    ///skrifar ekkert inni folerið
    */
    fout.write((char*)(&sideorderToAdd),sizeof(SideOrders));
}

void SideOrderList::readList(ifstream& ifin)
{
    SideOrders nyttSO;
        if(ifin.is_open())
        {
            ifin.seekg(0,ifin.end);
            int listSize = ifin.tellg() / sizeof(SideOrders);
            ifin.seekg(0, ifin.beg);

            //setlistSize(listSize);
            for(int i = 0; i < listSize;i++)
            {
                ifin.read((char*)(&nyttSO),sizeof(SideOrders));

                cout << nyttSO << endl <<endl;
            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }
}
/*

void SideOrderList::setSOListElements(SideOrders sideorder)
{
    if(currentSideorderNum < listLength)
    {
        SOList[currentSideorderNum] = sideorder;
        currentSideorderNum++;
    }
}
*/
