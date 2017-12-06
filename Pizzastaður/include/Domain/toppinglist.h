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
        void getToppingList();

        //void setList();
        //void printList();

    private:
       // int addToList;
        alegg ToppingToAdd;
        alegg *toppinglist;
        int listLength;
        bool add;
};

#endif // TOPPINGLIST_H
