#ifndef ALEGG_H
#define ALEGG_H
#include <iostream>
#include <fstream>
using namespace std;

class alegg
{
    public:
        alegg();
        friend istream& operator >> (istream& in, alegg& nyttalegg);
        friend ostream& operator << (ostream& out, const alegg skrifalegg);

        string getName();
        string getPriceSmall();
        string getPriceMedium();
        string getPriceLarge();

        void writeAlegg(ofstream &fout);
        void readAlegg(istream &fin);

        void setName(string name);
        void setPriceSmall(string priceLittle);
        void setPriceMiddle(string priceMiddle);
        void setPriceLarge(string priceLarge);


    private:
        string name;
        string priceLittle;
        string priceMiddle;
        string priceLarge;
};

#endif // ALEGG_H
