#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "pizza.h"
#include "menu.h"

class PizzaRepository
{
    public:
        PizzaRepository();

    void storePizza(const Pizza& pizza);
    void readPizza();
    void printPizza(vector<Pizza> pizzas);
    void printAllPizzas();



    void storeMenu(const Menu& menu);
    void readMenu();
    void printMenu();
    private:
        vector<Menu> menuList;
        vector<Pizza> pizzas;

};

#endif // PIZZAREPOSITORY_H
