#ifndef EXTRASREPOSITORY_H
#define EXTRASREPOSITORY_H
#include "sideorderlist.h"
#include "beverages.h"

class extrasRepository
{
    public:
        extrasRepository();
        virtual ~extrasRepository();

        void writeSideOrder(SideOrderList sideorderlist);
        SideOrderList readSOList();

        void writeBeverageToList(Beverages beverage);
        Beverages readBevergesList();
        int getBeverageSize();


    protected:

    private:
};

#endif // EXTRASREPOSITORY_H
