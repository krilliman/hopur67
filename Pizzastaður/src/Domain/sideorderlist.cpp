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

void SideOrderList::setNewSideOrder(SideOrders sideorder)
{
    ///need to validate the sideOrder
    extrasRepository extraRepo;
    extraRepo.writeSideOrder(sideorder);
}

void SideOrderList::getListOfSideOrders()
{
    extrasRepository extrasRepo;
    SOList = extrasRepo.readSOList();
}
