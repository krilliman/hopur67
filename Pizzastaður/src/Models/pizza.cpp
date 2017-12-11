#include "pizza.h"
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
ostream& operator <<(ostream& out, const Pizza& pizza)
{
    if(pizza.notMenuPizza == true)
    {
        cout << "Bottom type: ";
        out << pizza.bottom;

        cout << "Pizza Size: ";
        out << pizza.size;
    }
    cout << "Toppings: " << endl;
    for ( vector<alegg>::const_iterator i = pizza.aleggVector.begin(); i != pizza.aleggVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }

    return out;
}
istream& operator >>(istream& in, Pizza& pizza)
{
    int topCnt;
    int input;
    if(pizza.notMenuPizza == false)
    {

        char *bottom1 = (char*)"Normal";
        char *bottom2 = (char*)"Thin";
        char *bottom3 = (char*)"pan";

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
        if(input == 1)
        {
            pizza.size = sizeSmall;
        }
        else if (input == 2)
        {
            pizza.size = sizeMedium;
        }
        else if(input == 3)
        {
            pizza.size = sizeLarge;
        }

    }
    cout << "Enter Number Of Toppings: ";
    in >> topCnt;
    alegg topping;
    topping.setAddOrNot(false);
    for(int i = 0; i < topCnt;i++)
    {
        in >> topping;
        pizza.aleggVector.push_back(topping);
    }
    return in;

}
