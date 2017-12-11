#include "pizza.h"
#include "toppinglist.h"
Pizza::Pizza()
{
    bottom = '\0';
    size = '\0';
    notMenuPizza = true;
}
void Pizza::setMenuPizza(bool n)
{
    this->notMenuPizza = n;
}

char *Pizza::getBottom()
{
    return this->bottom;
}
char *Pizza::getSize()
{
    return this->size;
}

ostream& operator <<(ostream& out, const Pizza& pizza)
{

    cout << "Bottom type: ";
    out << pizza.bottom << endl;

    cout << "Pizza Size: ";
    out << pizza.size << endl;

    for ( vector<alegg>::const_iterator i = pizza.aleggVector.begin(); i != pizza.aleggVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
    return out;
}
istream& operator >>(istream& in, Pizza& pizza)
{
    int topCnt;

    if(pizza.notMenuPizza == false)
    {

        char *bottom1 = (char*)"Normal";
        char *bottom2 = (char*)"Thin";
        char *bottom3 = (char*)"pan";
        int input;
        cout << "Choose a bottom: " << endl;
        cout << "1." << bottom1 << endl;
        cout << "2." << bottom2 << endl;
        cout << "3." <<  bottom3 << endl;
        in >> input;

        if(input == 1)
        {
            pizza.bottom = bottom1;
        }
        else if (input == 2)
        {
            pizza.bottom = bottom2;
        }
        else if(input == 3)
        {
            pizza.bottom = bottom3;
        }
        char *sizeSmall = (char*)"small";
        char *sizeMedium = (char*)"medium";
        char *sizeLarge = (char*)"large";
        cout << "choose a size " << endl;
        cout << "1." << sizeSmall << endl;
        cout << "2." << sizeMedium << endl;
        cout << "3." <<  sizeLarge << endl;
        int input2;
        cin >> input2;
        if(input2 == 1)
        {
            pizza.size = sizeSmall;
        }
        else if (input2 == 2)
        {
            pizza.size = sizeMedium;
        }
        else if(input2 == 3)
        {
            pizza.size = sizeLarge;
        }

    }
    cout << "Enter Number Of Toppings: ";
    in >> topCnt;
    ToppingList newToppingList;
    for(int i = 0; i < topCnt;i++)
    {
        alegg topping;
        topping = newToppingList.getToppingList();
        pizza.aleggVector.push_back(topping);
    }

    return in;

}
