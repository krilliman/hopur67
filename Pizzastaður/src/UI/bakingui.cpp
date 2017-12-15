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
    char Selection = '\0';
    while (Selection != 'Q' || Selection != 'q')
    {
        cout << "*** BAKING INTERFACE ***" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Press Q to go back to -Main Menu-" << endl;
        cout << "Choose location: " << endl;

        BakingService bakingservice;
        PizzaPlaces currentPizzaPlace = bakingservice.GetPizzaPlace(); //ChoosePlace

        OrderRepository orderRepo;
        orderRepo.getOrderAtSpecificPizzaPlaceBakery(currentPizzaPlace);

        cout << "Choose w to print Orders From Menu: " << endl;
        cout << "Choose e to print Custom Orders: " << endl;
        cout << "q. to go back " << endl;
        char input;
        cin >> input;
        while(input != 'q')
        {

            if(input == 'w')
            {
                int menuElement = orderRepo.PickMenuOrderBakery();
                orderFromMenu menuOrder = orderRepo.getMenuOrderFromList(menuElement);

                cout << menuOrder << endl;

                cout << "1. If ready " << endl;
                cout << "2. If not ready" << endl;
                int currentStatus;
                cin >> currentStatus;
                if(currentStatus == 1)
                {
                    menuOrder.setPizzaStatus(true);
                }
                else if(currentStatus == 2)
                {
                    menuOrder.setPizzaStatus(false);
                }

            }
            else if(input == 'e')
            {
                int customElement = orderRepo.pickCustomOrderBakery();
                newOrder customOrder = orderRepo.getOrderFromList(customElement);

                cout << customOrder << endl;

                cout << "1. If ready " << endl;
                cout << "2. If not ready" << endl;
                int currentStatus;
                cin >> currentStatus;
                if(currentStatus == 1)
                {
                    customOrder.setPizzaStatus(true);
                }
                else if(currentStatus == 2)
                {
                    customOrder.setPizzaStatus(false);
                }
            }
        }


        /*
        cout << "-------------------------------------------------------" << endl;

        if(Selection == '1')
        {
            cout << "*** ORDERS ***" << endl;
            BakingService bakingservice;
            bakingservice.PrintOrders();
            cout << "-------------------------------------------------------" << endl;
            //print list of all incomplete orders for A
            //select specific order
            ///Þetta á að koma eftir að búið er að velja specific order:
                    cout << "Choose order status: " << endl;
                    cout << "1. Order in Progress " << endl;
                    cout << "2. Order ready " << endl;
                    cout << "-------------------------------------------------------" << endl;
                    if(status == '1')
                    {
                        //change status of order to inprep
                        cout << "Order has been marked as in progress." << endl;
                        cout << "Press Q to return to Main Menu" << endl;
                        cout << "Press B to return to Baking" << endl;
                        cin >> Selection;
                        if (Selection == 'b' || Selection == 'B')
                        {
                            bakingui BakingUI;
                            BakingUI.startUI();
                        }
                        else if (Selection == 'q' || Selection == 'Q')
                        {
                            MainUI mainui;
                            mainui.startUI();
                        }
                    }
                    else if (status ==- '2')
                    {
                        cout << "Order has been marked as ready." << endl;
                        //change status of order to ready
                        cout << "Press Q to return to Main Menu" << endl;
                        cout << "Press B to return to Baking" << endl;
                        cin >> Selection;
                        if (Selection == 'b' || Selection == 'B')
                        {
                            bakingui BakingUI;
                            BakingUI.startUI();
                        }
                        else if (Selection == 'q' || Selection == 'Q')
                        {
                            MainUI mainui;
                            mainui.startUI();
                        }
                    }
        }
        else if(Selection == '2')
        {
            cout << "*** ORDERS ***" << endl;
            BakingService bakingService;
            bakingService.PrintOrders();
            cout << "-------------------------------------------------------" << endl;
            //print list of all incomplete orders for A
            //select specific order
            ///Þetta á að koma eftir að búið er að velja specific order:
            cout << "Choose order status: " << endl;
            cout << "1. Order in Progress " << endl;
            cout << "2. Order ready " << endl;
            cout << "-------------------------------------------------------" << endl;
                if(status == '1')
                {
                    //change status of order to inprep
                    cout << "Order has been marked as in progress." << endl;
                    cout << "Press Q to return to Main Menu" << endl;
                    cout << "Press B to return to Baking" << endl;
                    cin >> Selection;
                        if (Selection == 'b' || Selection == 'B')
                        {
                            bakingui BakingUI;
                            BakingUI.startUI();
                        }
                        else if (Selection == 'q' || Selection == 'Q')
                        {
                            MainUI mainui;
                            mainui.startUI();
                        }
                    }
                else if (status ==- '2')
                {
                    //change status of order to ready
                    cout << "Order has been marked as ready." << endl;
                    cout << "Press Q to return to Main Menu" << endl;
                    cout << "Press B to return to Baking" << endl;
                    cin >> Selection;
                        if (Selection == 'b' || Selection == 'B')
                        {
                            bakingui BakingUI;
                            BakingUI.startUI();
                        }
                        else if (Selection == 'q' || Selection == 'Q')
                        {
                            MainUI mainui;
                            mainui.startUI();
                        }
                    }
        }
        else if (Selection == 'Q' || Selection == 'q')
        {
            MainUI mainui;
            mainui.startUI();
        }
        */
    }
}
