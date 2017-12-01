#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    string string_input;
    ofstream input;
    char check = '\\';
    int finder = 10;

    input.open("test222.txt", fstream::app);


    while(finder != 0)
    {
        getline(cin,string_input);
        finder = string_input.find(check);

        if(finder != 0)
        {
            input << "\n";
            input << string_input;
        }
    }


    input.close();
    return 0;
}
