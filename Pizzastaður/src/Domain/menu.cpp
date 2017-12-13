#include "menu.h"
#include <fstream>
#include "pizzarepository.h"
#include "aleggrepository.h"
Menu::Menu()
{
    name = " ";
    verdLitil = 0;
    verdMid = 0;
    verdStor = 0;

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
int Menu::getPriceSmall()
{
    return this->verdLitil;
}
int Menu::getPriceMedium()
{
    return this->verdMid;
}
int Menu::getPriceLarge()
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
void Menu::setPiceSmall(int priceSmall)
{
    this->verdLitil = priceSmall;
}
void Menu::setPiceMedium(int priceMedium)
{
    this->verdMid = priceMedium;
}
void Menu::setPiceLarge(int priceLarge)
{
    this->verdStor = priceLarge;
}
void Menu::setToppinNames(vector<alegg> toppingName)
{
    this->toppings = toppingName;
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
    cout << "Price for little: ";
    out << listi.verdLitil << endl;

    cout << "Price for Middle: ";
    out << listi.verdMid << endl;

    cout << "Price for Big: ";
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


    cout << "Price for little: ";
    in >> listi.verdLitil;

    cout << "Price for Middle: ";
    in >> listi.verdMid;

    cout << "Price for Big: ";
    in >> listi.verdStor;
    cout << "Exiting Menu/CIN: ---" << endl;
    return in;
}
