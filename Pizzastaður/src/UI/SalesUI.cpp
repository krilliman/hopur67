#include "salesui.h"
#include "mainui.h"
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
        cout << "*** SALES INTERFACE ***" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1: Menu Pizza" << endl;
        cout << "2: Make your own" << endl;
        cout << "3: Print all custom orders" << endl;
        cout << "4: Print all menu orders " << endl;
        cout << "Q: Press Q to go back to - Main Menu -" << endl;
        cout << "-------------------------------------------------------" << endl;
        cin >> Selection;
        cout << "-------------------------------------------------------" << endl;


        if (Selection == '1')
        {
            OrderList newOrderList;
            int input = 0;
            cout << "Enter the amount of orders: ";
            cin >> input;
            for(int i = 0 ; i < input; i++)
            {
                orderFromMenu neworder;

                cin >> neworder;
                newOrderList.setNewOrderFromMenu(neworder);
            }
        }
        else if (Selection == '2')
        {
            OrderList newOrderList;
            int input = 0;
            cout << "Enter the amount of orders: ";
            cin >> input;
            for(int i = 0 ; i < input; i++)
            {
                newOrder neworder;

                cin >> neworder;
                //cout << "TEST: " << neworder << endl;
                newOrderList.setNewOrder(neworder);
            }



        }
        else if (Selection == '3')
        {
           OrderList newOrderList;
           newOrderList.getOrderList();
        }
        else if (Selection == '4')
        {
            OrderList newOrderList;
            newOrderList.getOrdersFromMenu();
        }
        else if (Selection == 'Q' || Selection == 'q')
        {
            MainUI mainui;
            mainui.startUI();
        }
    }
}
