#include "beverages.h"

Beverages::Beverages()
{
    verd = 0;
    size = '\0';
    name = '\0';
}


Beverages::Beverages(char name , int verd , char size)
{
    this->name = name;
    this->verd = verd;
    this->size = size;
}

char Beverages::getName()
{
    return this->name;
}
int Beverages::getVerd()
{
    return this->verd;
}
char Beverages::getSize()
{
    return this->size;
}

ostream& operator << (ostream& out, const Beverages& beverages)
{
    cout << "Name: ";
    out << beverages.name;

    cout << "Size: ";
    out << beverages.size;

    cout << "Verd: ";
    out << beverages.verd;

    return out;
}
