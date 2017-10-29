#ifndef LISTA_SIMPLES
#define LISTA_SIMPLES

typedef struct item Item;
typedef struct lista Lista;


Item* CriaItem();
Item* inicializaItem(float valor);
void liberaItem(Item* item);
void imprimeItem(Item* item);

/* 
Cria uma Lista Vazia (com valor null)
*/
Lista* criaLista();
Lista* insereLista(Lista* lista, Item* item);
Item* retiraLista(Lista* lista, Item* item);
void imprimeLista(Lista* lista);
int vaziaLista(Lista* lista);
void liberaLista(Lista* lista);


#endif