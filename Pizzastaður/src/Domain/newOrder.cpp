#include "newOrder.h"
#include <cstdlib>
newOrder::newOrder()
{
    status = false;
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


void newOrder::setNewPricePerOrder()
{

    int total = 0, smallPizza = 1500 , mediumPizza = 2000 , largePizza = 2500;
    int pizzaVectorSize = pizzaVector.size();
    int sideOrderVectorSize = sideOrderVector.size();
    int beverageVectorSize = beverageVector.size();
    for(int i = 0; i < pizzaVectorSize;i++)
    {

        vector<alegg> newAlegg = pizzaVector[i].getAleggVector();
        char newSize = pizzaVector[i].getSize();
        cout << "newSize: " << newSize << endl;
        int sizeInInt = (int)newSize - 48;
        cout << "sizeInInt: " << sizeInInt << endl;
        if(sizeInInt == 1)
        {
            cout << "in small: " << endl;
            for(int i = 0; i < newAlegg.size();i++)
            {

                int small = stoi(newAlegg[i].getPriceSmall());
                total += small;
            }
            total += smallPizza;
        }
        else if(sizeInInt == 2)
        {
            cout << "in medium: " << endl;
            for(int i = 0; i < newAlegg.size();i++)
            {
                int medium = stoi(newAlegg[i].getPriceMedium());
                total += medium;
            }
            total += mediumPizza;

        }
        else if(sizeInInt == 3)
        {
            cout << "in large: " << endl;
            for(int i = 0; i < newAlegg.size();i++)
            {
                 int large = stoi(newAlegg[i].getPriceLarge());
                 total += large;
            }
            total += largePizza;

        }
    }

    cout << "Total after pizza: " << total << endl;
    for(int i = 0; i < sideOrderVectorSize; i++)
    {
       int price = stoi(sideOrderVector[i].getPrice());
        total += price;
    }

    cout << "Total after sideOrders: " << total << endl;
    for(int i = 0; i < beverageVectorSize;i++)
    {
        int price = stoi(beverageVector[i].getPrice());
        total += price;
    }

    cout << "total price after beverage: " << total << endl;
    this->pricePerOrder = total;


}
vector<Pizza> newOrder::getPizzaVector()
{
    return this->pizzaVector;
}

vector<SideOrders> newOrder::getSideOrderVector()
{
    return this->sideOrderVector;
}
vector<Beverages> newOrder::getBeverageVector()
{
    return this->beverageVector;
}


PizzaPlaces newOrder::getPizzaPlace()
{
    return this->pizzaplace;
}

int newOrder::getPricePerPizza()
{
    return this->pricePerPizza;
}
int newOrder::getPricePerOrder()
{
    return this->pricePerOrder;
}
bool newOrder::getOrderStatus()
{
    return this->status;
}

void newOrder::setPizzaVector(vector<Pizza> pizzaVector)
{
    this->pizzaVector = pizzaVector;
}

void newOrder::setSideOrderVector(vector<SideOrders> sideOrderVector)
{
    this->sideOrderVector = sideOrderVector;
}
void newOrder::setBeverageVector(vector<Beverages> beverageVector)
{
    this->beverageVector = beverageVector;
}


void newOrder::setPizzaPlace(PizzaPlaces pizzaplace)
{
    this->pizzaplace = pizzaplace;
}

void newOrder::setPizzaStatus(bool status)
{
    this->status = status;
}

void newOrder::setPricePerOrder(int pricePerOrder)
{
    this->pricePerOrder = pricePerOrder;
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

    out << endl << "Price Of Order: ";
    out << neworder.pricePerOrder << endl;
    if(neworder.status == false)
    {
        out << endl << "Not ready " << endl;
    }
    else if(neworder.status == true)
    {
        out << endl << "Order Ready " << endl;
    }
    return out;
}
