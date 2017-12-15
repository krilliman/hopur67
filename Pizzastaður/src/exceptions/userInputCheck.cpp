#include "userInputCheck.h"

userInputCheck::userInputCheck()
{
    //ctor
}


bool userInputCheck::checkIfDigit(string input)
{
    int inputLength = input.length();
    for(int i = 0; i < inputLength;i++)
    {
        if(isdigit(input[i]))
        {
            return true;
        }
    }
    return false;
}
bool userInputCheck::checkIfAscci(string input)
{
    int inputLength = input.length();
    for(int i = 0; i < inputLength;i++)
    {
        if(!(isdigit(input[i])))
        {
            return true;
        }
    }
    return false;
}

bool userInputCheck::checkInRangeAlegg(string input)
{
    ifstream fin;

    fin.open("../Topping_list.dat", ios::binary);
    fin.seekg(-4,fin.end);

    int sizeOfList;
    fin.read((char*)(&sizeOfList),sizeof(sizeOfList));

    fin.close();
}
bool userInputCheck::checkInRangeMenu(string input)
{

    ifstream fin;

    fin.open("../Menu_list.dat", ios::binary);
    fin.seekg(-4,fin.end);

    int sizeOfList;
    fin.read((char*)(&sizeOfList),sizeof(sizeOfList));

    fin.close();
}
bool userInputCheck::checkInRangeCustomOrder(string input)
{

}
bool userInputCheck::checkInRangeBeverages(string input)
{

}
bool userInputCheck::checkInRangeSideOrder(string input)
{

}
bool userInputCheck::checkInRangeMenuOrder(string input)
{

}
bool userInputCheck::checkInRangePizzaPlace(string input)
{

}

bool userInputCheck::checkIfBeverageExists(Beverages newBeverage)
{

}
bool userInputCheck::checkIfSideOrderExists(SideOrders newSideOrder)
{

}
bool userInputCheck::checkIfToppingExists(alegg newAlegg)
{

}
bool userInputCheck::checkIfExistsOnMenu(Menu newMenu)
{

}
