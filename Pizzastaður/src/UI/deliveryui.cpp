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
    char Selection = '\0';
    while (Selection != 'Q' || Selection != 'q')
    {
        cout << "*** DELIVERY INTERFACE ***" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Press Q to go back to -Main Menu-" << endl;
        cout << "Choose location: " << endl;
        //printListOfPizzaPlaces();
        DeliveryService deliveryservice;
        deliveryservice.GetPizzaPlace();

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
    }
}
