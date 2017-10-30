#ifndef PILHA_COM_VETOR
#define PILHA_COM_VETOR

typedef struct pilha Pilha;
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
