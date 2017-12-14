#ifndef BEVERAGES_H
#define BEVERAGES_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Beverages
{
    public:
        Beverages();
        Beverages(char name , int verd , char size);

        friend ostream& operator << (ostream& out, const Beverages& beverages);
        friend istream& operator >>(istream& in, Beverages& beverages);

        void writeBeverage(ofstream &fout);
        void readBeverage(ifstream &fin);

        string getName();
        string getPrice();

        void setName(string name);
        void setPrice(string price);

    private:
        string name;
        string price;
};

#endif // BEVERAGES_H
