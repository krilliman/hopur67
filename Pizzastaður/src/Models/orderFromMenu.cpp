#include "orderFromMenu.h"
#include <pizzarepository.h>
orderFromMenu::orderFromMenu()
{
    //ctor
}

istream& operator >>(istream& in, orderFromMenu& neworder)
{

    cout << "How many pizzas from menu would you like ? ";
    int inputPizzas;
    cin >> inputPizzas;
    for(int i = 0; i < inputPizzas; i++)
    {
        PizzaRepository pizzaRepo;
        int selection = pizzaRepo.selectFromMenu();
        Menu newMenu = pizzaRepo.selectElementFromMenu(selection);
        neworder.pizzaFromMenuVector.push_back(newMenu);
    }
    (system("CLS"));
    cout << "how many side Orders Would you like ? ";
    int inputSideOrders;
    cin >> inputSideOrders;
    for(int i = 0; i < inputSideOrders; i++)
    {
        SideOrderList newlist;
        SideOrders newSideOrder;
        newSideOrder = newlist.getOutOfSideOrderList();
        neworder.sideOrderVector.push_back(newSideOrder);
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
        neworder.beverageVector.push_back(newBeverage);

    }

    (system("CLS"));

    ListOfPizzaPlaces newPizzaPlaceList;
    PizzaPlaces newPizzaplace;
    newPizzaplace = newPizzaPlaceList.getFromListOfPizzaPlaces();
    neworder.setPizzaPlace(newPizzaplace);

    return in;

}
ostream& operator <<(ostream& out, orderFromMenu neworder)
{
    out << "---Pizza-- " << endl;
    for ( vector<Menu>::iterator i = neworder.pizzaFromMenuVector.begin(); i != neworder.pizzaFromMenuVector.end(); ++i)
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

    //out << endl << "Price Of Order: ";
    //out << neworder.pricePerOrder << endl;
    return out;
}


void orderFromMenu::setNewPricePerOrder()
{

}

vector<SideOrders> orderFromMenu::getSideOrderVector()
{
    return this->sideOrderVector;
}
vector<Beverages> orderFromMenu::getBeverageVector()
{
    return this->beverageVector;
}
vector<Menu> orderFromMenu::getPizzaFromMenuVector()
{
    return this->pizzaFromMenuVector;
}

int orderFromMenu::getPricePerOrder()
{
    return this->pricePerOrder;
}
bool orderFromMenu::getOrderStatus()
{
    return this->status;
}

void orderFromMenu::setSideOrderVector(vector<SideOrders> sideOrderVector)
{
    this->sideOrderVector = sideOrderVector;
}
void orderFromMenu::setBeverageVector(vector<Beverages> beverageVector)
{
    this->beverageVector = beverageVector;
}
void orderFromMenu::setPizzaFromMenuVector(vector<Menu> pizzaFromMenuVector)
{
    this->pizzaFromMenuVector = pizzaFromMenuVector;
}

void orderFromMenu::setPizzaPlace(PizzaPlaces pizzaplace)
{
    this->pizzaplace = pizzaplace;
}
void orderFromMenu::setPricePerOrder(int pricePerOrder)
{
    this->pricePerOrder = pricePerOrder;
}
void orderFromMenu::setPizzaStatus(bool status)
{
    this->status = status;
}

PizzaPlaces orderFromMenu::getPizzaPlace()
{
    return this->pizzaplace;
}
