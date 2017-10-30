#include <stdio.h>
#include <stdlib.h>
#include "pilhacomvetor.h"
#define MAX 10;

struct pilha{
  int topo;
  Item vet[MAX];
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
  pilha->topo = 0;
}

Pilha* pushPilha(Pilha* p, Item* item){
  p->vet[p->topo] = item;
  p->topo++;
  return p;
}
Item* popPilha(Pilha* p, Item* item){
  p->topo--;
  return p;
}
void imprimePilha(Pilha* p){
  for(i = 0; i < p->topo; i++){
    imprimeItem(p->vet[i]);
  }
}
void liberaPilha(Pilha* p){
  free(p);
}
