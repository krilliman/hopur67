#ifndef TOPPINGLIST_H
#define TOPPINGLIST_H
#include "alegg.h"
#include "aleggrepository.h"

#include <fstream>

class ToppingList
{
    public:
        ToppingList();
        virtual ~ToppingList();

        void setNewTopping(alegg newTopping);
        alegg getToppingList();


    private:
};

#endif // TOPPINGLIST_H
