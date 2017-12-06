#include "aleggrepository.h"
#include "toppinglist.h"
#include <fstream>
AleggRepository::AleggRepository()
{
    //ctor
}

AleggRepository::~AleggRepository()
{
    //dtor
}


void AleggRepository::storeAlegg( ToppingList toppinglist)
{
    ofstream fout;

    fout.open("Topping_list.dat", ios::binary | ios::app);

    toppinglist.write(fout);


    fout.close();
}
ToppingList AleggRepository::getTopList()
{
    ifstream fin;

    //fin.open("pizzas.dat", ios::binary );
    fin.open("Topping_list.dat", ios::binary);
    ToppingList topList;

    topList.read(fin);

    fin.close();

    return topList;
}
