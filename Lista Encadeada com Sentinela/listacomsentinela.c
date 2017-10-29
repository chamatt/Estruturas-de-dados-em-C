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



Item* inicializaItem(float valor);
void imprimeItem(Item* i);
void liberaItem(Item* i);


Lista* criaLista();
Lista* insereLista(Lista* l, Item* i);
Item* retiraLista(Lista* l, Item* i);
void imprimeLista(Lista* l);
int vaziaLista(Lista* l);
void liberaLista(Lista* l);
