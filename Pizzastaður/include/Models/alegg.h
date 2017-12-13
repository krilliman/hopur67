#ifndef ALEGG_H
#define ALEGG_H
#include <iostream>
using namespace std;

class alegg
{
    public:
        alegg();
        friend istream& operator >> (istream& in, alegg& nyttalegg);
        friend ostream& operator << (ostream& out, const alegg skrifalegg);

        char* getName();
        int getPriceSmall();
        int getPriceMedium();
        int getPriceLarge();


    private:
        char nafn[32];
        int verdLitil;
        int verdMid;
        int verdStor;
};

#endif // ALEGG_H
