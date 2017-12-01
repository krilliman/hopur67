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

        friend ostream& operator <<(ostream& out , ToppingList toppinglist);

        void setToppingToAdd(alegg ToppingToAdd);
        void setListMemory(int memory);

    protected:

    private:
       // int addToList;
        alegg ToppingToAdd;
        alegg *toppinglist;
        int listLength;
};

#endif // TOPPINGLIST_H
