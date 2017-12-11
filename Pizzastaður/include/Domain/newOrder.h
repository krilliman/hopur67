#ifndef NEWORDER_H
#define NEWORDER_H
#include <pizza.h>
#include <beverageslist.h>
#include <sideorderlist.h>
#include <extrasrepository.h>
#include <pizzarepository.h>

class newOrder
{
    public:
        newOrder();

        friend istream& operator >>(istream& in, newOrder neworder);
        friend ostream& operator <<(ostream& out, newOrder neworder);


    private:
        vector<Pizza> pizzaVector;
        vector<SideOrderList> sideOrderVector;
        vector<Beverageslist> beverageVector;
};

#endif // NEWORDER_H
