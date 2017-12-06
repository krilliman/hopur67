#include "pizza.h"
Pizza::Pizza()
{
    toppings = NULL;
    toppingCount = 0;
    currentToppingNum = 0;
    name[0] = '\0';
    menuPizza = false;
}

Pizza::~Pizza()
{
    clean();
}

Pizza::Pizza(int numberOfToppings)
{
    initialize(numberOfToppings);
}

void Pizza::initialize(int numberOfToppings)
{
    toppingCount = numberOfToppings;
    toppings = new alegg[toppingCount];
}
void Pizza::clean()
{
    if(toppings != NULL)
    {
        delete[] toppings;
    }
}
void Pizza::addTopping(alegg topping)
{
    if(currentToppingNum < toppingCount)
    {
        toppings[currentToppingNum] = topping;
        currentToppingNum++;
    }
}

void Pizza::write(ofstream& fout) const
{
    fout.write((char*)(&toppingCount), sizeof(int));
    fout.write((char*)toppings, sizeof(alegg) * toppingCount);

}
void Pizza::read(ifstream& fin)
{
    int topCnt;
    fin.read((char*)(&topCnt), sizeof(int));

    initialize(topCnt);
    fin.read((char*)toppings, sizeof(alegg) * toppingCount);
    currentToppingNum = toppingCount;
}


void Pizza::setMenuPizza(bool n)
{
    menuPizza = n;
}

ostream& operator <<(ostream& out ,const Pizza& pizza)
{
    if(pizza.menuPizza)
    {
        cout << "Name of the Pizza : ";
        out << pizza.name << endl;
    }
    for(int i = 0; i < pizza.toppingCount;i++)
    {
        out << pizza.toppings[i];
    }
}
istream& operator >>(istream& in, Pizza& pizza)
{
    int topCnt;
    bool n = false;

    if(pizza.menuPizza)
    {
        cout << "Enter Name For the Pizza: ";
        in >> pizza.name;
    }
    cout << "Enter Number Of Toppings: ";
    in >> topCnt;

    pizza.initialize(topCnt);

    alegg topping;
    topping.setAddOrNot(n);
    for(int i = 0; i < topCnt;i++)
    {
        in >> topping;
        pizza.addTopping(topping);
    }
    return in;

}
