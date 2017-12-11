#ifndef MATSEDILL_H
#define MATSEDILL_H

#include <fstream>
#include <iostream>
#include <pizza.h>
#include <vector>

using namespace std;
class matsedill
{
    public:
        matsedill();

        friend ostream& operator << (ostream& out, matsedill listi);
        friend istream& operator >> (istream& in, matsedill& listi);



    private:
        char nafn[25];
        int verdLitil;
        int verdMid;
        int verdStor;
        vector<Pizza> MenuVector;

};

#endif // MATSEDILL_H
