#include "Operator.h"

Operator::Operator()
{
   user = "";
   currentUserID = 0;
}
int Operator::getUserID()
{
    return currentUserID;
}
void Operator::setUserID()
{
    if(user == "Umsjon" || user == "umsjon")
    {
        currentUserID = 4;
    }
    else if(user == "Sala" || user == "sala")
    {
       currentUserID = 3;
    }
    else if(user == "Bakstur" || user == "bakstur")
    {
        currentUserID = 2;
    }
    else if(user == "Afhending" || user == "afhending")
    {
        currentUserID = 1;
    }
}
istream& operator >> (istream& in, Operator& currentOperator)
{
    cout << "Current User: ";
    in >> currentOperator.user;
    return in;
}


