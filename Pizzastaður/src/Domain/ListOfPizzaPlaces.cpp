#include "ListOfPizzaPlaces.h"

ListOfPizzaPlaces::ListOfPizzaPlaces()
{
    //ctor
}

void ListOfPizzaPlaces::setNewPizzaPlace(PizzaPlaces pizzaplace)
{
    ///validate pizza place
    PizzaPlaceRepo pizzaplaceRepo;
    pizzaplaceRepo.writeNewPizzaPlace(pizzaplace);

}
void ListOfPizzaPlaces::printListOfPizzaPlaces()
{
    PizzaPlaceRepo pizzaplaceRepo;
    pizzaplaceRepo.printPizzaPlacesStandard();
}

