#ifndef MATSEDILL_H
#define MATSEDILL_H

#include <fstream>
#include <iostream>
#include <pizza.h>
#include <vector>

using namespace std;
class Menu
{
    public:
        Menu();

        friend ostream& operator << (ostream& out,const Menu& menu);
        friend istream& operator >> (istream& in, Menu& menu);

        void addNewPizza(Menu menu);
        void getMenu();

    private:
        char name[32];
        int verdLitil;
        int verdMid;
        int verdStor;
        Pizza pizza;

};

#endif // MATSEDILL_H


