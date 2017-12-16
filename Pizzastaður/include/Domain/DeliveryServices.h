#ifndef DELIVERYSERVICE_H
#define DELIVERYSERVICE_H
#include <OrderRepository.h>

class DeliveryService
{
    public:
        DeliveryService();
        void PrintOrders();
        PizzaPlaces GetPizzaPlace();
        void getOrdersAtSpecificPizzaPlace(PizzaPlaces currentPizzaPlace);

        int selectListOfCustomOrderReady();
        int selectFromMenuOrders();

        orderFromMenu selectFromOrderMenuReady(int element);
        newOrder selectFromCustomOrdeReady(int element);

        void changeCustomOrders(newOrder);
        void changeMenuOrders(orderFromMenu);

        int customOrdersVectorSize(PizzaPlaces pizzaplace);
        int menuOrderVectorSize(PizzaPlaces pizzaplace);

    private:
        vector<newOrder> customOrderReady;
        vector<orderFromMenu> menuOrdersReady;
};

#endif // DELIVERYSERVICE_H
