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
    private:
};

#endif // BAKINGSERVICE_H
