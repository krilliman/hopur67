#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string test;
    char input;
    int counter = 0;
    ifstream ins;

    ins.open("test.txt");

    while(input != 'n' && !ins.eof())
    {
        cout << "choose y for next 10 lines and n to quit: ";
        cin >> input;
        if(input == 'y')
        {
            while(counter != 10 && !ins.eof())
            {
                getline(ins,test);
                cout << test << endl;
                counter++;
            }
            if(counter == 10)
            {
                counter = 0;
            }
            cout << endl;
        }
        else
        {
            cout << "Invalid input " << endl;
        }
    }
    ins.close();




    return 0;
}
