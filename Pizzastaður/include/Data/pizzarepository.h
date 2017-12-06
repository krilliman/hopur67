#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "pizza.h"
#include "menu.h"

class PizzaRepository
{
    public:
        PizzaRepository();
        virtual ~PizzaRepository();


    void storePizza(const Pizza& pizza);
    Pizza readPizza();

    void storeMenu(const Menu& menu);
    Menu readMenu();
    protected:

    private:
};

#endif // PIZZAREPOSITORY_H
