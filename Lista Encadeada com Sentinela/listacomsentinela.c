#include <stdio.h>
#include <stdlib.h>
#include "listacomsentinela.h"



struct lista{
	struct celula* ini;
	struct celula* fim;
};
struct celula{
	Item* item;
	struct celula* prox;
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


Lista* criaLista(){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->ini = NULL;
	l->fim = NULL;
	return l;
}

Lista* insereListaInicio(Lista* l, Item* i){
	Celula* novo = (Celula*) malloc(sizeof(Celula));
	Celula* aux;
	if(l->ini == NULL){
		l->ini = novo;
		l->fim = novo;
	}
	else{
		novo->prox = l->ini;
		l->ini = novo;
	}
	novo->item = i;
	l->fim->prox = NULL;
	return l;
}
Lista* insereListaFim(Lista* l, Item* i){
	Celula* novo = (Celula*) malloc(sizeof(Celula));
	Celula* aux;
	if(l->ini == NULL){
		l->ini = novo;
		l->fim = novo;
	}
	else{
		l->fim->prox = novo;
		l->fim = novo;
	}
	novo->item = i;
	l->fim->prox = NULL;
	return l;
}


Item* retiraLista(Lista* l, Item* i){
	Celula* ant = NULL;
	Celula* p = l->ini;
	while(p != NULL && p->item != i){
		ant = p;
		p = p->prox;
	}
	if(p == NULL){
		printf("Elemento nao encontrado!\n");
		return NULL;
	}
	else if(ant == NULL){
		l->ini = p->prox;
	}
	else{
		ant->prox = p->prox;
		return p->item;
	}
	return p->item;
}
void imprimeLista(Lista* l){
	Celula* aux = l->ini;
	if(aux == NULL)
		printf("Lista Vazia!\n");
	while(aux != NULL){
		imprimeItem(aux->item);
		aux = aux->prox;
	}
}
int vaziaLista(Lista* l){
	return (l->ini == NULL);
}
void liberaLista(Lista* l){
	Celula* aux = l->ini;
	Celula* aux2 = aux;
	while(aux != NULL){
		liberaItem(aux->item);
		aux2 = aux->prox;
		free(aux);
		aux = aux2;
	}
	free(l);
}
