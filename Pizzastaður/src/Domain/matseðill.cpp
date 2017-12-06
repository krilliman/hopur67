#include "matseðill.h"
#include <fstream>
matsedill::matsedill()
{
    nafn[0] = '\0';
    verdLitil = 0;
    verdMid = 0;
    verdStor = 0;

    verbose = true;
}

bool matsedill::check(bool verbose)
{
    this->verbose = verbose;
}

ostream& operator << (ostream& out, const matsedill listi)
{
    if(listi.verbose)
    {
        cout << "Nafn: ";
    }
    out << listi.nafn << endl;
    if(listi.verbose)
    {
        cout << "verdLitil: ";
    }
    out << listi.verdLitil << endl;
    if(listi.verbose)
    {
        cout << "verdMid: ";
    }
    out << listi.verdMid << endl;
    if(listi.verbose)
    {
        cout << "verdStor: ";
    }
    out << listi.verdStor << endl;

    return out;
}

istream& operator >> (istream& in, matsedill& listi)
{
    if(listi.verbose)
    {
        cout << "Nafn: ";
    }
    in >> listi.nafn;
    if(listi.verbose)
    {
        cout << "VerdLitil: ";
    }
    in >> listi.verdLitil;
    if(listi.verbose)
    {
        cout << "VerdMid: ";
    }
    in >> listi.verdMid;
    if(listi.verbose)
    {
        cout << "verdStor: ";
    }
    in >> listi.verdStor;

    return in;
}
