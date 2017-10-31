#include <stdio.h>
#include <stdlib.h>
#include "pilhacomlista.h"

struct pilha{
	Item* item;
	Pilha* prox;
};

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


Pilha* criaPilha(){
	return NULL;
}

Pilha* pushPilha(Pilha* p, Item* i){
	Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
	novo->prox = p;
	novo->item = i;
	return novo;
}

Pilha* popPilha(Pilha* p){
	if(p == NULL)
		return NULL;
	Pilha* inicio = p->prox;
	liberaItem(p->item);
	free(p);
	return inicio;
} 

void imprimePilha(Pilha* p){
	if(p == NULL)
		return;
	imprimePilha(p->prox);
	imprimeItem(p->item);
}

void liberaPilha(Pilha* p){
	Pilha* aux;
	while(p!=NULL){
		aux = p->prox;
		liberaItem(p->item);
		free(p);
		p = aux;
	}
}
