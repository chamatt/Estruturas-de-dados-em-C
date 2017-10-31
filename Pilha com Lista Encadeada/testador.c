#include <stdio.h>
#include "pilhacomlista.h"

int main()
{

    Pilha* p = criaPilha();

    imprimePilha(p);
    Item* item1 = inicializaItem(10.24);
    Item* item2 = inicializaItem(50.55);
    Item* item3 = inicializaItem(20.0);
    Item* item4 = inicializaItem(48);
    Item* item5 = inicializaItem(19);
    Item* item6 = inicializaItem(100.1);
    Item* item7 = inicializaItem(97.3);
    Item* item8 = inicializaItem(1.23);
    Item* item9 = inicializaItem(3.14);
    Item* item10 = inicializaItem(74.91);
    Item* item11 = inicializaItem(24.24);
    p = pushPilha(p, item1);
    p = pushPilha(p, item2);
    p = pushPilha(p, item3);
    p = pushPilha(p, item4);
    p = pushPilha(p, item5);
    p = pushPilha(p, item6);
    p = pushPilha(p, item7);
    p = pushPilha(p, item8);
    p = pushPilha(p, item9);
    p = pushPilha(p, item10);
    p = pushPilha(p, item11);
    printf ("---------- Imprime pilha-----------\n");
    imprimePilha(p);
    p = popPilha(p);

    imprimePilha(p);

    liberaPilha(p);

}
