#ifndef BEVERAGESLIST_H
#define BEVERAGESLIST_H

#include "beverages.h"
#include "extrasrepository.h"

class Beverageslist
{
    public:
        Beverageslist();

        void getNewBeverges(Beverages beverage);
        void getBevergeList();

        void setList();

    private:
        Beverages beveragesToAdd;
        Beverages *BeverageList;
        int listSize;


};

#endif // BEVERAGESLIST_H
