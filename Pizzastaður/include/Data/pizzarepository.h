#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "pizza.h"
#include "menu.h"

class PizzaRepository
{
    public:
        PizzaRepository();

    void storePizza(Pizza& pizza);
    void readPizza();
    void printPizza(vector<Pizza> pizzas);
    void printAllPizzas();



    void storeMenu(Menu& menu);
    void readMenu();

    int selectFromMenu();
    Menu selectElementFromMenu(int element);

    private:
        vector<Menu> menuList;
        vector<Pizza> pizzas;

};

#endif // PIZZAREPOSITORY_H
