#ifndef ALEGGREPOSITORY_H
#define ALEGGREPOSITORY_H
#include "alegg.h"
#include <vector>

class AleggRepository
{
    public:
        AleggRepository();

        void storeAlegg( alegg topping);
        void readTopList();
        void printTopList(vector<alegg> vectorAlegg);
        void printTopListStandard();

    protected:

    private:
        vector<alegg> vectorAlegg;
};

#endif // ALEGGREPOSITORY_H
