#include "adminui.h"
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
        cout << endl<< "t: to add to Toppings: " << endl;
        cout << "m: to add to Menu: " << endl;
        cout << "b: to add to Beverages: " << endl;
        cout << "c: to add a Pizza Place: " << endl;
        cout << "s: to add to Side Orders: " << endl << endl << endl;
        cout << "p: to print Toppings: " << endl;
        cout << "l: to print Menu: //ERROR" << endl;
        cout << "o: to print Side Orders: " << endl;
        cout << "i: to print Beverages" << endl;
        cout << "r: to print Pizza Places" << endl;
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
                toppinlist.setNewTopping(nyttAlegg);

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
                Menu menu;
                cin >> menu;

                menu.addNewPizza(menu);
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
                SOList.setNewSideOrder(newsideorder);
            }


        }
        else if(Selection == 'b' || Selection == 'B' )
        {
            int BeveragesAdd;

            Beverageslist beveragelist;

            cout << endl << "How many Beverages would you like to add ? ";
            cin >> BeveragesAdd;

            for(int i = 0; i < BeveragesAdd;i++)
            {
                Beverages beverage;
                cin >> beverage;
                cout << "test: " << beverage << endl;
                beveragelist.setNewBeverges(beverage);
            }


        }
        else if(Selection == 'c' || Selection == 'C' )
        {
            int PizzaPlacesToAdd;

            ListOfPizzaPlaces listOfpizzaplaces;

            cout << endl << "How many Pizza Places would you like to add ? ";
            cin >> PizzaPlacesToAdd;

            for(int i = 0; i < PizzaPlacesToAdd;i++)
            {
                PizzaPlaces pizzaplace;
                cin >> pizzaplace;
                cout << "test: " << pizzaplace << endl;
                listOfpizzaplaces.setNewPizzaPlace(pizzaplace);
            }


        }

        else if(Selection == 'o' || Selection == 'O')
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
        }
    }
}
