#ifndef PIZZA_H
#define PIZZA_H
#include "alegg.h"
#include <iostream>
#include <fstream>
#include <vector>

class Pizza
{
    public:
        Pizza();

        friend ostream& operator <<(ostream& out, const Pizza& pizza);
        friend istream& operator >>(istream& in, Pizza& pizza);

        void setMenuPizza(bool n);

        char *getBottom();
        char *getSize();

    protected:

    private:
        char* bottom;
        char* size;
        vector<alegg> aleggVector;
        bool notMenuPizza;

};

#endif // PIZZA_H
