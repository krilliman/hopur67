#include "matseğill.h"
#include <fstream>
matsedill::matsedill()
{
    nafn[0] = '\0';
    verdLitil = 0;
    verdMid = 0;
    verdStor = 0;

}


ostream& operator << (ostream& out, const matsedill listi)
{

    cout << "Nafn: ";
    out << listi.nafn << endl;

    cout << "verdLitil: ";
    out << listi.verdLitil << endl;

    cout << "verdMid: ";
    out << listi.verdMid << endl;

    cout << "verdStor: ";
    out << listi.verdStor << endl;

    return out;
}

istream& operator >> (istream& in, matsedill& listi)
{

    cout << "Nafn: ";
    in >> listi.nafn;

    cout << "VerdLitil: ";
    in >> listi.verdLitil;

    cout << "VerdMid: ";
    in >> listi.verdMid;

    cout << "verdStor: ";
    in >> listi.verdStor;

    return in;
}
