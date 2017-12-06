#ifndef MATSEDILL_H
#define MATSEDILL_H

#include <fstream>
#include <iostream>
using namespace std;
class matsedill
{
    public:
        matsedill();

        friend ostream& operator << (ostream& out, matsedill listi);
        friend istream& operator >> (istream& in, matsedill& listi);


        bool check(bool verbose);

    private:
        char nafn[25];
        int verdLitil;
        int verdMid;
        int verdStor;
        bool verbose = true;
};

#endif // MATSEDILL_H
