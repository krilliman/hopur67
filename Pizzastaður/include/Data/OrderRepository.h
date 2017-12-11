#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include <newOrder.h>

class OrderRepository
{
    public:
        OrderRepository();

        void writeOrder(newOrder neworder);
        void readOrder();
        void printOrderList();

    private:
        vector<newOrder> orderVector;
};

#endif // ORDERREPOSITORY_H
