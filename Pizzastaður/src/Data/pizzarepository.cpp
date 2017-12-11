#include "pizzarepository.h"
#include <fstream>
#include "menu.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

void PizzaRepository::storePizza(const Pizza& pizza)
{
    ofstream fout;

    fout.open("pizzas.dat", ios::binary | ios::app);

    fout.close();
}

void PizzaRepository::readPizza()
{
     ifstream fin;

    fin.open("pizzas.dat", ios::binary );


    if(fin.is_open())
        {
            fin.seekg(0,fin.end);
            int listSize = fin.tellg() / sizeof(Pizza);
            fin.seekg(0, fin.beg);

            Pizza pizza;
            for(int i = 0; i < listSize;i++)
            {
                fin.read((char*)(&pizza),sizeof(Menu));

                pizzas.push_back(pizza);
            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }


    fin.close();
}
void PizzaRepository::printPizza(vector<Pizza> pizzas)
{
    for ( vector<Pizza>::iterator i = pizzas.begin(); i != pizzas.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
void PizzaRepository::printAllPizzas()
{
    readPizza();
    for ( vector<Pizza>::iterator i = pizzas.begin(); i != pizzas.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}

void PizzaRepository::storeMenu(const Menu& menu)
{
    ofstream fout;


    fout.open("Menu_list.dat", ios::binary | ios::app);

    fout.write((char*)(&menu),sizeof(Menu));

    fout.close();
}

void PizzaRepository::readMenu()
{
    ifstream fin;

    fin.open("Menu_list.dat", ios::binary);
        if(fin.is_open())
        {
            fin.seekg(0,fin.end);
            int listSize = fin.tellg() / sizeof(Menu);
            fin.seekg(0, fin.beg);

            Menu menu;
            for(int i = 0; i < listSize;i++)
            {
                fin.read((char*)(&menu),sizeof(Menu));

                menuList.push_back(menu);
            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }

    fin.close();

}
void PizzaRepository::printMenu()
{
    readMenu();
    for ( vector<Menu>::iterator i = menuList.begin(); i != menuList.end(); i++)
    {
        cout << *i << ' ' << endl;
    }
}
