#include "beverages.h"

Beverages::Beverages()
{
    price = " ";
    name = " ";
}

string Beverages::getName()
{
    return this->name;
}
string Beverages::getPrice()
{
    return this->price;
}

void Beverages::setName(string name)
{
    this->name = name;
}
void Beverages::setPrice(string price)
{
    this->price = price;
}


void Beverages::writeBeverage(ofstream &fout)
{
    int nameLength = name.length();
    int priceLength = price.length();

    fout.write((char*)(&nameLength), sizeof(nameLength));
    fout.write(name.c_str(),nameLength);

    fout.write((char*)(&priceLength), sizeof(priceLength));
    fout.write(price.c_str(),priceLength);
}
void Beverages::readBeverage(ifstream &fin)
{
    int nameLength;
    fin.read((char*)(&nameLength), sizeof(nameLength));
    char *str1 = new char[nameLength];
    fin.read(str1,nameLength);

    string name = str1;
    setName(name);

    int priceLength;
    fin.read((char*)(&priceLength), sizeof(priceLength));
    char *str2 = new char[priceLength];
    fin.read(str2,priceLength);

    string price = str2;
    setPrice(price);
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
    in >> ws;
    getline(in,beverages.name);

    cout << "Enter a Price : ";
    in >> beverages.price;

    return in;
}
