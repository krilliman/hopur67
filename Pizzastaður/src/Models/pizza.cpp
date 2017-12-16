#include "pizza.h"
#include "toppinglist.h"
#include <aleggrepository.h>
Pizza::Pizza()
{
    bottom = " ";
    size = '\0';
    notMenuPizza = true;
}
void Pizza::setMenuPizza(bool n)
{
    this->notMenuPizza = n;
}


void Pizza::writePizza(ofstream &fout)
{
    int bottomSize = bottom.length()+1;

    fout.write((char*)(&bottomSize), sizeof(bottomSize));
    fout.write(bottom.c_str(),bottomSize);
    fout.write((char*)(&size), sizeof(size));
}
void Pizza::readPizza(istream& fin)
{
    int bottomSize;
    fin.read((char*)(&bottomSize) , sizeof(bottomSize));
    char *str = new char[bottomSize];
    fin.read(str,bottomSize);

    string bottomTemp = str;
    this->setNewBottom(bottomTemp);

    char newSize;
    fin.read((char*)(&newSize), sizeof(newSize));

    setNewSize(newSize);

}

void Pizza::setNewBottom(string bottom)
{
    this->bottom = bottom;
}
void Pizza::setNewSize(char size)
{
    this->size = size;
}
void Pizza::setNewAleggVector(vector<alegg> aleggVector)
{
    this->aleggVector = aleggVector;
}

string Pizza::getBottom()
{
    return this->bottom;
}
char Pizza::getSize()
{
    return this->size;
}
vector<alegg> Pizza::getAleggVector()
{
    return this->aleggVector;
}
ostream& operator <<(ostream& out, const Pizza& pizza)
{

    cout << "Crust type: ";
    out << pizza.bottom << endl;
    cout << "-------------------------------------------------------" << endl;

    cout << "Size: ";
    out << pizza.size << endl;
    cout << "-------------------------------------------------------" << endl;

    for ( vector<alegg>::const_iterator i = pizza.aleggVector.begin(); i != pizza.aleggVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
    return out;
}
istream& operator >>(istream& in, Pizza& pizza)
{

    //cout << "TEST 1: --- " << endl;

    if(pizza.notMenuPizza == false)
    {

        string bottom1 = "Normal";
        string bottom2 = "Thin";
        string bottom3 = "Pan";
        int input;
        cout << "Please choose crust: " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1." << bottom1 << endl;
        cout << "2." << bottom2 << endl;
        cout << "3." <<  bottom3 << endl;
        in >> input;

        if(input == 1)
        {
            pizza.bottom = bottom1;
        }
        else if (input == 2)
        {
            pizza.bottom = bottom2;
        }
        else if(input == 3)
        {
            pizza.bottom = bottom3;
        }

        cout << "Please choose size: " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1." << "Small" << endl;
        cout << "2." << "Medium" << endl;
        cout << "3." <<  "Large" << endl;
        char input2;
        cin >> input2;
        pizza.setNewSize(input2);

    }
    cout << "How many toppings would you like? ";
    int topCnt;
    in >> topCnt;
    cout << "-------------------------------------------------------" << endl;
    for(int i = 0; i < topCnt;i++)
    {

        AleggRepository aleggRepo;

        int element = aleggRepo.printTopListStandard();
        alegg newTopping = aleggRepo.getAleggFromList(element);
        pizza.aleggVector.push_back(newTopping);
    }

    return in;

}
