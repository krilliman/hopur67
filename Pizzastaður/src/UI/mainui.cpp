#include "mainui.h"
#include "adminui.h"
#include "SalesUI.h"
#include "bakingui.h"
#include "deliveryui.h"
#include <iostream>

using namespace std;
MainUI::MainUI()
{
    //ctor
}


void MainUI::startUI()
{
    char Selection = '\0';
    while (Selection != 'Q' || Selection != 'q')
    {
        cout << "Main Menu: " << endl;
        cout << "1. Admin" << endl;
        cout << "2. Sales" << endl;
        cout << "3. Baking" << endl;
        cout << "4. Delivery" << endl;
        cout << "To exit, press Q." << endl;

        cin >> Selection;

        if (Selection == '1')
        {
            AdminUI adminui;
            adminui.startUI();
        }
        if (Selection == '2')
        {
            SalesUI salesui;
            salesui.startUI();
        }
        if (Selection == '3')
        {
            bakingui BakingUI;
            BakingUI.startUI();
        }
        if (Selection == '4')
        {
            deliveryui DeliveryUI;
            DeliveryUI.startUI();
        }
    }

}
