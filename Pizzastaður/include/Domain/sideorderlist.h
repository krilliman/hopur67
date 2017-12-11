#ifndef SIDEORDERLIST_H
#define SIDEORDERLIST_H
#include "sideorders.h"
#include "extrasrepository.h"
#include <fstream>

class SideOrderList
{
    public:
        SideOrderList();
       void setNewSideOrder(SideOrders sideorder);
       void getListOfSideOrders();

       SideOrders getOutOfSideOrderList();



    protected:

    private:
};

#endif // SIDEORDERLIST_H
