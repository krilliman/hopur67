#include "PizzaPlaceRepo.h"

PizzaPlaceRepo::PizzaPlaceRepo()
{
    //ctor
}


void PizzaPlaceRepo::writeNewPizzaPlace(PizzaPlaces pizzaplace)
{
    ofstream fout;

    fout.open("List_Of_PizzaPlaces.dat" , ios::binary|ios::app);

    fout.write((char*)(&pizzaplace), sizeof(PizzaPlaces));

    fout.close();
}
void PizzaPlaceRepo::readListOfPizzaPlaces()
{
    ifstream fin;

    PizzaPlaces pizzaplace;

    fin.open("List_Of_PizzaPlaces.dat", ios::binary|ios::app);
        if(fin.is_open())
        {
            fin.seekg(0,fin.end);
            int listSize = fin.tellg() / sizeof(PizzaPlaces);
            fin.seekg(0, fin.beg);

            for(int i = 0; i < listSize;i++)
            {
                fin.read((char*)(&pizzaplace),sizeof(PizzaPlaces));

                vectorOfPizzaPlaces.push_back(pizzaplace);
            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }

    fin.close();
}
void PizzaPlaceRepo::printPizzaPlacesStandard()
{
    readListOfPizzaPlaces();
    for ( vector<PizzaPlaces>::iterator i = vectorOfPizzaPlaces.begin(); i != vectorOfPizzaPlaces.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
void PizzaPlaceRepo::printPizzaPlace(vector<PizzaPlaces> vectorOfPizzaPlaces)
{
    for ( vector<PizzaPlaces>::iterator i = vectorOfPizzaPlaces.begin(); i != vectorOfPizzaPlaces.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
