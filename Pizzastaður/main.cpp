#include <iostream>
#include <fstream>
#include "./ui/mainui.h"
using namespace std;
///when you clone the project for the first time u need to delete the old cpp and h files and right click on project and press add file recursively and pick the project path
///don't know how to fix so this just loads on start up

int main()
{
///Veit ekki hvort �a� er h�gt a� skrifa og prenta pizzur � menu eins og eg er a� gera (nota bara nafn �r toppings classanum) - spyrja uti �a�
///og s��an er �g me� breytu � pizzu sem tilgreynir hvort pizzan s� � menu e�a ekki, ef a menu �� gefir henni nafn , veit ekki hvort �a� er h�gt a� hafa �a� svolei�is
///G�ti veri� einhva� vesen �egar �g reyni a� lesa binary files �annig , s.s �a� er gert r�� fyrir a� �a� s� veri� a lesa einhva� sem er jafn m�rg byte og allur classin en si�an nota eg ekki allan classan

    MainUI mainui;
    mainui.startUI();

    return 0;
}
