#include "pizza.h"
Pizza::Pizza()
{
    toppings = NULL;
    toppingCount = 0;
    currentToppingNum = 0;
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

ostream& operator <<(ostream& out ,const Pizza& pizza)
{
    for(int i = 0; i < pizza.toppingCount;i++)
    {
        out << pizza.toppings[i];
    }
}
istream& operator >>(istream& in, Pizza& pizza)
{
    int topCnt;
    in >> topCnt;

    pizza.initialize(topCnt);

    alegg topping;

    for(int i = 0; i < topCnt;i++)
    {
        in >> topping;
        pizza.addTopping(topping);
    }
    return in;

}
