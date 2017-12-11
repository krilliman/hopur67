#include "beverageslist.h"

Beverageslist::Beverageslist()
{
    //ctor
}


void Beverageslist::setNewBeverges(Beverages beverage)
{
    ///validate beverage then call the repo;
    extrasRepository extraRepo;
    extraRepo.writeBeverageToList(beverage);

}
void Beverageslist::getBevergeList()
{
    extrasRepository extraRepo;
    ///tala við repo og setja inní pointerinn

    ///extraRepo.readBevergesList(); virkar til að prenta út bara
    extraRepo.printBevergesListStandard();

}
