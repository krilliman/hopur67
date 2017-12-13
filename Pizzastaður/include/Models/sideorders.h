#ifndef SIDEORDERS_H
#define SIDEORDERS_H
#include <iostream>
#include <fstream>

using namespace std;

class SideOrders
{
    public:
        SideOrders();

        friend ostream& operator <<(ostream& out, const SideOrders sideorders);
        friend istream& operator >> (istream& in, SideOrders& sideorders);

        int getPrice();

    private:
        char name[32];
        int price;

};

#endif // SIDEORDERS_H
