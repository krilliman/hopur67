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
        void setVerbose(bool v);



    private:
        char nafn[20];
        char tegund[20];
        int verdLitil;
        int verdMid;
        int verdStor;

        bool verbose = true;
};

#endif // ALEGG_H
