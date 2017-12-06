#include "adminui.h"
#include "alegg.h"
#include <iostream>
#include "toppinglist.h"
#include "aleggrepository.h"
#include "pizzarepository.h"
#include "sideorderlist.h"
#include "extrasrepository.h"
#include "sideorders.h"
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
    extrasRepository extraRepo;
    PizzaRepository pizzaRepo;
    char Selection = '\0';
    while(Selection != 'q')
    {
        cout << endl<< "t: to add to Toppings: " << endl;
        cout << "m: to add to Menu: " << endl;
        cout << "b: to add to Beverages: " << endl;
        cout << "s: to add to Side Orders: " << endl << endl << endl;
        cout << "p: to print Toppings: " << endl;
        cout << "l: to print Menu: //ERROR" << endl;
        cout << "o: to print Toppings: " << endl;
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
                nyPizza.setMenuPizza(true);
                cin >> nyPizza;

                menu.setPizzaToAdd(nyPizza);
                pizzaRepo.storeMenu(menu);

            }
        }
        else if(Selection == 's' || Selection == 'S')
        {
            int SOAdd;
            SideOrderList SOList;

            cout << endl << "How many Side Orders would you like to add ? ";
            cin >> SOAdd;

            for(int i = 0 ; i < SOAdd;i++)
            {
                cout << endl;
                SideOrders newsideorder;
                cin >> newsideorder;

                SOList.setSideOrderToAdd(newsideorder);
                extraRepo.writeSideOrder(SOList);
            }


        }
        else if(Selection == 'b' || Selection == 'B' )
        {
            int BeveragesAdd;


        }

        else if(Selection == 'o' || Selection == 'O')
        {
            cout << endl;
            extraRepo.readSOList();
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
