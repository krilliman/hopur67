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
    ///tala vi� repo og setja inn� pointerinn

    ///extraRepo.readBevergesList(); virkar til a� prenta �t bara
    extraRepo.printBevergesListStandard();

}
