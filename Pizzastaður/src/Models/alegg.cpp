#include "alegg.h"



alegg::alegg()
{
    nafn[0] = '\0';
    verdLitil = 0;
    verdMid = 0;
    verdStor = 0;
    addOrNot = true;
}

char* alegg::getName()
{
    return this->nafn;
}

int alegg::getPriceSmall()
{
    return this->verdLitil;
}
int alegg::getPriceMedium()
{
    return this->verdMid;
}
int alegg::getPriceLarge()
{
    return this->verdStor;
}


istream& operator >> (istream& in, alegg& nyttalegg)
{

    cout << "Name Of Topping: ";
    in >> nyttalegg.nafn;

    cout << "Price Little: ";
    in >> nyttalegg.verdLitil;

    cout << "Price Middle: ";
    in >> nyttalegg.verdMid;

    cout << "Price Big: ";
    in >> nyttalegg.verdStor;

    return in;

}
ostream& operator << (ostream& out, const alegg skrifalegg)
{

    cout << "Topping name: ";
    out << skrifalegg.nafn << endl;

    cout << "Price Little: ";
    out << skrifalegg.verdLitil << endl;

    cout << "Price Middle : ";
    out << skrifalegg.verdMid << endl;


    cout << "Price Big: ";
    out << skrifalegg.verdStor << endl;


    return out;
}
