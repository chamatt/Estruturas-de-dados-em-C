#include <stdio.h>
#include <stdlib.h>
#include "listasimples.h"

int main(){
	Item* item[3];
	item[0] = inicializaItem(10.2);
	item[1] = inicializaItem(14.5);
	item[2] = inicializaItem(25.6);
	Lista* lista = criaLista();
	imprimeLista(lista);
	lista = insereLista(lista, item[0]);
	lista = insereLista(lista, item[1]);
	lista = insereLista(lista, item[2]);
	Item* aux;
	aux = retiraLista(lista, item[1]);
	aux = retiraLista(lista, item[1]);
	aux = retiraLista(lista, item[1]);
	aux = retiraLista(lista, item[1]);
	aux = retiraLista(lista, item[1]);
	aux = retiraLista(lista, item[1]);
	aux = retiraLista(lista, item[1]);
	aux = retiraLista(lista, item[1]);
	imprimeLista(lista);
	liberaLista(lista);

	return 0;
}