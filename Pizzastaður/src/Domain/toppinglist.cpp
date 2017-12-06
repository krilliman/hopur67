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
void ToppingList::getToppingList()
{
    AleggRepository aleggRepo;

    this->toppinglist = aleggRepo.getTopList();
}
