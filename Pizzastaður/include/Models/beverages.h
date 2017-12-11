#ifndef BEVERAGES_H
#define BEVERAGES_H

#include <iostream>

using namespace std;

class Beverages
{
    public:
        Beverages();
        Beverages(char name , int verd , char size);

        friend ostream& operator << (ostream& out, const Beverages& beverages);
        friend istream& operator >>(istream& in, Beverages& beverages);

        char* getName();
        int getPriceSmall();
        int getPriceMedium();
        int getPriceLarge();

    private:
        char name[20];
        int smallPrice; /// 0.5L
        int midPrice;   /// 1.5L
        int bigPrice;   /// 2.0L
};

#endif // BEVERAGES_H
