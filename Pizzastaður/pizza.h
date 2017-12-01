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

        friend ostream& operator <<(ostream& out ,const Pizza& pizza);
        friend istream& operator >>(istream& in, Pizza& pizza);

    protected:

    private:
        alegg *toppings;
        int toppingCount;
        int currentToppingNum;

};

#endif // PIZZA_H
