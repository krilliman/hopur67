#include "DeliveryServices.h"

DeliveryService::DeliveryService()
{
    //ctor
}

void DeliveryService::PrintOrders()
{
    OrderRepository orderRepo;
    orderRepo.printOrderList();
}
void DeliveryService::GetPizzaPlace()
{
    PizzaPlaceRepo pizzaplaceRepo;
    pizzaplaceRepo.readFromListOFPizzaPlaces();

}
/* void DeliveryService::PrintCompleteOrders();
void DeliveryService::OpenOrder();
*/
/* void DeliveryService::Paid()
{
    char payment;
}
void DeliveryService::Delivered();*/
