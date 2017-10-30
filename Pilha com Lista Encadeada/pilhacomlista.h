#ifndef PILHA_COM_LISTA
#define PILHA_COM_LISTA

typedef struct pilha Pilha;
typedef struct celula Celula;
typedef struct item Item;

Item* inicializaItem(float valor);
void imprimeItem(Item* item);
void liberaItem(Item* item);

Pilha* criaPilha();
Pilha* pushPilha(Pilha* p, Item* item);
Item* popPilha(Pilha* p, Item* item);
void imprimePilha(Pilha p*);
void liberaPilha(Pilha p*);



#endif
