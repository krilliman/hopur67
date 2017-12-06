#include "alegg.h"
#include <fstream>
alegg::alegg()
{
    nafn[0] = '\0';
    verdLitil = 0;
    verdMid = 0;
    verdStor = 0;
    addOrNot = true;
}


void alegg::setAddOrNot(bool n)
{
    addOrNot = n;
}


istream& operator >> (istream& in, alegg& nyttalegg)
{

    cout << "Name Of Topping: ";
    in >> nyttalegg.nafn;

    if(nyttalegg.addOrNot)
    {
        cout << "Price Little: ";
        in >> nyttalegg.verdLitil;
    }

    if(nyttalegg.addOrNot)
    {
        cout << "Price Middle: ";
        in >> nyttalegg.verdMid;
    }

    if(nyttalegg.addOrNot)
    {
        cout << "Price Big: ";
        in >> nyttalegg.verdStor;
    }

    return in;

}
ostream& operator << (ostream& out, const alegg skrifalegg)
{

    cout << "Topping name: ";
    out << skrifalegg.nafn << endl;
    if(skrifalegg.addOrNot)
    {
        cout << "Price Little: ";
        out << skrifalegg.verdLitil << endl;
    }

    if(skrifalegg.addOrNot)
    {
        cout << "Price Middle : ";
        out << skrifalegg.verdMid << endl;
    }
    if(skrifalegg.addOrNot)
    {
        cout << "Price Big: ";
        out << skrifalegg.verdStor << endl;
    }

    return out;
}
