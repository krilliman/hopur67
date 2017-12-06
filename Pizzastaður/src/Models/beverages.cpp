#include "beverages.h"

Beverages::Beverages()
{
    smallPrice = 0;
    midPrice = 0;
    bigPrice = 0;
    name[20] = '\0';
}
ostream& operator << (ostream& out, const Beverages& beverages)
{
    cout << "Name: ";
    out << beverages.name << endl;

    cout << "Price for small: ";
    out << beverages.smallPrice << endl;

    cout << "Price for Mid: " ;
    out << beverages.midPrice << endl;

    cout << "Price for big: ";
    out << beverages.bigPrice << endl << endl;

    return out;
}
istream& operator >>(istream& in, Beverages& beverages)
{
    cout << "Name: ";
    in >> beverages.name;
    cout << "Enter a Price for small: ";
    in >> beverages.smallPrice;

    cout << "Enter a Price for Mid: ";
    in >> beverages.midPrice;

    cout << "Enter a Price for big: ";
    in >> beverages.bigPrice;

    return in;
}
