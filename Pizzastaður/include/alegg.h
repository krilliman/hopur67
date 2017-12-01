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
        void setAddOrNot(bool n);





    private:
        char nafn[20];
        int verdLitil;
        int verdMid;
        int verdStor;
        bool addOrNot;
};

#endif // ALEGG_H
