#ifndef EXTRASREPOSITORY_H
#define EXTRASREPOSITORY_H
#include "sideorders.h"
#include "beverages.h"

class extrasRepository
{
    public:
        extrasRepository();
        virtual ~extrasRepository();

        void writeSideOrder(SideOrders sideorder);
        SideOrders* readSOList();

        void writeBeverageToList(Beverages beverage);
        Beverages* readBevergesList();
        int getBeverageSize();


    protected:

    private:
};

#endif // EXTRASREPOSITORY_H
