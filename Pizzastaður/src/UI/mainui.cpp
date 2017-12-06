#include "mainui.h"
#include "adminui.h"
#include <iostream>

using namespace std;
MainUI::MainUI()
{
    //ctor
}

MainUI::~MainUI()
{
    //dtor
}

void MainUI::startUI()
{
    char Selection = '\0';
    while(Selection != 'q')
    {
        cout << "a: to add to menu/Toppings: " << endl;
        cout << "o: to create a order: " << endl;
        cin >> Selection;

        if(Selection == 'a' ||Selection == 'A' )
        {
            AdminUI adminui;
            adminui.startUI();

        }
        else if(Selection == 'o' || Selection == 'O' )
        {

        }
        else if(Selection == 'pm')
        {

        }
        else if(Selection == 'pm')
        {

        }
    }
}
