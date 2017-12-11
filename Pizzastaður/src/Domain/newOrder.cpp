#include "newOrder.h"

newOrder::newOrder()
{

}

istream& operator >>(istream& in, newOrder neworder)
{
    /*
    int pizzas;
    cout << "How many pizzas would you like ? ";
    in >> pizzas;
    for(int i = 0; i< pizzas;i++)
    {
        Pizza newPizza;
        in >> newPizza;
    }
    */
    int sideorder;
    cout << "How many Side orders would you like ? ";
    in >> sideorder;

    for(int i = 0; i < sideorder;i++)
    {
        SideOrderList sideorderlist;

    }

    return in;
}
ostream& operator <<(ostream& out, newOrder neworder)
{

    for ( vector<Pizza>::iterator i = neworder.pizzaVector.begin(); i != neworder.pizzaVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }

    return out;
}
