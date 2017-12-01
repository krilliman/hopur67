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



void ToppingList::setListMemory(int memory)
{
    toppinglist = new alegg[memory];
    listLength = memory;
}



void ToppingList::read(ifstream& ifin)
{
    ///vantar að laga svo að þetta sé í lista í toppings
    alegg nyttAlegg;
        if(ifin.is_open())
        {
            ifin.seekg(0,ifin.end);
            int listSize = ifin.tellg() / sizeof(alegg);
            ifin.seekg(0, ifin.beg);

            setListMemory(listSize);
            for(int i = 0; i < listSize;i++)
            {
                ifin.read((char*)(&nyttAlegg),sizeof(alegg));

                cout << nyttAlegg << endl;
            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }
}
/*
void ToppingList::addSizeSet(int addSize)
{
    addToList = addSize;
}
*/

void ToppingList::write(ofstream& fout)
{
    fout.write((char*)(&ToppingToAdd), sizeof(alegg));
}

void ToppingList::setToppingToAdd(alegg ToppingToAdd)
{
    this->ToppingToAdd = ToppingToAdd;
}
