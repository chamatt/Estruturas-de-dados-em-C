#include <stdio.h>
#include <stdlib.h>
#include "pilhacomvetor.h"
#define MAX 10

struct pilha{
  int topo;
  struct item* vet[MAX];
};
struct item{
    float valor;
};

Item* inicializaItem(float valor){
  Item* item = (Item*) malloc(sizeof(Item));
  item->valor = valor;
  return item;
}
void imprimeItem(Item* item){
  printf("%.2f\n", item->valor);
}
void liberaItem(Item* item){
  free(item);
}



Pilha* criaPilha(){
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  p->topo = 0;
}

Pilha* pushPilha(Pilha* p, Item* item){
  if(p->topo >= MAX){
    printf("Stack Overflow");
    return p;
  }
  p->vet[p->topo] = item;
  p->topo++;
  return p;
}
Item* popPilha(Pilha* p){
  Item* aux;
  p->topo--;
  return p->vet[p->topo-1];
}
void imprimePilha(Pilha* p){
  int i;
  for(i = 0; i < p->topo; i++){
    imprimeItem(p->vet[i]);
  }
}
void liberaPilha(Pilha* p){
  int i;
  for(i=0;i<p->topo;i++){
    liberaItem(p->vet[i]);
  }
  free(p);
}
