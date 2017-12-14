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

    PizzaPlaces pizzaplace = neworder.getPizzaPlace();

    int pizzaVectorSize = pizzaVector.size();
    int sideOrderVectorSize = sideOrderVector.size();
    int beverageVectorSize = beverageVector.size();

    neworder.setNewPricePerOrder();

    int picePerOrder = neworder.getPricePerOrder();
    ofstream fout;

    int orderVectorSize = orderVector.size()+1;

    fout.open("Order_list.dat", ios::binary |ios::app);

    fout.write((char*)(&pizzaVectorSize), sizeof(pizzaVectorSize));
    for (int i = 0; i < pizzaVectorSize; ++i)
    {
        vector<alegg> newAleggVector = pizzaVector[i].getAleggVector();
        int newAleggVectorSize = newAleggVector.size();

        pizzaVector[i].writePizza(fout);



        fout.write((char*)(&newAleggVectorSize),sizeof(newAleggVectorSize));
        cout << "writing down size of alegg array: " << newAleggVectorSize << endl;

        for(int i = 0; i < newAleggVectorSize; i++)
        {
            newAleggVector[i].writeAlegg(fout);
        }
    }

    fout.write((char*)(&sideOrderVectorSize), sizeof(sideOrderVectorSize));

    for (int i = 0; i < sideOrderVectorSize; ++i)
    {
        sideOrderVector[i].writeSideOrder(fout);
    }

    fout.write((char*)(&beverageVectorSize), sizeof(beverageVectorSize));

    for (int i = 0; i < beverageVectorSize; ++i)
    {
        beverageVector[i].writeBeverage(fout);
    }

    pizzaplace.writePizzaPlace(fout);

    //fout.write((char*)(&picePerOrder),sizeof(picePerOrder));

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
                    cout << "pizza Size :" << pizzaSize << endl;
                    for(int i = 0; i< pizzaSize;i++)
                    {
                        Pizza newPizza;

                        newPizza.readPizza(fin);

                        int aleggVectorSize;
                        fin.read((char*)(&aleggVectorSize),sizeof(aleggVectorSize));

                        cout << "alegg vector size before loop" << aleggVectorSize << endl;
                        vector<alegg> newAleggVector;

                        for(int i = 0; i < aleggVectorSize; i++)
                        {
                            cout << "alegg vector size inside loop" << aleggVectorSize <<endl;
                            alegg newAlegg;
                            newAlegg.readAlegg(fin);
                            newAleggVector.push_back(newAlegg);
                        }

                        cout << "exiting alegg " << endl;
                        newPizza.setNewAleggVector(newAleggVector);
                        pizzaVector.push_back(newPizza);
                    }
                    neworder.setPizzaVector(pizzaVector);

                int sideOrderSize;
                fin.read((char*)(&sideOrderSize),sizeof(sideOrderSize));

                vector<SideOrders> sideOrderVector;

                cout << "before SideOrder " << endl;
                for(int i = 0; i < sideOrderSize;i++)
                {
                    SideOrders newSideorder;
                    newSideorder.readSideOrder(fin);
                    sideOrderVector.push_back(newSideorder);
                }
                neworder.setSideOrderVector(sideOrderVector);

                int BevergeSize;
                fin.read((char*)(&BevergeSize), sizeof(BevergeSize));
                vector<Beverages> beverageVector;
                cout << "before Beverage " << endl;
                for(int i = 0; i < BevergeSize;i++)
                {
                    Beverages newBeverage;
                    newBeverage.readBeverage(fin);
                    beverageVector.push_back(newBeverage);
                }
                neworder.setBeverageVector(beverageVector);

                PizzaPlaces newPizzaPlace;
                newPizzaPlace.readPizzaPlace(fin);
                neworder.setPizzaPlace(newPizzaPlace);

                //int pricePerOrder;

                //fin.read((char*)(&pricePerOrder),sizeof(pricePerOrder));
                //neworder.setPricePerOrder(pricePerOrder);

                int ordernum;
                fin.read((char*)(&ordernum),sizeof(ordernum));

                this->orderVector.push_back(neworder);
                cout << "leaving fin" << endl;
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
    vector<string> sizeOfPizzas = newOrderfromMenu.getSizeOfPizzas();
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

            pizzaFromMenuVector[i].writeMenu(fout);

            fout.write((char*)(&newAleggVectorSize),sizeof(newAleggVectorSize));

            for(int i = 0; i < newAleggVectorSize; i++)
            {
                newAleggVector[i].writeAlegg(fout);
            }

            string pizzaSize = sizeOfPizzas[i];
            int sizeLength = pizzaSize.length()+ 1;
            fout.write((char*)(&sizeLength), sizeof(sizeLength));
            fout.write(pizzaSize.c_str(),sizeLength);



        }

        fout.write((char*)(&sideOrderVectorSize), sizeof(sideOrderVectorSize));

        for (int i = 0; i < sideOrderVectorSize; ++i)
        {
            sideOrderVector[i].writeSideOrder(fout);
        }

        fout.write((char*)(&beverageVectorSize), sizeof(beverageVectorSize));

        for (int i = 0; i < beverageVectorSize; ++i)
        {
            beverageVector[i].writeBeverage(fout);
        }

        pizzaplace.writePizzaPlace(fout);

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
                    vector<string> newSizeOfPizzaVector;

                    int pizzaOnMenuVectorSize;
                    fin.read((char*)(&pizzaOnMenuVectorSize), sizeof(pizzaOnMenuVectorSize));
                    for(int i = 0;i < pizzaOnMenuVectorSize; i++)
                    {
                        Menu newPizzaOnMenu;
                        newPizzaOnMenu.readMenu(fin);

                        int aleggVectorSize;
                        fin.read((char*)(&aleggVectorSize),sizeof(aleggVectorSize));

                        vector<alegg> newAleggVector;

                        for(int i = 0; i < aleggVectorSize; i++)
                        {
                            alegg newAlegg;
                            newAlegg.readAlegg(fin);
                            newAleggVector.push_back(newAlegg);
                        }
                        newPizzaOnMenu.setToppinNames(newAleggVector);

                        int sizeOfPizzaLength;
                        fin.read((char*)(&sizeOfPizzaLength), sizeof(sizeOfPizzaLength));
                        char *newString = new char[sizeOfPizzaLength];
                        fin.read(newString,sizeOfPizzaLength);

                        string newPizzaSize = newString;
                        newSizeOfPizzaVector.push_back(newPizzaSize);

                        pizzaOnMenuVector.push_back(newPizzaOnMenu);

                    }
                    neworder.setSizeOfPizzas(newSizeOfPizzaVector);
                    neworder.setPizzaFromMenuVector(pizzaOnMenuVector);



                int sideOrderSize;
                fin.read((char*)(&sideOrderSize),sizeof(sideOrderSize));

                vector<SideOrders> sideOrderVector;
                for(int i = 0; i < sideOrderSize;i++)
                {
                    SideOrders newSideorder;
                    newSideorder.readSideOrder(fin);
                    sideOrderVector.push_back(newSideorder);
                }
                neworder.setSideOrderVector(sideOrderVector);

                int BevergeSize;
                fin.read((char*)(&BevergeSize), sizeof(BevergeSize));
                vector<Beverages> beverageVector;

                for(int i = 0; i < BevergeSize;i++)
                {
                    Beverages newBeverage;
                    newBeverage.readBeverage(fin);
                    beverageVector.push_back(newBeverage);
                }
                neworder.setBeverageVector(beverageVector);

                PizzaPlaces newPizzaPlace;
                newPizzaPlace.readPizzaPlace(fin);
                neworder.setPizzaPlace(newPizzaPlace);


                //int pricePerOrder;

                //fin.read((char*)(&pricePerOrder),sizeof(pricePerOrder));
                //neworder.setPricePerOrder(pricePerOrder);


                int ordernum;
                fin.read((char*)(&ordernum),sizeof(ordernum));

                this->orderFromMenuVector.push_back(neworder);
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
