#ifndef EXTRASREPOSITORY_H
#define EXTRASREPOSITORY_H
#include "sideorders.h"
#include "beverages.h"
#include <vector>
class extrasRepository
{
    public:
        extrasRepository();

        void writeSideOrder(SideOrders sideorder);
        void readSOList();
        void printSOList(vector<SideOrders> vectorSideOrders);///can remove this function
        int printSOListStandard();
        SideOrders getSideOrderFromList(int element);


        void writeBeverageToList(Beverages beverage);
        void readBevergesList();
        void printBevergesList(vector<Beverages> vectorBeverages);///can remove this function
        int printBevergesListStandard();
        Beverages getBeverageFromList(int element);


    private:
        vector<SideOrders> vectorSideOrders;
        vector<Beverages> vectorBeverages;
};

#endif // EXTRASREPOSITORY_H
