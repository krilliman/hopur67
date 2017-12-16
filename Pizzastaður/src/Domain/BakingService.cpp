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
void BakingService::getOrdersAtSpecificPizzaPlace(PizzaPlaces currentPizzaPlace)
{
    OrderRepository orderRepo;
    orderRepo.getOrderAtSpecificPizzaPlaceBakery(currentPizzaPlace);
    this->customOrder = orderRepo.getOrderVectorBakery();
    this->menuOrders = orderRepo.getOrderFromMenuVectorBakery();
}


int BakingService::selectListOfCustomOrders()
{
    int counter = 1;
    int vectorSize = this->customOrder.size();
    cout << "Select from list of Orders: " << endl;
    for(int i = 0; i < vectorSize;i++)
    {
        cout << counter << ".";
        cout << customOrder[i] << endl;
        counter++;
    }
    int input;
    cin >> input;
    return input;
}
int BakingService::selectFromMenuOrders()
{
    int counter = 1;
    int vectorSize = this->menuOrders.size();
    cout << "Select from list of Orders: " << endl;
    for(int i = 0; i < vectorSize;i++)
    {
        cout << counter << ".";
        cout << menuOrders[i] << endl;
        counter++;
    }
    int input;
    cin >> input;
    return input;
}

orderFromMenu BakingService::selectFromOrderMenuReady(int element)
{
    orderFromMenu newOrderFromMenu = this->menuOrders[element-1];
    return newOrderFromMenu;
}
newOrder BakingService::selectFromCustomOrdeReady(int element)
{
    newOrder newCustomOrder = this->customOrder[element-1];
    return newCustomOrder;
}

void BakingService::changeCustomOrders(newOrder neworder)
{
    OrderRepository orderRepo;
    orderRepo.readOrder();
    vector<newOrder> allCustomOrders = orderRepo.getorderVector();

    int allCustomOrdersSize = allCustomOrders.size();


    for(int i = 0; i < allCustomOrdersSize; i++)
    {
        if(allCustomOrders[i].getOrderNum() == neworder.getOrderNum())
        {
            allCustomOrders.at(i) = neworder;
        }
    }
    orderRepo.overRideCustomOrders(allCustomOrders);
}
void BakingService::changeMenuOrders(orderFromMenu newOrderFromMenu)
{
    OrderRepository orderRepo;
    orderRepo.readOrderFromMenu();
    vector<orderFromMenu> allMenuOrders = orderRepo.getorderFromMenuVector();




    int allMenuOrdersSize = allMenuOrders.size();

    for(int i = 0; i < allMenuOrdersSize; i++)
    {
        if(allMenuOrders[i].getOrderNum() == newOrderFromMenu.getOrderNum())
        {
            allMenuOrders.at(i) = newOrderFromMenu;

        }
    }
    orderRepo.overRideMenuOrders(allMenuOrders);
}
