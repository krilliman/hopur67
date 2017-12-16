#include "sideorderlist.h"
#include "sideorders.h"

SideOrderList::SideOrderList()
{

}

void SideOrderList::setNewSideOrder(SideOrders sideorder)
{
    ///need to validate the sideOrder
    extrasRepository extraRepo;
    extraRepo.writeSideOrder(sideorder);
}
///can remove this function ?
void SideOrderList::getListOfSideOrders()
{
    int input;
    extrasRepository extrasRepo;
    input = extrasRepo.printSOListStandard();

}

SideOrders SideOrderList::getOutOfSideOrderList()
{

    int input;
    extrasRepository extrasRepo;
    input = extrasRepo.printSOListStandard();
    SideOrders newSideorder;
    newSideorder = extrasRepo.getSideOrderFromList(input);

    return newSideorder;
}
