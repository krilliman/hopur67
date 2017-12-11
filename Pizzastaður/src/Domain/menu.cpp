#include "menu.h"
#include <fstream>
#include "pizzarepository.h"
Menu::Menu()
{
    name[0] = '\0';
    verdLitil = 0;
    verdMid = 0;
    verdStor = 0;

}
void Menu::addNewPizza(Menu menu)
{
    PizzaRepository pizzaRepo;
    pizzaRepo.storeMenu(menu);
}
void Menu::getMenu()
{
    PizzaRepository pizzaRepo;
    pizzaRepo.printMenu();
}

ostream& operator << (ostream& out, const Menu& listi)
{

    cout << "Nafn: ";
    out << listi.name << endl;

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

    cout << "Name: ";
    in >> listi.name;

    cin >> listi.pizza;
    cout << "Price for little: ";
    in >> listi.verdLitil;

    cout << "Price for Middle: ";
    in >> listi.verdMid;

    cout << "Price for Big: ";
    in >> listi.verdStor;



    return in;
}
