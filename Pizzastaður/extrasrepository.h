#ifndef EXTRASREPOSITORY_H
#define EXTRASREPOSITORY_H
#include "sideorderlist.h"
#include "sideorders.h"


class extrasRepository
{
    public:
        extrasRepository();
        virtual ~extrasRepository();

        void writeSideOrder(SideOrderList sideorderlist);
        SideOrderList readSOList();

    protected:

    private:
};

#endif // EXTRASREPOSITORY_H
