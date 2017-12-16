#include "menu.h"
#include <fstream>
#include "pizzarepository.h"
#include "aleggrepository.h"
Menu::Menu()
{
    name = " ";
    verdLitil = " ";
    verdMid = " ";
    verdStor = " ";

}
void Menu::addNewPizza(Menu menu)
{
    PizzaRepository pizzaRepo;
    pizzaRepo.storeMenu(menu);
}
Menu Menu::getMenu()
{

    PizzaRepository pizzaRepo;
    int selection = pizzaRepo.selectFromMenu();
    Menu newMenu = pizzaRepo.selectElementFromMenu(selection);
    return newMenu;

}

string Menu::getName()
{
    return this->name;
}
string Menu::getPriceSmall()
{
    return this->verdLitil;
}
string Menu::getPriceMedium()
{
    return this->verdMid;
}
string Menu::getPriceLarge()
{
    return this->verdStor;
}

vector<alegg> Menu::getToppingVector()
{
    return this->toppings;
}


void Menu::setName(string name)
{
    this->name = name;
}
void Menu::setPiceSmall(string priceSmall)
{
    this->verdLitil = priceSmall;
}
void Menu::setPiceMedium(string priceMedium)
{
    this->verdMid = priceMedium;
}
void Menu::setPiceLarge(string priceLarge)
{
    this->verdStor = priceLarge;
}
void Menu::setToppinNames(vector<alegg> toppingName)
{
    this->toppings = toppingName;
}

void Menu::writeMenu(ofstream &fout)
{
    int nameLength = name.length() + 1;

    int priceSmallLength = verdLitil.length()+1;

    int priceMediumLength = verdMid.length()+1;

    int priceLargeLength = verdStor.length() + 1;

    fout.write((char*)(&nameLength), sizeof(nameLength));
    fout.write(this->name.c_str(),nameLength);

    fout.write((char*)(&priceSmallLength), sizeof(priceSmallLength));
    fout.write(this->verdLitil.c_str(),priceSmallLength);

    fout.write((char*)(&priceMediumLength), sizeof(priceMediumLength));
    fout.write(this->verdMid.c_str(),priceMediumLength);

    fout.write((char*)(&priceLargeLength), sizeof(priceLargeLength));
    fout.write(this->verdStor.c_str(),priceLargeLength);

}
void Menu::readMenu(istream &fin)
{
    int stringLength;
    fin.read((char*)(&stringLength), sizeof(stringLength));
    char *str = new char[stringLength];
    fin.read(str,stringLength);

    string name = str;
    setName(name);

    int newPriceSmall;
    fin.read((char*)(&newPriceSmall), sizeof(newPriceSmall));
    char *str1 = new char[newPriceSmall];
    fin.read(str1,newPriceSmall);

    string priceSmall = str1;
    setPiceSmall(priceSmall);

    int newPriceMiddle;
    fin.read((char*)(&newPriceMiddle), sizeof(newPriceMiddle));
    char *str2 = new char[newPriceMiddle];
    fin.read(str2,newPriceMiddle);

    string priceMedium = str2;
    setPiceMedium(priceMedium);

    int newPriceLarge;
    fin.read((char*)(&newPriceLarge), sizeof(newPriceLarge));
    char *str3 = new char[newPriceLarge];
    fin.read(str3,newPriceLarge);

    string priceLarge = str3;
    setPiceLarge(priceLarge);
}


ostream& operator << (ostream& out,  Menu& listi)
{

    cout << "Name: ";
    out << listi.name << endl;
    cout << "Toppings: " << endl;
    vector<alegg> newAleggVector =  listi.getToppingVector();
    for(unsigned int i = 0; i < newAleggVector.size();i++)
    {
        cout << newAleggVector[i].getName() << endl;
    }
    cout << "Price(Small): ";
    out << listi.verdLitil << endl;

    cout << "Price(Medium): ";
    out << listi.verdMid << endl;

    cout << "Price(Large): ";
    out << listi.verdStor << endl;

    return out;
}

istream& operator >> (istream& in, Menu& listi)
{

    AleggRepository aleggRepo;


    cout << "Name: ";
    in >> ws;
    getline(in,listi.name);

    cout << "Enter The amount of toppings: ";
    int input;
    cin >> input;
    for (int i = 0; i < input; i++)
    {
        int selection = aleggRepo.printTopListStandard();
        alegg newAlegg = aleggRepo.getAleggFromList(selection);
        listi.toppings.push_back(newAlegg);
    }


    cout << "Price(Small): ";
    in >> listi.verdLitil;

    cout << "Price(Medium): ";
    in >> listi.verdMid;

    cout << "Price(Large): ";
    in >> listi.verdStor;

    return in;
}
