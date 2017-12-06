#ifndef BEVERAGES_H
#define BEVERAGES_H

#include <iostream>

using namespace std;

class Beverages
{
    public:
        Beverages();
        Beverages(char name , int verd , char size);

        char getName();
        int getVerd();
        char getSize();

        friend ostream& operator << (ostream& out, const Beverages& beverages);

    private:
        char name;
        int verd;
        char size;
};

#endif // BEVERAGES_H
