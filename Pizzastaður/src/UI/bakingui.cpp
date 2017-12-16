#include "bakingui.h"
#include "mainui.h"
#include "OrderList.h"
#include "BakingService.h"
#include <iostream>

using namespace std;

bakingui::bakingui()
{
    //ctor
}
void bakingui::startUI()
{
    char status = '\0';
    int Selection = 0;
    while (Selection != 1)
    {
        cout << "*** BAKING INTERFACE ***" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Press 1 to go back to -Main Menu-" << endl;
        cout << " 2 To Choose location: " << endl;
        cin >> Selection;
        if(Selection == '1' )
        {

        }
        else if (Selection == 2)
        {
        BakingService bakingservice;
        PizzaPlaces currentPizzaPlace = bakingservice.GetPizzaPlace(); //ChoosePlace

        bakingservice.getOrdersAtSpecificPizzaPlace(currentPizzaPlace);

        cout << "Choose w to print Orders From Menu: " << endl;
        cout << "Choose e to print Custom Orders: " << endl;
        cout << "q. to go back " << endl;

        char input;
        cin >> input;


        if(input == 'w')
        {
            int menuInput = bakingservice.selectFromMenuOrders();
            orderFromMenu newOrderFromMenu = bakingservice.selectFromOrderMenuReady(menuInput);

            cout << newOrderFromMenu << endl;

            cout << "1. Mark ready " << endl;
            cout << "2. Mark in process " << endl;
            int currentStatus;
            cin >> currentStatus;
            if(currentStatus == 1)
            {
                bool temp = true;
                newOrderFromMenu.setPizzaStatus(temp);
                cout << "Test " << newOrderFromMenu << "test " << endl;
                bakingservice.changeMenuOrders(newOrderFromMenu);
            }
            else if(currentStatus == 2)
            {
                //cout << "doing nothing " << endl;
            }
        }
        else
        {
            cout << "No Menu orders found " << endl;
        }

        if(input == 'e')
        {
            int customElement = bakingservice.selectListOfCustomOrders();
            newOrder customOrder = bakingservice.selectFromCustomOrdeReady(customElement);

            cout << customOrder << endl;

            cout << "1. Mark ready " << endl;
            cout << "2. Mark in progress" << endl;
            int currentStatus;
            cin >> currentStatus;
            if(currentStatus == 1)
            {
                bool temp = true;
                customOrder.setPizzaStatus(temp);
                bakingservice.changeCustomOrders(customOrder);
            }
            else if(currentStatus == 2)
            {
                //cout << "Doing Nothing. " << endl;
            }
        }
        else
        {
            cout << "No Custom Orders found " << endl;
        }

    }
           else if (Selection == 'Q' || Selection == 'q')
        {
            MainUI mainui;
            mainui.startUI();
        }
    }
}
