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
PizzaPlaces ListOfPizzaPlaces::getFromListOfPizzaPlaces()
{
    PizzaPlaceRepo pizzaplaceRepo;
    int input = pizzaplaceRepo.readFromListOFPizzaPlaces();
    PizzaPlaces newPizzaplace;
    newPizzaplace = pizzaplaceRepo.getPizzaPlaceFromList(input);

    cout << "TEST::" << endl << newPizzaplace << endl;
    return newPizzaplace;
}

