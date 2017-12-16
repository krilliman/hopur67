#include "adminui.h"
#include "mainui.h"
#include "toppinglist.h"
#include "sideorderlist.h"
#include "beverageslist.h"
#include "ListOfPizzaPlaces.h"
#include "menu.h"
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

    char Selection = '\0';
    while(Selection != 'q')
    {
        cout << "*** ADMIN INTERFACE ***" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1: Add new topping " << endl;
        cout << "2: Add new pizza " << endl;
        cout << "3: Add new side " << endl;
        cout << "4: Add new beverage " << endl;
        cout << "5: Add new pizza place " << endl;
        cout << "Press Q to go back to -Main Menu-" << endl;
        cout << "-------------------------------------------------------" << endl;
        cin >> Selection;
        cout << "-------------------------------------------------------" << endl;

        if(Selection == '1')
        {
            int addTopping;
            ToppingList toppinlist;

            cout << endl << "How many Toppings would you like to add? ";
            cin >> addTopping;

            for(int i = 0 ; i < addTopping;i++)
            {
                cout << endl;
                alegg nyttAlegg;
                cin >> nyttAlegg;
                toppinlist.setNewTopping(nyttAlegg);

            }
        }
        else if(Selection == '2')
        {
            int addPizza;
            Menu menuList;

            cout << endl << "How many pizzas would you like to add to the menu? ";
            cin >> addPizza;

            for(int i = 0; i < addPizza;i++)
            {
                cout << endl;
                Menu menu;
                cin >> menu;

                menuList.addNewPizza(menu);
            }
        }
        else if(Selection == '3')
        {
            int SOAdd;
            SideOrderList SOList;

            cout << endl << "How many sides would you like to add? ";
            cin >> SOAdd;

            for(int i = 0 ; i < SOAdd;i++)
            {
                cout << endl;
                SideOrders newsideorder;
                cin >> newsideorder;
                SOList.setNewSideOrder(newsideorder);
            }


        }
        else if(Selection == '4')
        {
            int BeveragesAdd;

            Beverageslist beveragelist;

            cout << endl << "How many beverages would you like to add? ";
            cin >> BeveragesAdd;

            for(int i = 0; i < BeveragesAdd;i++)
            {
                Beverages beverage;
                cin >> beverage;
                //cout << "test: " << beverage << endl;
                beveragelist.setNewBeverges(beverage);
            }


        }
        else if(Selection == '5')
        {
            int PizzaPlacesToAdd;

            ListOfPizzaPlaces listOfpizzaplaces;

            cout << endl << "How many Pizza Places would you like to add? ";
            cin >> PizzaPlacesToAdd;

            for(int i = 0; i < PizzaPlacesToAdd;i++)
            {
                PizzaPlaces pizzaplace;
                cin >> pizzaplace;
                //cout << "test: " << pizzaplace << endl;
                listOfpizzaplaces.setNewPizzaPlace(pizzaplace);
            }


        }

        /* else if(Selection == 'o' || Selection == 'O')
        {
            cout << endl;
            SideOrderList sideorderlist;
            sideorderlist.getOutOfSideOrderList();
        }
        else if(Selection == 'p' || Selection == 'P')
        {
            cout << endl;
            ToppingList toppinlist;
            toppinlist.getToppingList();
        }
        else if(Selection == 'l'||Selection == 'L')
        {
            cout << endl;
            Menu menu;
            menu.getMenu();
        }
        else if(Selection == 'i' ||Selection == 'I')
        {
            cout << endl;
            Beverageslist beverageslist;

            beverageslist.getFromBevergeList();
        }
         else if(Selection == 'r' ||Selection == 'R')
        {
            cout << endl;
            ListOfPizzaPlaces listOfPizzaplaces;

            listOfPizzaplaces.getFromListOfPizzaPlaces();
        }*/
        else if (Selection == 'Q' || Selection == 'q')
        {
            MainUI mainui;
            mainui.startUI();
        }
    }
}
