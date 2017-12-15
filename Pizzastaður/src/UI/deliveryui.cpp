#include "deliveryui.h"
#include "mainui.h"
#include "DeliveryServices.h"
#include "OrderList.h"
#include <iostream>

using namespace std;

deliveryui::deliveryui()
{
    //ctor
}


void deliveryui::startUI()
{
    char status = '\0';
    int Selection;
    while (Selection != 1)
    {
        cout << "*** DELIVERY INTERFACE ***" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Press 1 to go back to -Main Menu-" << endl;
        cout << "Press 2 Choose location: " << endl;
        cin >> Selection;

        if(Selection == 1)
        {

        }
        else if(Selection == 2)
        {
            DeliveryService deliveryservice;
            PizzaPlaces newPizzaplace = deliveryservice.GetPizzaPlace();
            deliveryservice.getOrdersAtSpecificPizzaPlace(newPizzaplace);

            int customVectorSize = deliveryservice.customOrdersVectorSize(newPizzaplace);
            int menuVectorSize = deliveryservice.menuOrderVectorSize(newPizzaplace);

            cout << "Size of custom Vector: " << customVectorSize << endl;
            cout << "Size of Menu Vector: " << menuVectorSize << endl;

            cout << "Press m to print list of orders from menu " << endl;
            cout << "Press c to print list of Custom orders " << endl;
            char input;
            cin >> input;
            if(input == 'm' && menuVectorSize != 0)
            {
                int menuInput = deliveryservice.selectFromMenuOrderReady();
                orderFromMenu newOrderFromMenu = deliveryservice.selectFromOrderMenuReady(menuInput);

                cout << endl << newOrderFromMenu  << endl;
                cout << "Select 1 to mark order Paid " << endl;
                cout << "Select 2 to mark unPaid " << endl;
                int input;
                cin >> input;
                if(input == 1)
                {
                    deliveryservice.changeMenuOrders(newOrderFromMenu);
                }
                else if(input == 2)
                {
                    cout << "Doing nothing " << endl;
                }
            }
            else
            {
                cout << "File Empty. " << endl;
            }


            if(input == 'c' && customVectorSize != 0)
            {
                int customOrderInput = deliveryservice.selectListOfCustomOrderReady();
                newOrder newCustomOrder = deliveryservice.selectFromCustomOrdeReady(customOrderInput);

                cout << endl << newCustomOrder  << endl;
                cout << "Select 1 to mark order Paid " << endl;
                cout << "Select 2 to mark unPaid " << endl;
                int input;
                cin >> input;
                if(input == 1)
                {
                    bool test = true;
                    newCustomOrder.setPizzaStatus(test);
                    deliveryservice.changeCustomOrders(newCustomOrder);
                }
                else if(input == 2)
                {
                    cout << "Doing nothing " << endl;
                }
            }
            else
            {
                cout << "File Empty." << endl;
            }
        }
        ////printListOfPizzaPlaces();



        /*
        cin >> Selection;
        cout << "-------------------------------------------------------" << endl;

        if(Selection == '1')
        {
            cout << "*** ORDERS ***" << endl;
            DeliveryService deliveryservice;
            deliveryservice.PrintOrders();
            cout << "-------------------------------------------------------" << endl;
            //print list of all complete orders for B
            //select specific order
            ///Þetta á að koma eftir að búið er að velja specific order:
                    cout << "Choose order status: " << endl;
                    cout << "1. Paid " << endl;
                    cout << "2. Delivered / Picked-up " << endl;
                    cout << "-------------------------------------------------------" << endl;
                    if(status == '1')
                    {
                        cout << "Order has been marked as paid" << endl;
                        cout << "Press Q to return to Main Menu" << endl;
                        cout << "Press B to return to Delivery" << endl;
                        cin >> Selection;
                            if (Selection == 'b' || Selection == 'B')
                            {
                                deliveryui DeliveryUI;
                                DeliveryUI.startUI();
                            }
                            else if (Selection == 'q' || Selection == 'Q')
                            {
                                MainUI mainui;
                                mainui.startUI();
                            }

                    }
                    else if (status ==- '2')
                    {
                        cout << "Order has been marked as picked up" << endl;
                        //change status of order to gone
                        cout << "Press Q to return to Main Menu" << endl;
                        cout << "Press B to return to Delivery" << endl;
                        cin >> Selection;
                            if (Selection == 'b' || Selection == 'B')
                            {
                                deliveryui DeliveryUI;
                                DeliveryUI.startUI();
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
            DeliveryService deliveryservice;
            deliveryservice.PrintOrders();
            cout << "-------------------------------------------------------" << endl;
                        //print list of all complete orders for B
            //select specific order
            ///Þetta á að koma eftir að búið er að velja specific order:
                    cout << "Choose order status: " << endl;
                    cout << "1. Paid " << endl;
                    cout << "2. Delivered / Picked-up " << endl;
                    cout << "-------------------------------------------------------" << endl;
                    if(status == '1')
                    {
                        cout << "Order has been marked as paid" << endl;
                        cout << "Press Q to return to Main Menu" << endl;
                        cout << "Press B to return to Delivery" << endl;
                        cin >> Selection;
                            if (Selection == 'b' || Selection == 'B')
                            {
                                deliveryui DeliveryUI;
                                DeliveryUI.startUI();
                            }
                            else if (Selection == 'q' || Selection == 'Q')
                            {
                                MainUI mainui;
                                mainui.startUI();
                            }
                    }
                    else if (status ==- '2')
                    {
                        cout << "Order has been marked as picked up" << endl;
                        cout << "Press Q to return to Main Menu" << endl;
                        cout << "Press B to return to Delivery" << endl;
                        cin >> Selection;
                            if (Selection == 'b' || Selection == 'B')
                            {
                                deliveryui DeliveryUI;
                                DeliveryUI.startUI();
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
