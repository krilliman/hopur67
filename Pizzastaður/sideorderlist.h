#ifndef SIDEORDERLIST_H
#define SIDEORDERLIST_H
#include "sideorders.h"
#include <fstream>

class SideOrderList
{
    public:
        SideOrderList();
        virtual ~SideOrderList();

        void writeList(ofstream& fout);
        void readList(ifstream& fin);

        //void setlistSize(int listSize);

        //void setSOListElements(SideOrders sideorder);

        void setSideOrderToAdd(SideOrders sideorder);

    protected:

    private:
        SideOrders sideorderToAdd;
        //SideOrders *SOList;
        //int listLength;
        //int currentSideorderNum;
};

#endif // SIDEORDERLIST_H
