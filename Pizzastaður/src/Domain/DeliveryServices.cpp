#include "DeliveryServices.h"

DeliveryService::DeliveryService()
{
    //ctor
}

PizzaPlaces DeliveryService::GetPizzaPlace()
{
    PizzaPlaceRepo pizzaplaceRepo;
    int input = pizzaplaceRepo.readFromListOFPizzaPlaces();
    PizzaPlaces newPizzaplace = pizzaplaceRepo.getPizzaPlaceFromList(input);

    return newPizzaplace;

}
void DeliveryService::getOrdersAtSpecificPizzaPlace(PizzaPlaces currentPizzaPlace)
{
    OrderRepository orderRepo;
    orderRepo.getOrderAtSpecificPizzaPlaceDelivery(currentPizzaPlace);
    this->customOrderReady = orderRepo.getCustomOrderReady();
    this->menuOrdersReady = orderRepo.getMenuOrderReady();
}

int DeliveryService::selectListOfCustomOrderReady()
{
    int counter = 1;
    int vectorSize = this->customOrderReady.size();
    cout << "Select from list of Orders: " << endl;
    for(int i = 0; i < vectorSize;i++)
    {
        cout << counter << ".";
        cout << customOrderReady[i] << endl;
        counter++;
    }
    int input;
    cin >> input;
    return input;
}
int DeliveryService::selectFromMenuOrders()
{
    int counter = 1;
    int vectorSize = this->menuOrdersReady.size();
    cout << "Select from list of Orders: " << endl;
    for(int i = 0; i < vectorSize;i++)
    {
        cout << counter << ".";
        cout << menuOrdersReady[i] << endl;
        counter++;
    }
    int input;
    cin >> input;
    return input;
}

orderFromMenu DeliveryService::selectFromOrderMenuReady(int element)
{
    orderFromMenu newOrderFromMenu = this->menuOrdersReady[element-1];
    return newOrderFromMenu;
}
newOrder DeliveryService::selectFromCustomOrdeReady(int element)
{
    newOrder newCustomOrder = this->customOrderReady[element-1];
    return newCustomOrder;
}


void DeliveryService::changeCustomOrders(newOrder neworder)
{
    OrderRepository orderRepo;
    orderRepo.readOrder();
    vector<newOrder> allCustomOrders = orderRepo.getorderVector();

    int allCustomOrdersSize = allCustomOrders.size();


    for(int i = 0; i < allCustomOrdersSize; i++)
    {
        if(allCustomOrders[i].getOrderNum() == neworder.getOrderNum())
        {
            allCustomOrders.erase(allCustomOrders.begin()+i);
        }
        orderRepo.overRideCustomOrders(allCustomOrders);
        orderRepo.writePaidCustomOrders(neworder);
    }
}
void DeliveryService::changeMenuOrders(orderFromMenu newOrderFromMenu)
{
    OrderRepository orderRepo;
    vector<orderFromMenu> allMenuOrders = orderRepo.getorderFromMenuVector();

    int allMenuOrdersSize = allMenuOrders.size();

    for(int i = 0; i < allMenuOrdersSize; i++)
    {
        if(allMenuOrders[i].getOrderNum() == newOrderFromMenu.getOrderNum())
        {
            allMenuOrders.erase(allMenuOrders.begin()+i);
        }
    }
    orderRepo.overRideMenuOrders(allMenuOrders);
    orderRepo.writePaidMenuOrders(newOrderFromMenu);
}
int DeliveryService::customOrdersVectorSize(PizzaPlaces pizzaplace)
{
    OrderRepository orderRepo;
    orderRepo.getOrderAtSpecificPizzaPlaceDelivery(pizzaplace);

    vector<newOrder> tempOrder = orderRepo.getCustomOrderReady();

    int vectorSize = tempOrder.size();

    return vectorSize;
}
int DeliveryService::menuOrderVectorSize(PizzaPlaces pizzaplace)
{
    OrderRepository orderRepo;
    orderRepo.getOrderAtSpecificPizzaPlaceDelivery(pizzaplace);

    vector<orderFromMenu> tempOrder = orderRepo.getMenuOrderReady();

    int vectorSize = tempOrder.size();

    return vectorSize;
}
