#include "aleggrepository.h"
#include <fstream>
AleggRepository::AleggRepository()
{
    //ctor
}

void AleggRepository::storeAlegg( alegg aleggToAdd)
{

    ofstream fout;

    fout.open("Topping_list.dat", ios::binary | ios::app);

    fout.write((char*)(&aleggToAdd), sizeof(alegg));

    fout.close();
}

///not a good idea to return a pointer so need to find another way/if this even works.
void AleggRepository::readTopList()
{
    ifstream ifin;

    alegg newAlegg;

    ifin.open("Topping_list.dat", ios::binary);


    if(ifin.is_open())
        {
            ifin.seekg(0,ifin.end);
            int listSize = ifin.tellg() / sizeof(alegg);
            ifin.seekg(0, ifin.beg);


            for(int i = 0; i < listSize;i++)
            {
                ifin.read((char*)(&newAlegg),sizeof(alegg));
                vectorAlegg.push_back(newAlegg);

            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }

    ifin.close();

}

void AleggRepository::printTopList(vector<alegg> vectorAlegg)
{
    for ( vector<alegg>::iterator i = vectorAlegg.begin(); i != vectorAlegg.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
void AleggRepository::printTopListStandard()
{
    readTopList();
    for ( vector<alegg>::iterator i = vectorAlegg.begin(); i != vectorAlegg.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
