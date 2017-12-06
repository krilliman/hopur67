#ifndef MENU_H
#define MENU_H
#include "pizza.h"
#include <fstream>
class Menu
{
    public:
        Menu();
        virtual ~Menu();

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        void setListMemory(int menuLength);
        void setPizzaToAdd(Pizza newPizza);




    protected:

    private:
        Pizza addPizza;
        Pizza *pizzaMenu;
        int menuLength;
};

#endif // MENU_H
