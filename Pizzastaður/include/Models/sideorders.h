#ifndef SIDEORDERS_H
#define SIDEORDERS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SideOrders
{
    public:
        SideOrders();

        friend ostream& operator <<(ostream& out, const SideOrders sideorders);
        friend istream& operator >> (istream& in, SideOrders& sideorders);

        void writeSideOrder(ofstream &fout);
        void readSideOrder(ifstream &fin);

        string getPrice();
        string getName();
        void setName(string name);
        void setPrice(string Price);

    private:
        string name;
        string Price;

};

#endif // SIDEORDERS_H
