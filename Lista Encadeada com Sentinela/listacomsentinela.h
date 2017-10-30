#ifndef LISTA_COM_SENTINELA
#define LISTA_COM_SENTINELA

typedef struct lista Lista;
typedef struct celula Celula;
typedef struct item Item;



Item* inicializaItem(float valor);
void imprimeItem(Item* i);
void liberaItem(Item* i);


Lista* criaLista();
Lista* insereListaInicio(Lista* l, Item* i);
Lista* insereListaFim(Lista* l, Item* i);
Item* retiraLista(Lista* l, Item* i);
void imprimeLista(Lista* l);
int vaziaLista(Lista* l);
void liberaLista(Lista* l);


#endif