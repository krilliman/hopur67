#include "beverages.h"

Beverages::Beverages()
{
    price = 0;
    name[0]= '\0';
}

char* Beverages::getName()
{
    return this->name;
}
int Beverages::getPrice()
{
    return this->price;
}

ostream& operator << (ostream& out, const Beverages& beverages)
{
    cout << "Name: ";
    out << beverages.name << endl;

    cout << "Price : ";
    out << beverages.price << endl;

    return out;
}
istream& operator >>(istream& in, Beverages& beverages)
{
    cout << "Name: ";
    in >> beverages.name;
    cout << "Enter a Price : ";
    in >> beverages.price;

    return in;
}
