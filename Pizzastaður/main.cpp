#include <iostream>
#include <fstream>
#include "./ui/mainui.h"
using namespace std;
///when you clone the project for the first time u need to delete the old cpp and h files and right click on project and press add file recursively and pick the project path
///don't know how to fix so this just loads on start up

int main()
{
///Veit ekki hvort það er hægt að skrifa og prenta pizzur á menu eins og eg er að gera (nota bara nafn úr toppings classanum) - spyrja uti það
///og síðan er ég með breytu í pizzu sem tilgreynir hvort pizzan sé á menu eða ekki, ef a menu þá gefir henni nafn , veit ekki hvort það er hægt að hafa það svoleiðis
///Gæti verið einhvað vesen þegar ég reyni að lesa binary files þannig , s.s það er gert ráð fyrir að það sé verið a lesa einhvað sem er jafn mörg byte og allur classin en siðan nota eg ekki allan classan

    MainUI mainui;
    mainui.startUI();

    return 0;
}
