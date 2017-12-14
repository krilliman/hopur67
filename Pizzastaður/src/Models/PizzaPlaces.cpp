#include "PizzaPlaces.h"

PizzaPlaces::PizzaPlaces()
{
    name = " ";
}

string PizzaPlaces::getName()
{
    return this->name;
}
void PizzaPlaces::setName(string name)
{
    this->name = name;
}


void PizzaPlaces::writePizzaPlace(ofstream &fout)
{
    int nameLength = name.length()+1;

    fout.write((char*)(&nameLength), sizeof(nameLength));
    fout.write(name.c_str(),nameLength);
}
void PizzaPlaces::readPizzaPlace(ifstream &fin)
{
    int stringLength;
    fin.read((char*)(&stringLength), sizeof(stringLength));
    char *str = new char[stringLength];
    fin.read(str,stringLength);

    string name = str;
    setName(name);

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
    in >> ws;
    getline(in,pizzaplaces.name);

    return in;
}
