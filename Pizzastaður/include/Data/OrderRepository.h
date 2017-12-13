#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include <newOrder.h>
#include <orderFromMenu.h>
class OrderRepository
{
    public:
        OrderRepository();

        void writeOrder(newOrder neworder);
        void readOrder();
        void printOrderList();

        void setNewOrderFromMenu(orderFromMenu newOrderfromMenu);
        void readOrderFromMenu();
        void printOrderFromMenuList();


    private:
        vector<newOrder> orderVector;
        vector<orderFromMenu> orderFromMenuVector;
};

#endif // ORDERREPOSITORY_H
