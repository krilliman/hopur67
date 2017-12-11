#ifndef PIZZAPLACEREPO_H
#define PIZZAPLACEREPO_H
#include "PizzaPlaces.h"
#include <vector>
#include <fstream>

class PizzaPlaceRepo
{
    public:
        PizzaPlaceRepo();

        void writeNewPizzaPlace(PizzaPlaces pizzaplace);
        void readListOfPizzaPlaces();
        void printPizzaPlacesStandard();
        void printPizzaPlace(vector<PizzaPlaces> vectorOfPizzaPlaces);

    private:
        vector<PizzaPlaces> vectorOfPizzaPlaces;

};

#endif // PIZZAPLACEREPO_H
