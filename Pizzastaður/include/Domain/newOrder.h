#ifndef NEWORDER_H
#define NEWORDER_H
#include <pizza.h>
#include <beverageslist.h>
#include <sideorderlist.h>
#include <ListOfPizzaPlaces.h>

class newOrder
{
    public:
        newOrder();

        friend istream& operator >>(istream& in, newOrder& neworder);
        friend ostream& operator <<(ostream& out, newOrder neworder);

        void addToSideOrderVector(SideOrders newSideorder);
        void addToPizzaVector(Pizza newPizza);
        void addToBeveragesVector(Beverages newBeverages);



    private:
        vector<Pizza> pizzaVector;
        vector<SideOrders> sideOrderVector;
        vector<Beverages> beverageVector;
        PizzaPlaces pizzaplace;

};

#endif // NEWORDER_H
