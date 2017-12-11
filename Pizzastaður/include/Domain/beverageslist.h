#ifndef BEVERAGESLIST_H
#define BEVERAGESLIST_H

#include "beverages.h"
#include "extrasrepository.h"

class Beverageslist
{
    public:
        Beverageslist();

        void setNewBeverges(Beverages beverage);
        Beverages getFromBevergeList();

    private:
};

#endif // BEVERAGESLIST_H
