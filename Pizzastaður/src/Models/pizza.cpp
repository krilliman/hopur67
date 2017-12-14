#include "pizza.h"
#include "toppinglist.h"
#include <aleggrepository.h>
Pizza::Pizza()
{
    bottom = " ";
    size = " ";
    notMenuPizza = true;
}
void Pizza::setMenuPizza(bool n)
{
    this->notMenuPizza = n;
}


void Pizza::writePizza(ofstream &fout)
{
    cout << "Entering writePizza" << endl;
    int bottomSize = this->bottom.length()+1;
    int sizeSize = this->size.length()+1;

    fout.write((char*)(&bottomSize), sizeof(bottomSize));
    fout.write(bottom.c_str(),bottomSize);

    cout << "writing size: " << this->size << endl;
    fout.write((char*)(&sizeSize), sizeof(sizeSize));
    fout.write(size.c_str(),sizeSize);
    cout << "leaving writePizza" << endl;
}
void Pizza::readPizza(ifstream &fin)
{
    cout << "Entering readPizza" << endl;
    int bottomSize;
    fin.read((char*)(&bottomSize) , sizeof(bottomSize));
    char *str = new char[bottomSize];
    fin.read(str,bottomSize);

    string bottomTemp = str;
    this->setNewBottom(bottomTemp);
    cout << "bottomTemp: " << bottomTemp << endl;

    int sizeSize;
    fin.read((char*)(&sizeSize) , sizeof(sizeSize));
    char *str2 = new char[sizeSize];
    fin.read(str2,bottomSize);

    string sizeTemp = str2;
    cout << "sizetemp: " << sizeTemp << endl;
    this->setNewSize(sizeTemp);
    cout << "leaving readPizza" << endl;
}

void Pizza::setNewBottom(string bottom)
{
    this->bottom = bottom;
}
void Pizza::setNewSize(string size)
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
string Pizza::getSize()
{
    return this->size;
}
vector<alegg> Pizza::getAleggVector()
{
    return this->aleggVector;
}
ostream& operator <<(ostream& out, const Pizza& pizza)
{

    cout << "Bottom type: ";
    out << pizza.bottom << endl;

    cout << "Pizza Size: ";
    out << pizza.size << endl;

    for ( vector<alegg>::const_iterator i = pizza.aleggVector.begin(); i != pizza.aleggVector.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
    return out;
}
istream& operator >>(istream& in, Pizza& pizza)
{

    cout << "TEST 1: --- " << endl;

    if(pizza.notMenuPizza == false)
    {

        string bottom1 = "Normal";
        string bottom2 = "Thin";
        string bottom3 = "pan";
        int input;
        cout << "Choose a bottom: " << endl;
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

        cout << "choose a size " << endl;
        cout << "1." << "small" << endl;
        cout << "2." << "medium" << endl;
        cout << "3." <<  "large" << endl;
        string input2;
        cin >> input2;
        pizza.setNewSize(input2);

    }
    cout << "Enter Number Of Toppings: ";
    int topCnt;
    in >> topCnt;
    for(int i = 0; i < topCnt;i++)
    {

        AleggRepository aleggRepo;

        int element = aleggRepo.printTopListStandard();
        alegg newTopping = aleggRepo.getAleggFromList(element);
        pizza.aleggVector.push_back(newTopping);

        cout << "pizza cin newTopping: " << i+1 << newTopping << endl;
    }

    return in;

}
