#include "aleggrepository.h"
#include <fstream>
AleggRepository::AleggRepository()
{
    //ctor
}

AleggRepository::~AleggRepository()
{
    //dtor
}


void AleggRepository::storeAlegg( alegg aleggToAdd)
{

    ofstream fout;

    fout.open("Topping_list.dat", ios::binary | ios::app);

    fout.write((char*)(&aleggToAdd), sizeof(alegg));

    fout.close();
    /*
    ofstream fout;

    fout.open("Topping_list.dat", ios::binary | ios::app);

    toppinglist.write(fout);


    fout.close();
    */
}

///not a good idea to return a pointer so need to find another way/if this even works.
alegg* AleggRepository::getTopList()
{
    ifstream ifin;

    alegg newAlegg;

    ifin.open("Topping_list.dat", ios::binary);


    if(ifin.is_open())
        {
            ifin.seekg(0,ifin.end);
            int listSize = ifin.tellg() / sizeof(alegg);
            ifin.seekg(0, ifin.beg);

            alegg arrayOfAlegg[listSize];

            for(int i = 0; i < listSize;i++)
            {
                ifin.read((char*)(&newAlegg),sizeof(alegg));

                arrayOfAlegg[i] = newAlegg;
                cout << newAlegg << endl;
            }
             return arrayOfAlegg;
        }
        else
        {
            cout << "Could not open file." << endl;
        }

    ifin.close();

}
