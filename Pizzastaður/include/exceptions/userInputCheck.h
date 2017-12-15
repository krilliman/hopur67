#ifndef USERINPUTCHECK_H
#define USERINPUTCHECK_H

#include <string>
#include <fstream>
#include <vector>
#include <aleggrepository.h>
#include <extrasrepository.h>
#include <OrderRepository.h>
#include <PizzaPlaceRepo.h>
#include <pizzarepository.h>


using namespace std;
class userInputCheck
{
    public:
        userInputCheck();

        bool checkIfDigit(string input);
        bool checkIfAscci(string input);
        bool checkInRangeAlegg(string input);
        bool checkInRangeMenu(string input);
        bool checkInRangeCustomOrder(string input);
        bool checkInRangeBeverages(string input);
        bool checkInRangeSideOrder(string input);
        bool checkInRangeMenuOrder(string input);
        bool checkInRangePizzaPlace(string input);
        bool checkIfBeverageExists(Beverages newBeverage);
        bool checkIfSideOrderExists(SideOrders newSideOrder);
        bool checkIfToppingExists(alegg newAlegg);
        bool checkIfExistsOnMenu(Menu newMenu);


    private:

};

#endif // USERINPUTCHECK_H
