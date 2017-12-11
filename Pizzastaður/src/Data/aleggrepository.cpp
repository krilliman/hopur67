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

alegg AleggRepository::getAleggFromList(int element)
{
    alegg newAlegg;
    newAlegg = this->vectorAlegg[element-1];
    return newAlegg;
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
int AleggRepository::printTopListStandard()
{
    readTopList();
    int counter = 1;
    int input = 0;
    for ( vector<alegg>::iterator i = vectorAlegg.begin(); i != vectorAlegg.end(); ++i)
    {
        cout << "Select topping number: " << endl;
        cout << counter << ": ";
        cout << *i << ' ' << endl;
        counter++;
    }
    cin >> input;
    return input;
}
