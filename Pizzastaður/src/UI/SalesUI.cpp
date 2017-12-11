#include "salesui.h"
#include "alegg.h"
#include "toppinglist.h"
#include "pizzarepository.h"
#include "sideorderlist.h"
#include "beverageslist.h"
#include "OrderList.h"

using namespace std;

SalesUI::SalesUI()
{
    //ctor
}


void SalesUI::startUI()
{
    char Selection = '\0';
    while (Selection != 'r')
    {
        cout << endl<< "New Order: " << endl;
        cout << "1: Offers / Missing" << endl;
        cout << "2: Pizza from Menu / Missing" << endl;
        cout << "3: Make your own / Missing" << endl;
        cout << "4: to Print order" << endl;
        cout << "r: Press r to go back to - Main Menu -" << endl;
        cin >> Selection;

        if (Selection == '1')
        {
            ///int menu.offer;

            cout << "Please select offer: " << endl;
            cout << "1: Offer A " << endl;
            cout << "2: Offer B " << endl;
            cout << "3: Offer C " << endl;

            //cin >> menu.offer;
            //INSERTSERVICE
        }
        if (Selection == '2')
        {
            ///int menu.pizza;
            ///Here we need to make an instance of menuList and print out the list

            cout << "Please select pizza: " << endl;
            cout << "1: Pizza A " << endl;
            cout << "2: Pizza B " << endl;
            cout << "3: Pizza C " << endl;
            cout << "4: Pizza D " << endl;
            cout << "5: Pizza E " << endl;
            cout << "6: Pizza F " << endl;
            cout << "7: Pizza G " << endl;

           // cin >> menu.pizza;
            //checkmenublabla
        }
        if (Selection == '3')
        {
            OrderList newOrderList;
            int input = 0;
            cout << "Enter the amount of orders: ";
            cin >> input;
            for(int i = 0 ; i < input; i++)
            {
                newOrder neworder;

                cin >> neworder;
                cout << "TEST: " << neworder << endl;
                newOrderList.setNewOrder(neworder);
            }



        }
        if (Selection == '4')
        {
           OrderList newOrderList;
           newOrderList.getOrderList();
        }
        if (Selection == '5')
        {
            ///char beverage.selection;
            cout << "Please select beverage: " << endl;
            cout << "1: Coke " << endl;
            cout << "2: Sprite " << endl;
            cout << "3: Fanta " << endl;

            ///cin >> beverage.selection;
            //Service
        }
    }
}
