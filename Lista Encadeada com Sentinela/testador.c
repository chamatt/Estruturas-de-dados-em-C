#include <stdio.h>
#include <stdlib.h>
#include "listacomsentinela.h"

int main(){
	Item* item[3];
	item[0] = inicializaItem(10.2);
	item[1] = inicializaItem(14.5);
	item[2] = inicializaItem(25.6);
	Lista* lista = criaLista();
	imprimeLista(lista);
	lista = insereListaInicio(lista, item[0]);
	lista = insereListaInicio(lista, item[1]);
	lista = insereListaInicio(lista, item[2]);
	imprimeLista(lista);
	retiraLista(lista, item[0]);
	retiraLista(lista, item[1]);
	retiraLista(lista, item[2]);
	lista = insereListaFim(lista, item[0]);
	lista = insereListaFim(lista, item[1]);
	lista = insereListaFim(lista, item[2]);
	imprimeLista(lista);
	liberaLista(lista);

	return 0;
}