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

        void getOrderAtSpecificPizzaPlaceBakery(PizzaPlaces newPizzaplace);
        void getOrderAtSpecificPizzaPlaceDelivery(PizzaPlaces newPizzaplace);

        int pickCustomOrderBakery();
        int PickMenuOrderBakery();

        int getOrderFromMenuVectorBakerySize();
        int getOrderVectorBakerySize();

        newOrder getOrderFromList(int element);
        orderFromMenu getMenuOrderFromList(int element);


        vector<newOrder> getorderVector();
        vector<orderFromMenu> getorderFromMenuVector();

        vector<newOrder> getCustomOrderReady();
        vector<orderFromMenu> getMenuOrderReady();

        vector<newOrder> getOrderVectorBakery();
        vector<orderFromMenu> getOrderFromMenuVectorBakery();

        void overRideMenuOrders(vector<orderFromMenu> orderFromMenuVector);
        void overRideCustomOrders(vector<newOrder> customOrder);

        void clearLoadVectors();
        void writePaidCustomOrders(newOrder customPaidorder);
        void writePaidMenuOrders(orderFromMenu menuPaidOrder);




    private:
        vector<newOrder> orderVector;
        vector<orderFromMenu> orderFromMenuVector;

        vector<newOrder> orderVectorBakery;
        vector<orderFromMenu> orderFromMenuVectorBakery;

        vector<newOrder> orderVectorDelivery;
        vector<orderFromMenu> orderFromMenuVectorDelivery;

};

#endif // ORDERREPOSITORY_H
