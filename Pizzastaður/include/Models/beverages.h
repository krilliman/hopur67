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
        int getPrice();

    private:
        char name[32];
        int price;
};

#endif // BEVERAGES_H
