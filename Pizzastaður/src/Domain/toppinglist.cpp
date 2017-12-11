#include "toppinglist.h"
#include "alegg.h"

ToppingList::ToppingList()
{
    //ctor
}

ToppingList::~ToppingList()
{
    //dtor
}

void ToppingList::setNewTopping(alegg newTopping)
{
    ///validate first before setting a new topping
    AleggRepository aleggRepo;
    aleggRepo.storeAlegg(newTopping);

}
alegg ToppingList::getToppingList()
{
    AleggRepository aleggRepo;

    int input = 0;
    input = aleggRepo.printTopListStandard();
    alegg newAlegg;
    newAlegg = aleggRepo.getAleggFromList(input);

    cout << "TEST: "<< newAlegg << endl;

    return newAlegg;

}
