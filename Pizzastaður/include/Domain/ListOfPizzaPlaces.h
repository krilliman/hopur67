#ifndef LISTOFPIZZAPLACES_H
#define LISTOFPIZZAPLACES_H

#include <PizzaPlaces.h>
#include <PizzaPlaceRepo.h>
class ListOfPizzaPlaces
{
    public:
        ListOfPizzaPlaces();

        void setNewPizzaPlace(PizzaPlaces pizzaplace);
        PizzaPlaces getFromListOfPizzaPlaces();

    private:
};

#endif // LISTOFPIZZAPLACES_H
