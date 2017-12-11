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
        int readFromListOFPizzaPlaces();
        PizzaPlaces getPizzaPlaceFromList(int element);
        void printPizzaPlace(vector<PizzaPlaces> vectorOfPizzaPlaces); /// might not need this function

    private:
        vector<PizzaPlaces> vectorOfPizzaPlaces;

};

#endif // PIZZAPLACEREPO_H
