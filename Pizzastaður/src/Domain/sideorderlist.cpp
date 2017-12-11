#include "sideorderlist.h"
#include "sideorders.h"

SideOrderList::SideOrderList()
{

}
SideOrderList::~SideOrderList()
{

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
    extrasRepo.printSOListStandard();
}
