#include "OrderList.h"

OrderList::OrderList()
{
    //ctor
}
void OrderList::setNewOrder(newOrder neworder)
{
    OrderRepository orderRepo;
    orderRepo.writeOrder(neworder);
}
void OrderList::getOrderList()
{
    OrderRepository orderRepo;
    orderRepo.printOrderList();
}
