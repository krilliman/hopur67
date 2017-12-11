#include "newOrder.h"
#include <cstdlib>
newOrder::newOrder()
{

}

void newOrder::addToSideOrderVector(SideOrders newSideorder)
{
    this->sideOrderVector.push_back(newSideorder);
}
void newOrder::addToPizzaVector(Pizza newPizza)
{
    this->pizzaVector.push_back(newPizza);
}
void newOrder::addToBeveragesVector(Beverages newBeverages)
{
    this->beverageVector.push_back(newBeverages);
}

istream& operator >>(istream& in, newOrder& neworder)
{
    (system("CLS"));
    int pizzas;
    cout << "How many pizzas would you like ? ";
    in >> pizzas;
    for(int i = 0; i< pizzas;i++)
    {
        Pizza newPizza;
        newPizza.setMenuPizza(false);
        in >> newPizza;
        neworder.addToPizzaVector(newPizza);
    }
    (system("CLS"));
    int sideorder;
    cout << "How many Side orders would you like ? ";
    in >> sideorder;

    for(int i = 0; i < sideorder;i++)
    {

        SideOrderList newlist;
        SideOrders newSideOrder;
        newSideOrder = newlist.getOutOfSideOrderList();
        neworder.addToSideOrderVector(newSideOrder);

    }

    (system("CLS"));
    int beverage;
    cout << "How many beverages would you like ? ";
    in >> beverage;

    for(int i = 0; i < beverage; i++)
    {
        Beverageslist newList;
        Beverages newBeverage;

        newBeverage = newList.getFromBevergeList();
        neworder.addToBeveragesVector(newBeverage);

    }
    (system("CLS"));
    ListOfPizzaPlaces newPizzaPlaceList;
    PizzaPlaces newPizzaplace;
    newPizzaplace = newPizzaPlaceList.getFromListOfPizzaPlaces();
    neworder.pizzaplace = newPizzaplace;
    return in;
}
ostream& operator <<(ostream& out, newOrder neworder)
{
    out << "---Pizza-- " << endl;
    for ( vector<Pizza>::iterator i = neworder.pizzaVector.begin(); i != neworder.pizzaVector.end(); ++i)
    {
        out << *i << ' ' << endl;
    }

    out << endl << "--sideOrder---" << endl;
    for ( vector<SideOrders>::iterator i = neworder.sideOrderVector.begin(); i != neworder.sideOrderVector.end(); ++i)
    {
        out << *i << ' ' << endl;
    }
    out << endl << "--Beverage---" << endl;
    for ( vector<Beverages>::iterator i = neworder.beverageVector.begin(); i != neworder.beverageVector.end(); ++i)
    {
        out << *i << ' ' << endl;
    }
    out << endl << "---Pizza Place---" << endl;
    out << neworder.pizzaplace << endl;

    return out;
}
