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
    ///tala við repo og setja inní pointerinn

    ///extraRepo.readBevergesList(); virkar til að prenta út bara
    /*
    int listLize = extraRepo.getBeverageSize();

    BeverageList = new Beverages[listSize];

    for(int i = 0 ; i < listLize; i++)
    {
        this->BeverageList[i] = extraRepo.readBevergesList();
    }
    */
    BeverageList = extraRepo.readBevergesList();



}

void Beverageslist::printList()
{
    for(int i = 0; i < listSize;i++)
    {
        cout << BeverageList[i];
    }
}
