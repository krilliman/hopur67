#include "BakingService.h"
#include <OrderRepository.h>

BakingService::BakingService()
{
    //ctor
}

void BakingService::PrintOrders()
{
    OrderRepository orderRepo;
    orderRepo.printOrderList();
}
PizzaPlaces BakingService::GetPizzaPlace()
{
    PizzaPlaceRepo pizzaplaceRepo;
    int input = pizzaplaceRepo.readFromListOFPizzaPlaces();
    PizzaPlaces newPizzaplace = pizzaplaceRepo.getPizzaPlaceFromList(input);

    return newPizzaplace;
}







/*
void BakingService::MarkInProgress()
{
}
void BakingService::MarkComplete()
{
}
 */
/* BakingService BakingOrderList::getOutOfBakingOrderList()
{
    int input;
    OrderRepository orderRepo;
    input = orderRepo.printOrderList();
    BakingService newPizzaToBake;
    newPizzaToBake = orderRepo.getOrderFromList(input);

    cout << newPizzaToBake << endl;
    return newPizzaToBake;
}
*/
