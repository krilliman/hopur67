#ifndef ORDERFROMMENU_H
#define ORDERFROMMENU_H

#include <pizza.h>
#include <beverageslist.h>
#include <sideorderlist.h>
#include <ListOfPizzaPlaces.h>
#include <menu.h>


class orderFromMenu
{
    public:
        orderFromMenu();

        friend istream& operator >>(istream& in, orderFromMenu& neworder);
        friend ostream& operator <<(ostream& out, orderFromMenu neworder);

        void setNewPricePerOrder();

        void getPizzaMenu();

        vector<SideOrders> getSideOrderVector();
        vector<Beverages> getBeverageVector();
        vector<Menu> getPizzaFromMenuVector();
        vector<string> getSizeOfPizzas();

        int getPricePerOrder();
        bool getOrderStatus();

        void setPizzaVector(vector<Pizza> pizzaVector);
        void setSideOrderVector(vector<SideOrders> sideOrderVector);
        void setBeverageVector(vector<Beverages> beverageVector);
        void setPizzaFromMenuVector(vector<Menu> pizzaFromMenuVecor);
        void setSizeOfPizzas(vector<string> sizeOfPizzas);


        void setPizzaPlace(PizzaPlaces pizzaplace);
        void setPricePerOrder(int pricePerOrder);
        void setPizzaStatus(bool status);


        PizzaPlaces getPizzaPlace();



    private:
        vector<Menu> pizzaFromMenuVector;
        vector<SideOrders> sideOrderVector;
        vector<Beverages> beverageVector;
        vector<string> sizeOfPizzas;
        PizzaPlaces pizzaplace;
        int pricePerOrder;
        bool status;
};

#endif // ORDERFROMMENU_H
