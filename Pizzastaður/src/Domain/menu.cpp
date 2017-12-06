#include "menu.h"
#include "pizza.h"
Menu::Menu()
{
        addPizza;
        pizzaMenu = NULL;
        menuLength = 0;
}

Menu::~Menu()
{
    if(pizzaMenu != NULL)
    {
        delete[] pizzaMenu;
    }
}
void Menu::setListMemory(int menuLength)
{
    pizzaMenu = new Pizza[menuLength];
    this->menuLength = menuLength;
}
void Menu::read(ifstream& ifin)
{
    Pizza nyPizza;
        if(ifin.is_open())
        {
            ifin.seekg(0,ifin.end);
            int listSize = ifin.tellg() / sizeof(Pizza);
            ifin.seekg(0, ifin.beg);

            setListMemory(listSize);
            for(int i = 0; i < listSize;i++)
            {
                ifin.read((char*)(&nyPizza),sizeof(Pizza));

                cout << nyPizza << endl;
            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }
}
void Menu::setPizzaToAdd(Pizza newPizza)
{
    addPizza = newPizza;
}

void Menu::write(ofstream& fout)const
{
    fout.write((char*)(&addPizza), sizeof(Pizza));
}

