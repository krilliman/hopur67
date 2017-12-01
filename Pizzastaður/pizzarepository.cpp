#include "pizzarepository.h"
#include <fstream>
#include "menu.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

PizzaRepository::~PizzaRepository()
{
    //dtor
}

void PizzaRepository::storePizza(const Pizza& pizza)
{
    ofstream fout;

    fout.open("pizzas.dat", ios::binary | ios::app);

    pizza.write(fout);
    fout.close();
}

Pizza PizzaRepository::readPizza()
{
     ifstream fin;

    fin.open("pizzas.dat", ios::binary );
    Pizza pizza;

    pizza.read(fin);
    fin >> pizza;

    fin.close();

    return pizza;
}


void PizzaRepository::storeMenu(const Menu& menu)
{
    ofstream fout;

    fout.open("Menu_list.dat", ios::binary | ios::app);

    menu.write(fout);
    fout.close();
}

Menu PizzaRepository::readMenu()
{
    ifstream fin;

    //fin.open("pizzas.dat", ios::binary );
    fin.open("Menu_list.dat", ios::binary);
    Menu menu;

    menu.read(fin);

    fin.close();

    return menu;

}
