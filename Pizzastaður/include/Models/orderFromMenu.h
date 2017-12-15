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

        void writeOrderFromMenu(ofstream &fout);
        void readOrderFromMenu(ifstream &fin);

        int getPricePerOrder();
        bool getOrderStatus();
        int getOrderNum();

        void setPizzaVector(vector<Pizza> pizzaVector);
        void setSideOrderVector(vector<SideOrders> sideOrderVector);
        void setBeverageVector(vector<Beverages> beverageVector);
        void setPizzaFromMenuVector(vector<Menu> pizzaFromMenuVecor);
        void setSizeOfPizzas(vector<string> sizeOfPizzas);


        void setOrderNum(int orderNum);
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
        int orderNum;
        bool status;
};

#endif // ORDERFROMMENU_H
