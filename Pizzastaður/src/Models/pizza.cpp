#include "pizza.h"
#include "toppinglist.h"
#include <aleggrepository.h>
Pizza::Pizza()
{
    char temp[32];
    bottom = '\0';
    size = 0;
    notMenuPizza = true;
}
void Pizza::setMenuPizza(bool n)
{
    this->notMenuPizza = n;
}



void Pizza::setNewBottom(char* bottom)
{
    this->bottom = bottom;
}
void Pizza::setNewSize(int size)
{
    this->size = size;
}
void Pizza::setNewAleggVector(vector<alegg> aleggVector)
{
    this->aleggVector = aleggVector;
}

char *Pizza::getBottom()
{
    return this->bottom;
}
int Pizza::getSize()
{
    return this->size;
}


vector<alegg> Pizza::getAleggVector()
{
    return this->aleggVector;
}
ostream& operator <<(ostream& out, const Pizza& pizza)
{

    cout << "Bottom type: ";
    out << pizza.bottom << endl;

    cout << "Pizza Size: ";
    out << pizza.size << endl;

    for ( vector<alegg>::const_iterator i = pizza.aleggVector.begin(); i != pizza.aleggVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
    return out;
}
istream& operator >>(istream& in, Pizza& pizza)
{

    cout << "TEST 1: --- " << endl;

    if(pizza.notMenuPizza == false)
    {

        char *bottom1 = (char*)"Normal";
        char *bottom2 = (char*)"Thin";
        char *bottom3 = (char*)"pan";
        int input;
        cout << "Choose a bottom: " << endl;
        cout << "1." << bottom1 << endl;
        cout << "2." << bottom2 << endl;
        cout << "3." <<  bottom3 << endl;
        in >> input;

        if(input == 1)
        {
            pizza.bottom = bottom1;
        }
        else if (input == 2)
        {
            pizza.bottom = bottom2;
        }
        else if(input == 3)
        {
            pizza.bottom = bottom3;
        }

        cout << "choose a size " << endl;
        cout << "1." << "small" << endl;
        cout << "2." << "medium" << endl;
        cout << "3." <<  "large" << endl;
        int input2;
        cin >> input2;
        if(input2 == 1)
        {
            pizza.size = 1;
        }
        else if (input2 == 2)
        {
            pizza.size = 2;
        }
        else if(input2 == 3)
        {
            pizza.size = 3;
        }

    }
    cout << "Enter Number Of Toppings: ";
    int topCnt;
    in >> topCnt;
    for(int i = 0; i < topCnt;i++)
    {

        AleggRepository aleggRepo;

        int element = aleggRepo.printTopListStandard();
        alegg newTopping = aleggRepo.getAleggFromList(element);
        pizza.aleggVector.push_back(newTopping);
        cout << "pizza cin newTopping: " << i+1 << newTopping << endl;
    }

    return in;

}
