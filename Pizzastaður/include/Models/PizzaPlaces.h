#ifndef PIZZAPLACES_H
#define PIZZAPLACES_H
#include <iostream>
#include <fstream>

using namespace std;

class PizzaPlaces
{
    public:
        PizzaPlaces();

        friend ostream& operator <<(ostream& out, const PizzaPlaces& pizzaplaces);
        friend istream& operator >>(istream& in, PizzaPlaces& pizzaplaces);

        void writePizzaPlace(ofstream &fout);
        void readPizzaPlace(ifstream &fin);

        string getName();
        void setName(string name);

    private:
        string name;
};

#endif // PIZZAPLACES_H
