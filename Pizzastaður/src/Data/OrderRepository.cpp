#include "OrderRepository.h"
#include <fstream>
OrderRepository::OrderRepository()
{
    //ctor
}


void OrderRepository::writeOrder(newOrder neworder)
{
    readOrder();
    vector<Pizza> pizzaVector = neworder.getPizzaVector();
    vector<SideOrders> sideOrderVector = neworder.getSideOrderVector();
    vector<Beverages> beverageVector = neworder.getBeverageVector();
    //vector<Menu> pizzaFromMenuVector = neworder.getPizzaFromMenuVector();
    PizzaPlaces pizzaplace = neworder.getPizzaPlace();

    int pizzaVectorSize = pizzaVector.size();
    int sideOrderVectorSize = sideOrderVector.size();
    int beverageVectorSize = beverageVector.size();
    //int pizzaFromMenuVectorSize = pizzaFromMenuVector.size();

    neworder.setNewPricePerOrder();

    int picePerOrder = neworder.getPricePerOrder();
    ofstream fout;

    int orderVectorSize = orderVector.size()+1;

    fout.open("Order_list.dat", ios::binary |ios::app);

    fout.write((char*)(&pizzaVectorSize), sizeof(pizzaVectorSize));
    for (int i = 0; i < pizzaVectorSize; ++i)
    {
        vector<alegg> newAleggVector = pizzaVector[i].getAleggVector();
        char *bottom = pizzaVector[i].getBottom();
        int size = pizzaVector[i].getSize();

        fout.write((char*)(&bottom), sizeof(bottom));
        fout.write((char*)(&size), sizeof(size));

        int aleggVectorSize = newAleggVector.size();

        fout.write((char*)(&aleggVectorSize),sizeof(aleggVectorSize));
        for(int i = 0; i < aleggVectorSize;i++)
        {
            fout.write((char*)(&newAleggVector[i]),sizeof(alegg));
        }
    }



    fout.write((char*)(&sideOrderVectorSize), sizeof(sideOrderVectorSize));

    for (int i = 0; i < sideOrderVectorSize; ++i)
    {
        fout.write((char*)(&sideOrderVector[i]), sizeof(SideOrders));
    }

    fout.write((char*)(&beverageVectorSize), sizeof(beverageVectorSize));

    for (int i = 0; i < beverageVectorSize; ++i)
    {
        fout.write((char*)(&beverageVector[i]), sizeof(Beverages));
    }

    fout.write((char*)(&pizzaplace),sizeof(pizzaplace));

    fout.write((char*)(&picePerOrder),sizeof(picePerOrder));

    fout.write((char*)(&orderVectorSize),sizeof(orderVectorSize));

    fout.close();
}
void OrderRepository::readOrder()
{


    ifstream fin;
    fin.open("Order_list.dat", ios::binary);

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
            fin.read((char*)(&listSize),sizeof(listSize));
            fin.seekg(0,fin.beg);

            cout << "List Size: " << listSize << endl;

            for(int i = 0; i < listSize;i++)
            {
                newOrder neworder;


                    vector<Pizza> pizzaVector;
                    int pizzaSize;
                    fin.read((char*)(&pizzaSize),sizeof(pizzaSize));
                    for(int i = 0; i< pizzaSize;i++)
                    {
                        Pizza newPizza;
                        char *bottom;
                        fin.read((char*)(&bottom), sizeof(bottom));
                        newPizza.setNewBottom(bottom);

                        int size;
                        fin.read((char*)(&size), sizeof(size));
                        newPizza.setNewSize(size);

                        int aleggVectorSize;
                        fin.read((char*)(&aleggVectorSize),sizeof(aleggVectorSize));

                        vector<alegg> newAleggVector;
                        for(int i = 0; i < aleggVectorSize;i++)
                        {
                            alegg newAlegg;
                            fin.read((char*)(&newAlegg),sizeof(alegg));
                            newAleggVector.push_back(newAlegg);
                        }
                        newPizza.setNewAleggVector(newAleggVector);

                        pizzaVector.push_back(newPizza);
                    }
                    neworder.setPizzaVector(pizzaVector);

                int sideOrderSize;
                fin.read((char*)(&sideOrderSize),sizeof(sideOrderSize));

                vector<SideOrders> sideOrderVector;
                for(int i = 0; i < sideOrderSize;i++)
                {
                    SideOrders newSideorder;
                    fin.read((char*)(&newSideorder), sizeof(SideOrders));
                    sideOrderVector.push_back(newSideorder);
                }
                neworder.setSideOrderVector(sideOrderVector);

                int BevergeSize;
                fin.read((char*)(&BevergeSize), sizeof(BevergeSize));
                vector<Beverages> beverageVector;

                for(int i = 0; i < BevergeSize;i++)
                {
                    Beverages newBeverage;
                    fin.read((char*)(&newBeverage), sizeof(Beverages));
                    beverageVector.push_back(newBeverage);
                }
                neworder.setBeverageVector(beverageVector);

                PizzaPlaces newPizzaPlace;
                fin.read((char*)(&newPizzaPlace), sizeof(PizzaPlaces));
                neworder.setPizzaPlace(newPizzaPlace);

                int pricePerOrder;

                fin.read((char*)(&pricePerOrder),sizeof(pricePerOrder));
                neworder.setPricePerOrder(pricePerOrder);

                int ordernum;
                fin.read((char*)(&ordernum),sizeof(ordernum));

                this->orderVector.push_back(neworder);
            }
        }
    }
    else
    {
        cout << "Could not open file." << endl;
    }

    fin.close();
}

void OrderRepository::printOrderList()
{
    readOrder();
    for ( vector<newOrder>::iterator i = orderVector.begin(); i != orderVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}

void OrderRepository::setNewOrderFromMenu(orderFromMenu newOrderfromMenu)
{
    readOrderFromMenu();

    vector<SideOrders> sideOrderVector = newOrderfromMenu.getSideOrderVector();
    vector<Beverages> beverageVector = newOrderfromMenu.getBeverageVector();
    vector<Menu> pizzaFromMenuVector = newOrderfromMenu.getPizzaFromMenuVector();
    PizzaPlaces pizzaplace = newOrderfromMenu.getPizzaPlace();

    int sideOrderVectorSize = sideOrderVector.size();
    int beverageVectorSize = beverageVector.size();
    int pizzaFromMenuVectorSize = pizzaFromMenuVector.size();

    newOrderfromMenu.setNewPricePerOrder();

    int picePerOrder = newOrderfromMenu.getPricePerOrder();
    ofstream fout;

    int orderVectorSize = orderFromMenuVector.size()+1;

    fout.open("Order_fromMenu_list.dat", ios::binary |ios::app);

    fout.write((char*)(&pizzaFromMenuVectorSize), sizeof(pizzaFromMenuVectorSize));

        for(int i = 0;i < pizzaFromMenuVectorSize;i++)
        {
            vector<alegg> newAleggVector = pizzaFromMenuVector[i].getToppingVector();
            int newAleggVectorSize = newAleggVector.size();

            int priceSmall = pizzaFromMenuVector[i].getPriceSmall();
            int priceMiddle = pizzaFromMenuVector[i].getPriceMedium();
            int priceLarge = pizzaFromMenuVector[i].getPriceLarge();
            string menuName = pizzaFromMenuVector[i].getName();

            int nameLength = menuName.length()+1;
            fout.write((char*)(&nameLength), sizeof(nameLength));
            fout.write(menuName.c_str(),nameLength);

            fout.write((char*)(&priceSmall),sizeof(priceSmall));
            fout.write((char*)(&priceMiddle), sizeof(priceMiddle));
            fout.write((char*)(&priceLarge), sizeof(priceLarge));

            fout.write((char*)(&newAleggVectorSize),sizeof(newAleggVectorSize));

            for(int i = 0; i < newAleggVectorSize; i++)
            {
                fout.write((char*)(&newAleggVector[i]), sizeof(alegg));
            }


        }

        fout.write((char*)(&sideOrderVectorSize), sizeof(sideOrderVectorSize));

        for (int i = 0; i < sideOrderVectorSize; ++i)
        {
            fout.write((char*)(&sideOrderVector[i]), sizeof(SideOrders));
        }

        fout.write((char*)(&beverageVectorSize), sizeof(beverageVectorSize));

        for (int i = 0; i < beverageVectorSize; ++i)
        {
            fout.write((char*)(&beverageVector[i]), sizeof(Beverages));
        }

        fout.write((char*)(&pizzaplace),sizeof(pizzaplace));

        //fout.write((char*)(&picePerOrder),sizeof(picePerOrder));

        fout.write((char*)(&orderVectorSize),sizeof(orderVectorSize));

        fout.close();
}
void OrderRepository::readOrderFromMenu()
{
    ifstream fin;
    fin.open("Order_fromMenu_list.dat", ios::binary);

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
            fin.read((char*)(&listSize),sizeof(listSize));
            fin.seekg(0,fin.beg);

            cout << "List Size: " << listSize << endl;

            for(int i = 0; i < listSize;i++)
            {
                    orderFromMenu neworder;


                    vector<Menu> pizzaOnMenuVector;

                    int pizzaOnMenuVectorSize;
                    fin.read((char*)(&pizzaOnMenuVectorSize), sizeof(pizzaOnMenuVectorSize));
                    for(int i = 0;i < pizzaOnMenuVectorSize; i++)
                    {
                        cout << "Entering for:"<< endl;
                        Menu newPizzaOnMenu;
                        int stringLength;
                         cout << "before reading string:"<< endl;
                        fin.read((char*)(&stringLength), sizeof(stringLength));
                        char *str = new char[stringLength];
                        fin.read(str,stringLength);
                         cout << "after reading string:"<< endl;

                        string name = str;
                        newPizzaOnMenu.setName(str);
                         cout << "before price small:"<< endl;
                        int priceSmall;
                        fin.read((char*)(&priceSmall), sizeof(priceSmall));
                        newPizzaOnMenu.setPiceSmall(priceSmall);

                         cout << "before price medium :"<< endl;
                        int priceMedium;
                        fin.read((char*)(&priceMedium), sizeof(priceMedium));
                        newPizzaOnMenu.setPiceSmall(priceMedium);

                         cout << "before price Large:"<< endl;
                        int priceLarge;
                        fin.read((char*)(&priceLarge), sizeof(priceLarge));
                        newPizzaOnMenu.setPiceSmall(priceLarge);

                        int aleggVectorSize;
                        fin.read((char*)(&aleggVectorSize),sizeof(aleggVectorSize));

                        vector<alegg> newAleggVector;
                        cout << "Size of aleggVector: " << aleggVectorSize << endl;

                         cout << "before alegg for:"<< endl;
                        for(int i = 0; i < aleggVectorSize; i++)
                        {
                            alegg newAlegg;
                            fin.read((char*)(&newAlegg), sizeof(newAlegg));
                            newAleggVector.push_back(newAlegg);
                        }
                        newPizzaOnMenu.setToppinNames(newAleggVector);
                        cout << "after entering alegg to vector"<< endl;
                        pizzaOnMenuVector.push_back(newPizzaOnMenu);
                        cout << "after setting pizza menu to vector:"<< endl;

                    }
                    neworder.setPizzaFromMenuVector(pizzaOnMenuVector);

                    cout << "fished with the menu pizza:"<< endl;


                int sideOrderSize;
                fin.read((char*)(&sideOrderSize),sizeof(sideOrderSize));

                vector<SideOrders> sideOrderVector;
                for(int i = 0; i < sideOrderSize;i++)
                {
                    SideOrders newSideorder;
                    fin.read((char*)(&newSideorder), sizeof(SideOrders));
                    sideOrderVector.push_back(newSideorder);
                }
                neworder.setSideOrderVector(sideOrderVector);

                int BevergeSize;
                fin.read((char*)(&BevergeSize), sizeof(BevergeSize));
                vector<Beverages> beverageVector;

                for(int i = 0; i < BevergeSize;i++)
                {
                    Beverages newBeverage;
                    fin.read((char*)(&newBeverage), sizeof(Beverages));
                    beverageVector.push_back(newBeverage);
                }
                neworder.setBeverageVector(beverageVector);

                PizzaPlaces newPizzaPlace;
                fin.read((char*)(&newPizzaPlace), sizeof(PizzaPlaces));
                neworder.setPizzaPlace(newPizzaPlace);

                /*
                int pricePerOrder;

                fin.read((char*)(&pricePerOrder),sizeof(pricePerOrder));
                neworder.setPricePerOrder(pricePerOrder);
                */

                int ordernum;
                fin.read((char*)(&ordernum),sizeof(ordernum));

                this->orderFromMenuVector.push_back(neworder);
                cout << "New order check: ---" << endl << neworder << endl;
            }
        }
    }
    else
    {
        cout << "Could not open file." << endl;
    }

    fin.close();

}
void OrderRepository::printOrderFromMenuList()
{
    readOrderFromMenu();
    for ( vector<orderFromMenu>::iterator i = orderFromMenuVector.begin(); i != orderFromMenuVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}
