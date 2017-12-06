#ifndef PIZZA_H
#define PIZZA_H
#include "alegg.h"
#include <iostream>
#include <fstream>


class Pizza
{
    public:
        Pizza();
        Pizza(int numberOfToppings);
        virtual ~Pizza();

        void initialize(int numberOfToppings);
        void clean();
        void addTopping(alegg topping);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        void setMenuPizza(bool n);

        friend ostream& operator <<(ostream& out ,const Pizza& pizza);
        friend istream& operator >>(istream& in, Pizza& pizza);

    protected:

    private:
        char name[20];
        alegg *toppings;
        int toppingCount;
        int currentToppingNum;
        bool menuPizza;

};

#endif // PIZZA_H
