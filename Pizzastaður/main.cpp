#include <iostream>
#include <fstream>
#include "mainui.h"
using namespace std;


int main()
{
///Veit ekki hvort �a� er h�gt a� skrifa og prenta pizzur � menu eins og eg er a� gera (nota bara nafn �r toppings classanum) - spyrja uti �a�
///og s��an er �g me� breytu � pizzu sem tilgreynir hvort pizzan s� � menu e�a ekki, ef a menu �� gefir henni nafn , veit ekki hvort �a� er h�gt a� hafa �a� svolei�is
///G�ti veri� einhva� vesen �egar �g reyni a� lesa binary files �annig , s.s �a� er gert r�� fyrir a� �a� s� veri� a lesa einhva� sem er jafn m�rg byte og allur classin en si�an nota eg ekki allan classan
///Komast a� �v� hvernig �a� er h�gt a� lesa �r skr�m inni fylki, vantar a� laga �a� � topping List , Side Order List og Menu(menu er bara fattla� yfir h�fu�).
    MainUI mainui;
    mainui.startUI();

    return 0;
}
