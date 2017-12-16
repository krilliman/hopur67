#include "pizzarepository.h"
#include <fstream>
#include "menu.h"
#include <userInputCheck.h>

PizzaRepository::PizzaRepository()
{
    //ctor
}

void PizzaRepository::storeMenu( Menu& menu)
{

    readMenu();
    ofstream fout;
    int menuSize = menuList.size() + 1;

    vector<alegg> newAleggVector = menu.getToppingVector();
    int VectorSize = newAleggVector.size();

    fout.open("Menu_list.dat", ios::binary|ios::app);

    menu.writeMenu(fout);
    fout.write((char*)(&VectorSize), sizeof(VectorSize));
    for(int i = 0 ;i < VectorSize; i++)
    {
            newAleggVector[i].writeAlegg(fout);
    }

    fout.write((char*)(&menuSize), sizeof(menuSize));
    fout.close();
}

void PizzaRepository::readMenu()
{
    ifstream fin;
    fin.open("Menu_list.dat", ios::binary);
        if(fin.is_open())
        {
            fin.seekg(0,fin.end);
            int listSize = fin.tellg();
            fin.seekg(0,fin.beg);
            if(listSize == 0)
            {

            }
            else
            {
                int menuSize;
                fin.seekg(-4,fin.end);
                fin.read((char*)(&menuSize), sizeof(menuSize));
                fin.seekg(0,fin.beg);
                for(int i = 0; i < menuSize;i++)
                {
                    Menu menu;

                    menu.readMenu(fin);

                    int toppingSize;
                    fin.read((char*)(&toppingSize), sizeof(toppingSize));

                    vector<alegg> newAleggVector;

                    for(int i = 0 ;i < toppingSize; i++)
                    {
                            alegg newAlegg;
                            newAlegg.readAlegg(fin);
                            newAleggVector.push_back(newAlegg);
                    }
                        menu.setToppinNames(newAleggVector);

                    int orderNum;

                    fin.read((char*)(&orderNum),sizeof(orderNum));

                    this->menuList.push_back(menu);

                }
            }

        }
        else
        {
            //cout << "Could not open file." << endl;
        }

    fin.close();

}
int PizzaRepository::selectFromMenu()
{
    userInputCheck newuserinput;
    readMenu();
    string newInput;
    int input;
    int newCounter = 0;
    while(newCounter == 0)
    {
         int counter = 1;
            cout << "Select pizza from menu: " << endl;
            cout << "-------------------------------------------------------" << endl;
            for ( vector<Menu>::iterator i = menuList.begin(); i != menuList.end(); i++)
            {
                cout << counter << ": ";
                cout << *i << ' ' << endl << endl;
                counter++;
            }
            cin >> newInput;
            if(newuserinput.checkInRangeMenu(newInput) == true)
            {
                input = stoi(newInput);
                newCounter++;
            }
            else
            {
              cout << "invalid input " << endl;
            }
    }

    return input;


}

Menu PizzaRepository::selectElementFromMenu(int element)
{
    readMenu();
    Menu newMenu = this->menuList[element-1];
    return newMenu;
}
