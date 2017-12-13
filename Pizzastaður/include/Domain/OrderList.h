#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <newOrder.h>
#include <OrderRepository.h>
#include <orderFromMenu.h>
class OrderList
{
    public:
        OrderList();

        void setNewOrder(newOrder neworder);
        void getOrderList();

        void setNewOrderFromMenu(orderFromMenu orderfromMenu);
        void getOrdersFromMenu();

    private:
};

#endif // ORDERLIST_H
