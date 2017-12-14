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

        void writePizza(ofstream &fout);
        void readPizza(ifstream &fin);

        void setNewBottom(string bottom);
        void setNewSize(string size);
        void setNewAleggVector(vector<alegg> aleggVector);

        vector<alegg> getAleggVector();

        string getBottom();
        string getSize();

    protected:

    private:
        string bottom;
        string size;
        vector<alegg> aleggVector;
        bool notMenuPizza;

};

#endif // PIZZA_H
