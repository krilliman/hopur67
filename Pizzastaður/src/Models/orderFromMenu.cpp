#include "orderFromMenu.h"
#include <pizzarepository.h>
#include <stdlib.h>
orderFromMenu::orderFromMenu()
{
    status = false;
}

istream& operator >>(istream& in, orderFromMenu& neworder)
{

    cout << "How many pizzas would you like? ";
    int inputPizzas;
    cin >> inputPizzas;
    cout << "-------------------------------------------------------" << endl;
    for(int i = 0; i < inputPizzas; i++)
    {
        PizzaRepository pizzaRepo;
        int selection = pizzaRepo.selectFromMenu();
        Menu newMenu = pizzaRepo.selectElementFromMenu(selection);
        neworder.pizzaFromMenuVector.push_back(newMenu);
        cout << "Please choose size: " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1. Small" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Large" << endl;
        string input;
        cin >> input;
        neworder.sizeOfPizzas.push_back(input);
    }
    (system("CLS"));
    cout << "How many sides would you like? ";
    int inputSideOrders;
    cin >> inputSideOrders;
    cout << "-------------------------------------------------------" << endl;
    for(int i = 0; i < inputSideOrders; i++)
    {
        SideOrderList newlist;
        SideOrders newSideOrder;
        newSideOrder = newlist.getOutOfSideOrderList();
        neworder.sideOrderVector.push_back(newSideOrder);
    }
    (system("CLS"));
    int beverage;
    cout << "How many beverages would you like? ";
    in >> beverage;
    cout << "-------------------------------------------------------" << endl;

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
    vector<Menu> newMenuVector = neworder.getPizzaFromMenuVector();
    vector<string> newPizzaSize = neworder.getSizeOfPizzas();

    out << "** PIZZA **" << endl;
    for(unsigned int i = 0; i < newMenuVector.size();i++)
    {
        vector<alegg> toppingOnCurrentPizza = newMenuVector[i].getToppingVector();
        out << newMenuVector[i].getName() << endl;
        out << "Toppings: " << endl;
        cout << "-------------------------------------------------------" << endl;
        for(unsigned int u = 0; u < toppingOnCurrentPizza.size();u++)
        {
            out << toppingOnCurrentPizza[u].getName() << endl;
        }
       int stringToInt = stoi(newPizzaSize[i]);
        if(stringToInt == 1)
        {
            out << "Customer Picked Small pizza, Price is: ";
            out << newMenuVector[i].getPriceSmall() << endl;
        }
        else if(stringToInt == 2)
        {
            out << "Customer Picked Medium pizza, Price is: ";
            out << newMenuVector[i].getPriceMedium() << endl;
        }
        else if(stringToInt == 3)
        {
            out << "Customer Picked Large pizza, Price is: ";
            out << newMenuVector[i].getPriceLarge() << endl << endl;
        }

    }
    out << endl << "** SIDES **" << endl;
    for ( vector<SideOrders>::iterator i = neworder.sideOrderVector.begin(); i != neworder.sideOrderVector.end(); ++i)
    {
        out << *i << ' ' << endl;
    }
    out << endl << "** BEVERAGES **" << endl;
    for ( vector<Beverages>::iterator i = neworder.beverageVector.begin(); i != neworder.beverageVector.end(); ++i)
    {
        out << *i << ' ' << endl;
    }
    cout << "-------------------------------------------------------" << endl;
    out << endl << "PICK UP AT: " << endl;
    out << neworder.pizzaplace << endl;
    cout << "-------------------------------------------------------" << endl;

    out << endl << "ORDER TOTAL: ";
    out << neworder.pricePerOrder << endl;
    cout << "-------------------------------------------------------" << endl;
    if(neworder.status == false)
    {
        out << endl << "Order in progress" << endl;
        cout << "-------------------------------------------------------" << endl;
    }
    else if(neworder.status == true)
    {
        out << endl << "Order ready for pick up" << endl;
        cout << "-------------------------------------------------------" << endl;
    }
    return out;
}

int orderFromMenu::getOrderNum()
{
    return this->orderNum;
}
void orderFromMenu::setOrderNum(int orderNum)
{
    this->orderNum = orderNum;
}
void orderFromMenu::setNewPricePerOrder()
{

    int total = 0;

    int pizzasOnMenuVectorSize = this->pizzaFromMenuVector.size();

    for(int i =0; i <  pizzasOnMenuVectorSize;i++)
    {
        string temp = this->sizeOfPizzas[i];
        int stringToInt = stoi(temp);
        if(stringToInt == 1)
        {
            int small = stoi( pizzaFromMenuVector[i].getPriceSmall());
            total += small;
        }

        else if(stringToInt == 2)
        {
            int medium = stoi(pizzaFromMenuVector[i].getPriceMedium());
            total += medium;
        }

        else if(stringToInt == 3)
        {
            int large = stoi(pizzaFromMenuVector[i].getPriceLarge());
            total += large;
        }
    }

    int sizeOfSideOrderVector = sideOrderVector.size();
    for(int i = 0; i < sizeOfSideOrderVector; i++)
    {
        int sidePice = stoi(sideOrderVector[i].getPrice());
        total += sidePice;
    }
    int sizeOfBeverageVector = beverageVector.size();
    for(int i = 0; i < sizeOfBeverageVector;i++)
    {
        int beveragePrice = stoi(beverageVector[i].getPrice());
        total += beveragePrice;
    }

    this->pricePerOrder = total;


}

vector<SideOrders> orderFromMenu::getSideOrderVector()
{
    return this->sideOrderVector = sideOrderVector;
}
vector<Beverages> orderFromMenu::getBeverageVector()
{
    return this->beverageVector;
}
vector<Menu> orderFromMenu::getPizzaFromMenuVector()
{
    return this->pizzaFromMenuVector;
}
vector<string> orderFromMenu::getSizeOfPizzas()
{
    return this->sizeOfPizzas;
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
void orderFromMenu::setSizeOfPizzas(vector<string> sizeOfPizzas)
{
    this->sizeOfPizzas = sizeOfPizzas;
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
