#include <stdio.h>
#include "pilhacomvetor.h"

int main()
{

    Pilha* p = criaPilha();

    imprimePilha(p);

    Item* item1= inicializaItem(10.24);
    Item* item2= inicializaItem(50.55);
    Item* item3= inicializaItem(20.0);
    Item* item4= inicializaItem(48);
    Item* item5= inicializaItem(19);
    Item* item6= inicializaItem(100.1);
    Item* item7= inicializaItem(97.3);
    Item* item8= inicializaItem(1.23);
    Item* item9= inicializaItem(3.14);
    Item* item10= inicializaItem(74.91);
    Item* item11= inicializaItem(24.24);

    pushPilha(p, item1);
    pushPilha(p, item2);
    pushPilha(p, item3);
    pushPilha(p, item4);
    pushPilha(p, item5);
    pushPilha(p, item6);
    pushPilha(p, item7);
    pushPilha(p, item8);
    pushPilha(p, item9);
    pushPilha(p, item10);
    pushPilha(p, item11);

    printf ("---------- Imprime pilha-----------\n");
    imprimePilha(p);

    Item* retirado = popPilha(p);

    imprimePilha(p);

    liberaPilha(p);

}
