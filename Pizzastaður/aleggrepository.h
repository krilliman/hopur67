#ifndef ALEGGREPOSITORY_H
#define ALEGGREPOSITORY_H
#include "alegg.h"
#include "toppinglist.h"

class AleggRepository
{
    public:
        AleggRepository();
        virtual ~AleggRepository();

        void storeAlegg( ToppingList toppinglist);
        ToppingList getTopList();
    protected:

    private:
};

#endif // ALEGGREPOSITORY_H
