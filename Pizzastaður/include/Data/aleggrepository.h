#ifndef ALEGGREPOSITORY_H
#define ALEGGREPOSITORY_H
#include "alegg.h"

class AleggRepository
{
    public:
        AleggRepository();
        virtual ~AleggRepository();

        void storeAlegg( alegg topping);
        alegg* getTopList();
    protected:

    private:
};

#endif // ALEGGREPOSITORY_H
