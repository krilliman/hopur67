#include "PizzaPlaceRepo.h"
#include <userInputCheck.h>

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
            //cout << "Could not open file." << endl;
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
    readListOfPizzaPlaces();
    userInputCheck newuserInput;
    string input;
    int newCounter = 0;
    int newInput;
    while(newCounter == 0)
    {
        int counter = 1;

        cout << "Select a pizza place: " << endl;
        cout << "-------------------------------------------------------" << endl;
        for ( vector<PizzaPlaces>::iterator i = vectorOfPizzaPlaces.begin(); i != vectorOfPizzaPlaces.end(); ++i)
        {
            cout << " * " << counter  << " * : ";
            cout << *i << ' ' << endl << endl;
            cout << "-------------------------------------------------------" << endl;
            counter++;
        }
        cin >> input;
        cout << "-------------------------------------------------------" << endl;
        if(newuserInput.checkInRangePizzaPlace(input) == true)
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

void PizzaPlaceRepo::printPizzaPlace(vector<PizzaPlaces> vectorOfPizzaPlaces)
{
    for ( vector<PizzaPlaces>::iterator i = vectorOfPizzaPlaces.begin(); i != vectorOfPizzaPlaces.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
