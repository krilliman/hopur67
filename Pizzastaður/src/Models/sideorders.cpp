#include "sideorders.h"

SideOrders::SideOrders()
{
    name = " ";
    Price = " ";
}


string SideOrders::getPrice()
{
    return this->Price;
}
string SideOrders::getName()
{
    return this->name;
}
void SideOrders::setName(string name)
{
    this->name = name;
}
void SideOrders::setPrice(string Price)
{
    this->Price = Price;
}
ostream& operator <<(ostream& out, const SideOrders sideorders)
{
    cout << "Side Order Name: ";
    out << sideorders.name;
    cout << endl << "Side Order Price: ";
    out << sideorders.Price;

    return out;
}

void SideOrders::writeSideOrder(ofstream &fout)
{

    int nameLength = name.length()+1;
    int priceLength = Price.length()+1;


    fout.write((char*)(&nameLength), sizeof(nameLength));
    fout.write(name.c_str(),nameLength);

    fout.write((char*)(&priceLength), sizeof(priceLength));
    fout.write(Price.c_str(),priceLength);

}
void SideOrders::readSideOrder(ifstream &fin)
{
    int nameLength;
    fin.read((char*)(&nameLength), sizeof(nameLength));
    char *str1 = new char[nameLength];
    fin.read(str1,nameLength);


    string name = str1;
    setName(str1);


    int priceLength;
    fin.read((char*)(&priceLength), sizeof(priceLength));
    char *str2 = new char[priceLength];
    fin.read(str2,priceLength);

    string price = str2;
    setPrice(str2);
}
istream& operator >> (istream& in, SideOrders& sideorders)
{
    cout << "Please enter side order name: ";
    in >> ws;
    getline(in,sideorders.name);
    cout << "-------------------------------------------------------" << endl;

    cout << "Price: ";
    in >> sideorders.Price;
    cout << "-------------------------------------------------------" << endl;

    return in;
}
