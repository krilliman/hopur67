#include "adminui.h"
#include "alegg.h"
#include <iostream>
#include "toppinglist.h"
#include "aleggrepository.h"
#include "pizzarepository.h"
using namespace std;
AdminUI::AdminUI()
{
    //ctor
}

AdminUI::~AdminUI()
{
    //dtor
}

void AdminUI::startUI()
{
    AleggRepository aleggRepo;
    PizzaRepository pizzaRepo;
    char Selection = '\0';
    while(Selection != 'q')
    {
        cout << endl<< "t: to add to Toppings: " << endl;
        cout << "m: to add to Menu: " << endl;
        cout << "p: to print Toppings: " << endl;
        cout << "pm: to print Menu: " << endl;
        cin >> Selection;

        if(Selection == 't' ||Selection == 'T' )
        {
            int addTopping;
            ToppingList toppinlist;

            cout << endl << "How many Toppings would you like to add ? ";
            cin >> addTopping;

            for(int i = 0 ; i < addTopping;i++)
            {
                cout << endl;
                alegg nyttAlegg;
                cin >> nyttAlegg;

                toppinlist.setToppingToAdd(nyttAlegg);

                aleggRepo.storeAlegg(toppinlist);
            }
        }
        else if(Selection == 'm' || Selection == 'M' )
        {
            int addPizza;
            Menu menu;

            cout << endl << "How many Pizza's would you like to add to the menu ? ";
            cin >> addPizza;

            for(int i = 0; i < addPizza;i++)
            {
                cout << endl;
                Pizza nyPizza;
                cin >> nyPizza;

                menu.setPizzaToAdd(nyPizza);
                pizzaRepo.storeMenu(menu);

            }
        }
        else if(Selection == 'p' || Selection == 'P')
        {
            cout << endl;
            aleggRepo.getTopList();
        }
        else if(Selection == 'l'||Selection == 'L')
        {
            cout << endl;
            pizzaRepo.readMenu();
        }
    }
}
