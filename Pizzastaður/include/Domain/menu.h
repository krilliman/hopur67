#ifndef MATSEDILL_H
#define MATSEDILL_H

#include <fstream>
#include <iostream>
#include <pizza.h>
#include <vector>
#include <string>

using namespace std;
class Menu
{
    public:
        Menu();

        friend ostream& operator << (ostream& out, Menu& menu);
        friend istream& operator >> (istream& in, Menu& menu);

        void addNewPizza(Menu menu);
        Menu getMenu();

        string getName();
        int getPriceSmall();
        int getPriceMedium();
        int getPriceLarge();
        vector<alegg> getToppingVector();

        void setName(string name);
        void setPiceSmall(int priceSmall);
        void setPiceMedium(int priceMedium);
        void setPiceLarge(int priceLarge);
        void setToppinNames(vector<alegg> toppings);

    private:
        string name;
        int verdLitil;
        int verdMid;
        int verdStor;
        vector<alegg> toppings;

};

#endif // MATSEDILL_H


