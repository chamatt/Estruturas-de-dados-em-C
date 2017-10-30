#include <stdio.h>
#include <stdlib.h>
#include "pilhacomlista.h"


struct item{
	float valor;
};
Item* inicializaItem(float valor){
	Item* i = (Item*) malloc(sizeof(Item));
	i->valor = valor;
	return i;
}

void imprimeItem(Item* i){
	printf("%.2f\n", i->valor);
}

void liberaItem(Item* i){
	free(i);
}
