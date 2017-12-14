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

        void writeMenu(ofstream &fout);
        void readMenu(istream &fin);

        string getName();
        string getPriceSmall();
        string getPriceMedium();
        string getPriceLarge();
        vector<alegg> getToppingVector();

        void setName(string name);
        void setPiceSmall(string priceSmall);
        void setPiceMedium(string priceMedium);
        void setPiceLarge(string priceLarge);
        void setToppinNames(vector<alegg> toppings);

    private:
        string name;
        string verdLitil;
        string verdMid;
        string verdStor;
        vector<alegg> toppings;

};

#endif // MATSEDILL_H


