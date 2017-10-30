#include <stdio.h>
#include "pilhacmvetor.h"

int main()
{

    Pilha* p = cria_pilha();

    imprime_pilha(p);

    Pessoa* pessoa1= inicializaItem(10.24);
    Pessoa* pessoa2= inicializaItem(50.55);
    Pessoa* pessoa3= inicializaItem(20.0);
    Pessoa* pessoa4= inicializaItem(48);
    Pessoa* pessoa5= inicializaItem(19);
    Pessoa* pessoa6= inicializaItem(100.1);
    Pessoa* pessoa7= inicializaItem(97.3);
    Pessoa* pessoa8= inicializaItem(1.23);
    Pessoa* pessoa9= inicializaItem(3.14);
    Pessoa* pessoa10= inicializaItem(74.91);
    Pessoa* pessoa11= inicializaItem(24.24);

    pushPilha(pessoa1, p);
    pushPilha(pessoa2, p);
    pushPilha(pessoa3, p);
    pushPilha(pessoa4, p);
    pushPilha(pessoa5, p);
    pushPilha(pessoa6, p);
    pushPilha(pessoa7, p);
    pushPilha(pessoa8, p);
    pushPilha(pessoa9, p);
    pushPilha(pessoa10, p);
    pushPilha(pessoa11, p);

    printf ("---------- Imprime pilha-----------\n");
    imprime_pilha(p);

    Pessoa* retirado = popPilha(p);

    imprime_pilha(p);

    p = destroi_pilha(p);

}
