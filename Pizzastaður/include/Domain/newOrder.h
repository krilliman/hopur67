#ifndef NEWORDER_H
#define NEWORDER_H
#include <pizza.h>
#include <beverageslist.h>
#include <sideorderlist.h>
#include <ListOfPizzaPlaces.h>
#include <menu.h>

class newOrder
{
    public:
        newOrder();

        friend istream& operator >>(istream& in, newOrder& neworder);
        friend ostream& operator <<(ostream& out, newOrder neworder);

        void addToSideOrderVector(SideOrders newSideorder);
        void addToPizzaVector(Pizza newPizza);
        void addToBeveragesVector(Beverages newBeverages);
        void setNewPricePerOrder();

        vector<Pizza> getPizzaVector();
        vector<SideOrders> getSideOrderVector();
        vector<Beverages> getBeverageVector();
        vector<Menu> getPizzaFromMenuVector();

        int getPricePerPizza();
        int getPricePerOrder();
        int getOrderNum();
        bool getOrderStatus();

        void setPizzaVector(vector<Pizza> pizzaVector);
        void setSideOrderVector(vector<SideOrders> sideOrderVector);
        void setBeverageVector(vector<Beverages> beverageVector);
        void setPizzaFromMenuVector(vector<Menu> pizzaFromMenuVecor);

        void setPizzaPlace(PizzaPlaces pizzaplace);
        void setPricePerOrder(int pricePerOrder);
        void setPizzaStatus(bool status);
        void setOrderNum(int orderNum);


        PizzaPlaces getPizzaPlace();



    private:
        vector<Pizza> pizzaVector;
        vector<SideOrders> sideOrderVector;
        vector<Beverages> beverageVector;
        PizzaPlaces pizzaplace;
        int pricePerPizza;
        int pricePerOrder;
        int orderNum;
        bool status;

};

#endif // NEWORDER_H
