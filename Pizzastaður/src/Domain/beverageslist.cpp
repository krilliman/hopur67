#include "beverageslist.h"

Beverageslist::Beverageslist()
{
    //ctor
}


void Beverageslist::getNewBeverges(Beverages beverage)
{
    ///validate beverage then call the repo;
    extrasRepository extraRepo;
    extraRepo.writeBeverageToList(beverage);

}
void Beverageslist::getBevergeList()
{
    extrasRepository extraRepo;
    ///tala vi� repo og setja inn� pointerinn
    int listLize = extraRepo.getBeverageSize();

    BeverageList = new Beverages[listSize];

    for(int i = 0 ; i < listLize; i++)
    {
        this->BeverageList[i] = extraRepo.readBevergesList();
    }

}
