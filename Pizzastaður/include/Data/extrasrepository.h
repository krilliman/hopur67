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
        void printSOList(vector<SideOrders> vectorSideOrders);
        int printSOListStandard();///testing the int function
        vector<SideOrders> SOfunctionTest(int element);


        void writeBeverageToList(Beverages beverage);
        void readBevergesList();
        void printBevergesList(vector<Beverages> vectorBeverages);
        void printBevergesListStandard();


    protected:
        vector<SideOrders> vectorSideOrders;
        vector<Beverages> vectorBeverages;

    private:
};

#endif // EXTRASREPOSITORY_H
