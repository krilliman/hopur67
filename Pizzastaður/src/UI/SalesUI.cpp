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
        cout << "5. to print orders from menu" << endl;
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
            OrderList newOrderList;
            int input = 0;
            cout << "Enter the amount of orders: ";
            cin >> input;
            for(int i = 0 ; i < input; i++)
            {
                orderFromMenu neworder;

                cin >> neworder;
                cout << "TEST: " << neworder << endl;
                newOrderList.setNewOrderFromMenu(neworder);
            }
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
            OrderList newOrderList;
            newOrderList.getOrdersFromMenu();
        }
    }
}
