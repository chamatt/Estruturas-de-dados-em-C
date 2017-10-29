#include <stdio.h>
#include <stdlib.h>
#include "listasimples.h"


struct item{
	float valor;
};
struct lista{
	struct lista* prox;
	struct item* item;
};

Item* inicializaItem(float valor){
	Item* obj = (Item*) malloc(sizeof(Item));
	obj->valor = valor;
	return obj;
}

void liberaItem(Item* item){
	free(item);
}

void imprimeItem(Item* item){
	printf("%.2f\n", item->valor);
}



Lista* criaLista(){
	return NULL;
}

Lista* insereLista(Lista* lista, Item* item){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->prox = lista;
	novo->item = item;
	return novo;
}


Item* retiraLista(Lista* lista, Item* item){
	Lista* ant = NULL;
	Lista* p = lista;
	while(p != NULL && p->item != item){
		ant = p;
		p = p->prox;
	}
	
	if(p == NULL){
		printf("Elemento nao encontrado\n");
		return NULL;
	}
	if(ant == NULL){
		lista = p->prox;
	}
	else{
		ant->prox = p->prox;
	}
	return p->item;

}
void imprimeLista(Lista* lista){
	if(lista == NULL){
		printf("Lista Vazia!\n");
		return;
	}
	while(lista != NULL){
		imprimeItem(lista->item);
		lista = lista->prox;
	}
}

int vaziaLista(Lista* lista){
	return (lista==NULL);
}

void liberaLista(Lista* lista){
	Lista* aux = lista;
	while(lista != NULL){
		aux = lista;
		lista = lista->prox;
		liberaItem(aux->item);
		free(aux);
	}
}