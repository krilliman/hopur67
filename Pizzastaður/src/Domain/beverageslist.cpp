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
Beverages Beverageslist::getFromBevergeList()
{
    int input = 0;
    extrasRepository extraRepo;
    input = extraRepo.printBevergesListStandard();

    Beverages newBeverage;
    newBeverage = extraRepo.getBeverageFromList(input);
    return newBeverage;

}
