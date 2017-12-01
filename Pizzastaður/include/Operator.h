#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <string>
using namespace std;

class Operator
{
    public:
        Operator();
        friend istream& operator >> (istream& in, Operator& currentOperator);
        void setUserID();
        int getUserID();

    private:
        string user;
        int currentUserID;
};

#endif // OPERATOR_H
