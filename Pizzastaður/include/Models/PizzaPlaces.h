#ifndef PIZZAPLACES_H
#define PIZZAPLACES_H
#include <iostream>

using namespace std;

class PizzaPlaces
{
    public:
        PizzaPlaces();

        friend ostream& operator <<(ostream& out, const PizzaPlaces& pizzaplaces);
        friend istream& operator >>(istream& in, PizzaPlaces& pizzaplaces);

    private:
        char name[20];
};

#endif // PIZZAPLACES_H
