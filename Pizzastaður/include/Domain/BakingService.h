#ifndef BAKINGSERVICE_H
#define BAKINGSERVICE_H
#include <OrderRepository.h>
#include <PizzaPlaceRepo.h>


class BakingService
{
    public:
        BakingService();
        void PrintOrders();
        PizzaPlaces GetPizzaPlace();
        void getOrdersAtSpecificPizzaPlace(PizzaPlaces currentPizzaPlace);
        void changeOrders();

        int selectListOfCustomOrders();
        int selectFromMenuOrders();

        orderFromMenu selectFromOrderMenuReady(int element);
        newOrder selectFromCustomOrdeReady(int element);

        void changeCustomOrders(newOrder);
        void changeMenuOrders(orderFromMenu);

    private:
        vector<newOrder> customOrder;
        vector<orderFromMenu> menuOrders;


    private:
};

#endif // BAKINGSERVICE_H
