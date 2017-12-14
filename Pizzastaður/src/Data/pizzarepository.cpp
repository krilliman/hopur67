#include "pizzarepository.h"
#include <fstream>
#include "menu.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

void PizzaRepository::storePizza(Pizza& pizza)
{

    vector<alegg> newAleggVector = pizza.getAleggVector();
    int vectorSize = newAleggVector.size();
    char *newBottom = pizza.getBottom();
    int newSize = pizza.getSize();

    ofstream fout;

    fout.open("pizzas.dat", ios::binary | ios::app);

    fout.write((char*)(&newBottom),sizeof(newBottom));
    fout.write((char*)(&newSize),sizeof(newSize));

    fout.write((char*)(&vectorSize), sizeof(vectorSize));
    fout.write((char*)(&newAleggVector),sizeof(alegg));

    fout.close();
}

void PizzaRepository::readPizza()
{
     ifstream fin;

    fin.open("pizzas.dat", ios::binary );


    if(fin.is_open())
        {
            fin.seekg(0,fin.end);
            int listSize = fin.tellg() / sizeof(Pizza);
            fin.seekg(0, fin.beg);

            Pizza pizza;
            for(int i = 0; i < listSize;i++)
            {
                    Pizza newPizza;

                    char *newBottom;
                    fin.read((char*)(&newBottom),sizeof(newBottom));
                    newPizza.setNewBottom(newBottom);

                    int newSize;
                    fin.read((char*)(&newSize),sizeof(newSize));
                    newPizza.setNewSize(newSize);

                    int vectorSize;
                    fin.read((char*)(&vectorSize), sizeof(vectorSize));

                    vector<alegg> newAleggVector;
                    for(int i = 0; i < vectorSize; i++)
                    {
                        alegg newAlegg;
                        fin.read((char*)(&newAlegg),sizeof(alegg));
                        newAleggVector.push_back(newAlegg);
                    }
                    newPizza.setNewAleggVector(newAleggVector);

                pizzas.push_back(newPizza);
            }
        }
        else
        {
            cout << "Could not open file." << endl;
        }


    fin.close();
}
void PizzaRepository::printPizza(vector<Pizza> pizzas)
{
    for ( vector<Pizza>::iterator i = pizzas.begin(); i != pizzas.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
void PizzaRepository::printAllPizzas()
{
    readPizza();
    for ( vector<Pizza>::iterator i = pizzas.begin(); i != pizzas.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}

void PizzaRepository::storeMenu( Menu& menu)
{

    readMenu();
    ofstream fout;
    string name = menu.getName();
    int nameLength = name.length() + 1;

    int priceSmall = menu.getPriceSmall();
    int priceMedium = menu.getPriceMedium();
    int piceLarge = menu.getPriceLarge();

    int menuSize = menuList.size() + 1;


    vector<alegg> newAleggVector = menu.getToppingVector();
    int VectorSize = newAleggVector.size();

    fout.open("Menu_list.dat", ios::binary|ios::app);

    fout.write((char*)(&nameLength), sizeof(nameLength));
    fout.write(name.c_str(),nameLength);

    fout.write((char*)(&priceSmall), sizeof(priceSmall));

    fout.write((char*)(&priceMedium), sizeof(priceMedium));

    fout.write((char*)(&piceLarge), sizeof(piceLarge));


    fout.write((char*)(&VectorSize), sizeof(VectorSize));
    for(int i = 0 ;i < VectorSize; i++)
    {
            fout.write((char*)(&newAleggVector[i]), sizeof(alegg));

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
            cout << "Entering If: ----" << endl;
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

                    int stringLength;
                    fin.read((char*)(&stringLength), sizeof(stringLength));
                    char *str = new char[stringLength];
                    fin.read(str,stringLength);

                    string name = str;
                    menu.setName(name);

                    int newPriceSmall;
                    fin.read((char*)(&newPriceSmall), sizeof(newPriceSmall));
                    menu.setPiceSmall(newPriceSmall);

                    int newPriceMiddle;
                    fin.read((char*)(&newPriceMiddle), sizeof(newPriceMiddle));
                    menu.setPiceMedium(newPriceMiddle);

                    int newPriceLarge;
                    fin.read((char*)(&newPriceLarge), sizeof(newPriceLarge));
                    menu.setPiceLarge(newPriceLarge);

                    int toppingSize;
                    fin.read((char*)(&toppingSize), sizeof(toppingSize));

                    vector<alegg> newAleggVector;
                    for(int i = 0 ;i < toppingSize; i++)
                    {
                            alegg newAlegg;
                            fin.read((char*)(&newAlegg), sizeof(newAlegg));
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
            cout << "Could not open file." << endl;
        }

    fin.close();

}
int PizzaRepository::selectFromMenu()
{
    readMenu();
    int counter = 1;
    int input = 0;

    cout << "Select from given menu: " << endl;
    for ( vector<Menu>::iterator i = menuList.begin(); i != menuList.end(); i++)
    {
        cout << counter << ": ";
        cout << *i << ' ' << endl << endl;
        counter++;
    }
    cin >> input;

    return input;
}

Menu PizzaRepository::selectElementFromMenu(int element)
{
    readMenu();
    Menu newMenu = this->menuList[element-1];
    return newMenu;
}
