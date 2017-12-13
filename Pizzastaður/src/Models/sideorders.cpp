#include "sideorders.h"

SideOrders::SideOrders()
{
    name[0] = '\0';
    price = 0;
}


int SideOrders::getPrice()
{
    return this->price;
}
ostream& operator <<(ostream& out, const SideOrders sideorders)
{
    cout << "Side Order Name: ";
    out << sideorders.name;
    cout << endl << "Side Order Price: ";
    out << sideorders.price;

    return out;
}

istream& operator >> (istream& in, SideOrders& sideorders)
{
    cout << "Enter Side Order Name: ";
    in >> sideorders.name;

    cout << "Enter Side Order Price: ";
    in >> sideorders.price;

    return in;
}
