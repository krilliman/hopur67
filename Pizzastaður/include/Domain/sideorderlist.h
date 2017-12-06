#ifndef SIDEORDERLIST_H
#define SIDEORDERLIST_H
#include "sideorders.h"
#include "extrasrepository.h"
#include <fstream>

class SideOrderList
{
    public:
        SideOrderList();
        virtual ~SideOrderList();

       void setNewSideOrder(SideOrders sideorder);
       void getListOfSideOrders();



    protected:

    private:
        SideOrders sideorderToAdd;
        SideOrders *SOList;
        int listLength;
};

#endif // SIDEORDERLIST_H
