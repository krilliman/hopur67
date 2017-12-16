#include "aleggrepository.h"
#include <fstream>
#include <userInputCheck.h>
AleggRepository::AleggRepository()
{
    //ctor
}

void AleggRepository::storeAlegg( alegg aleggToAdd)
{

    readTopList();
    ofstream fout;
    int aleggVectorSize = this->vectorAlegg.size()+1;

    fout.open("Topping_list.dat", ios::binary | ios::app);
    aleggToAdd.writeAlegg(fout);
    fout.write((char*)(&aleggVectorSize),sizeof(aleggVectorSize));

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
    ifstream fin;

    fin.open("Topping_list.dat", ios::binary);


    if(fin.is_open())
        {
            fin.seekg(0,fin.end);
            int testSize = fin.tellg();
            fin.seekg(0,fin.beg);
            if(testSize == 0)
            {

            }
            else
            {
                    int listSize;
                    fin.seekg(-4,fin.end);
                    fin.read((char*)(&listSize), sizeof(listSize));
                    fin.seekg(0,fin.beg);

                    // cout << "List Size: " << listSize << endl;
                    for(int i = 0; i < listSize;i++)
                    {
                            alegg newAlegg;
                            newAlegg.readAlegg(fin);

                            int aleggNum;
                            fin.read((char*)(&aleggNum), sizeof(aleggNum));
                            this->vectorAlegg.push_back(newAlegg);
                    }
            }
        }
        else
        {
            //cout << "Could not open file." << endl;
        }

    fin.close();

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
    userInputCheck newcheck;
    readTopList();

    string input;
    int newInput;
    int newCounter = 0;
    while(newCounter == 0)
    {
        int counter = 1;
        cout << "Please select topping: " << endl;
        cout << "-------------------------------------------------------" << endl;
        for ( vector<alegg>::iterator i = vectorAlegg.begin(); i != vectorAlegg.end(); ++i)
        {
            cout << " * " << counter << " * : ";
            cout << *i << ' ' << endl;
            cout << "-------------------------------------------------------" << endl;
            counter++;
        }
        cin >> input;
        cout << "-------------------------------------------------------" << endl;


        if(newcheck.checkInRangeAlegg(input) == true)
        {
            newInput = stoi(input);
            newCounter++;
        }
        else
        {
          cout << "invalid input " << endl;
        }
    }

    return newInput;
}
