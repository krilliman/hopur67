#ifndef TOPPINGLIST_H
#define TOPPINGLIST_H
#include "alegg.h"
#include <iostream>
#include <fstream>

class ToppingList
{
    public:
        ToppingList();
        virtual ~ToppingList();


        void read(ifstream& fin);
        void write(ofstream& fout);
        //void addSizeSet(int addSize);


        void setToppingToAdd(alegg ToppingToAdd);
        void setListMemory(int memory);

    protected:

    private:
       // int addToList;
        alegg ToppingToAdd;
        alegg *toppinglist;
        int listLength;
        bool add;
};

#endif // TOPPINGLIST_H
