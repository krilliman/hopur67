#include "PizzaPlaces.h"

PizzaPlaces::PizzaPlaces()
{
    name[0] = '\0';
}

ostream& operator <<(ostream& out, const PizzaPlaces& pizzaplaces)
{
    cout << "Name of PizzaPlace: ";
    out << pizzaplaces.name << endl;
    return out;
}
istream& operator >>(istream& in, PizzaPlaces& pizzaplaces)
{
    cout << "Enter a name of a PizzaPlace: ";
    in >> pizzaplaces.name;

    return in;
}
