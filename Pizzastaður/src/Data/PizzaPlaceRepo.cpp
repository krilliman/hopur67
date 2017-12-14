#include "PizzaPlaceRepo.h"

PizzaPlaceRepo::PizzaPlaceRepo()
{
    //ctor
}


void PizzaPlaceRepo::writeNewPizzaPlace(PizzaPlaces pizzaplace)
{
    readListOfPizzaPlaces();
    ofstream fout;

    fout.open("List_Of_PizzaPlaces.dat" , ios::binary|ios::app);

    int pizzaplaceVectorSize = this->vectorOfPizzaPlaces.size()+1;
    pizzaplace.writePizzaPlace(fout);
    fout.write((char*)(&pizzaplaceVectorSize), sizeof(pizzaplaceVectorSize));

    fout.close();
}
void PizzaPlaceRepo::readListOfPizzaPlaces()
{
    ifstream fin;
    fin.open("List_Of_PizzaPlaces.dat", ios::binary);
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

                cout << "List Size: " << listSize << endl;
                for(int i = 0; i < listSize;i++)
                {
                    PizzaPlaces pizzaplace;

                    pizzaplace.readPizzaPlace(fin);

                    int pizzaplaceNum;
                    fin.read((char*)(&pizzaplaceNum), sizeof(pizzaplaceNum));

                    this->vectorOfPizzaPlaces.push_back(pizzaplace);
                }
            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }

    fin.close();
}
PizzaPlaces PizzaPlaceRepo::getPizzaPlaceFromList(int element)
{
    PizzaPlaces newPizzaplace;

    newPizzaplace = this->vectorOfPizzaPlaces[element-1];
    return newPizzaplace;
}

int PizzaPlaceRepo::readFromListOFPizzaPlaces()
{
    int input = 0;
    int counter = 1;
    readListOfPizzaPlaces();
    cout << "Select a pizza place" << endl;
    for ( vector<PizzaPlaces>::iterator i = vectorOfPizzaPlaces.begin(); i != vectorOfPizzaPlaces.end(); ++i)
    {
        cout << counter  << ": ";
        cout << *i << ' ' << endl << endl;
        counter++;
    }
    cin >> input;
    return input;
}

void PizzaPlaceRepo::printPizzaPlace(vector<PizzaPlaces> vectorOfPizzaPlaces)
{
    for ( vector<PizzaPlaces>::iterator i = vectorOfPizzaPlaces.begin(); i != vectorOfPizzaPlaces.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
