#include "alegg.h"
#include <fstream>
alegg::alegg()
{
    nafn[0] = '\0';
    tegund[0] = '\0';
    verdLitil = 0;
    verdMid = 0;
    verdStor = 0;
}

void alegg::setVerbose(bool v)
{
    verbose = v;
}



istream& operator >> (istream& in, alegg& nyttalegg)
{
    if(nyttalegg.verbose)
    {
        cout << "Nafn:";
        in >> nyttalegg.nafn;
    }


    if(nyttalegg.verbose)
    {
        cout << "tegund:";
        in >> nyttalegg.tegund;
    }

    if(nyttalegg.verbose)
    {
        cout << "verd Litil:";
        in >> nyttalegg.verdLitil;
    }
    if(nyttalegg.verbose)
    {
        cout << "verd Litil:";
        in >> nyttalegg.verdMid;
    }
    if(nyttalegg.verbose)
    {
        cout << "verd Stor:";
        in >> nyttalegg.verdStor;
    }
    return in;

}
ostream& operator << (ostream& out, const alegg skrifalegg)
{
    if(skrifalegg.verbose)
    {
        cout << "Nafn:";
    }
    out << skrifalegg.nafn << endl;

    if(skrifalegg.verbose)
    {
        cout << "tegund:";
    }
    out << skrifalegg.tegund << endl;

    if(skrifalegg.verbose)
    {
        cout << "verd Litil: ";
    }
    out << skrifalegg.verdLitil << endl;
    if(skrifalegg.verbose)
    {
        cout << "verd Mid :";
    }
    out << skrifalegg.verdMid << endl;
    if(skrifalegg.verbose)
    {
        cout << "verd Stor:";
    }
    out << skrifalegg.verdStor << endl;
    return out;
}
