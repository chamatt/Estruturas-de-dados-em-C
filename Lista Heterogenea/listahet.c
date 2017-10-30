#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listahet.h"
#define MOV 1
#define IMOV 2


/*Estrutura Cliente(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - nome (string)
  - id (int)
  */
struct cliente{
   char* nome;
   int id;
};

/*Estrutura Movel(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - placa (int)
  - ano (int)
  - valor (float)
  */
struct movel{
  int placa;
  int ano;
  float valor;
};


/*Estrutura Imovel(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - identificador (int)
  - ano (int)
  - valor (float)
  */
struct imovel{
  int identificador;
  int ano;
  float valor;
};


/*Tipo que define a lista heterogenea(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.  Use o ponteiro genérico para implementar a lista (void*)
  Campos da celula da lista: 
   - dono (Cliente*)
   - item (void*)
   - Prox (struct listahet*)
   - identificador do item (int)
*/
struct listahet{
  Cliente* dono;
  void* item;
  struct listahet* prox;
  int tipo;
};

/*Cria lista vazia
* inputs: nenhum
* output: lista vazia
* pre-condicao: nenhuma
* pos-condicao: lista criada e vazia
*/
ListaHet* cria (){
  ListaHet* h = NULL;
  return h; 
}

/*Cria uma estrutura do tipo Cliente
* inputs: nome do cliente e o identificador do cliente
* output: Endereço da estrutura cliente criada
* pre-condicao: nome e id validos
* pos-condicao: estrutura cliente criada, com os campos nome e id corretamente atribuidos
*/
Cliente* cria_cliente (char* nome, int id){
  Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
  cliente->nome = nome;
  cliente->id = id;
  return cliente;
}


/*Cria uma estrutura do tipo Movel
* inputs: placa, ano de fabricacao e valor do automovel 
* output: Endereço da estrutura movel criada
* pre-condicao: placa, ano e valor validos
* pos-condicao: estrutura movel criada
*/
Movel* cria_movel (int placa, int ano, float valor){
  Movel* movel = (Movel*) malloc(sizeof(Movel));
  movel->placa = placa;
  movel->ano = ano;
  movel->valor = valor;
  return movel;
}

/*Cria uma estrutura do tipo Imovel
* inputs: identificador, ano de construcao e o valor do imovel
* output: Endereço da estrutura imovel criada
* pre-condicao: id, ano e valor validos
* pos-condicao: estrutura imovel criada
*/
Imovel* cria_imovel (int id, int ano, float valor){
  Imovel* imovel = (Imovel*) malloc(sizeof(Imovel));
  imovel->identificador = id;
  imovel->ano = ano;
  imovel->valor = valor;
  return imovel;
}

/*Insere um item (do tipo Movel) na primeira posicao da lista 
* inputs: a lista, o cliente dono do automovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e automovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item){
  ListaHet* h = (ListaHet*) malloc(sizeof(ListaHet));
  h->prox = lista;
  h->tipo = MOV;
  h->item = item;
  h->dono = dono;
  return h;
}


/*Insere um item (do tipo Imovel) na primeira posicao da lista 
* inputs: a lista, o cliente dono do imovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e imovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item){
  ListaHet* h = (ListaHet*) malloc(sizeof(ListaHet));
  h->prox = lista;
  h->tipo = IMOV;
  h->item = item;
  h->dono = dono;
  return h;
}

/*Imprime os elementos da lista. Para cada elemento da lista, deve-se imprimir os dados do Cliente, seguido dos dados do imóvel (caso o item seja um imóvel) ou dos dados do automóvel (caso o item seja um movel)
* inputs: a lista
* output: nao tem
* pre-condicao: lista valida
* pos-condicao: lista inalterada
*/
void imprime (ListaHet* lista){
  ListaHet* aux = lista;
  if(lista == NULL){
    printf("Lista Vazia!\n");
    return;
  }
  while(aux != NULL){
    printf("Nome do Cliente: %s  -  ID: %d\n", aux->dono->nome, aux->dono->id);
    if(aux->tipo == MOV){
      Movel* movel = (Movel*) aux->item;
      printf("Movel ->  Placa: %d  -  Ano: %d  -  Valor: R$ %.2f\n\n", movel->placa, movel->ano, movel->valor);
    }
    else if(aux->tipo == IMOV){
      Imovel* imovel = (Imovel*) aux->item;
      printf("Movel ->  Placa: %d  -  Ano: %d  -  Valor: R$ %.2f\n\n", imovel->identificador, imovel->ano, imovel->valor);
    }
    aux = aux->prox;
  }
}

/*Retira da lista todos os itens assegurados de um dado cliente 
* inputs: a lista e o identificador do cliente
* output: lista atualizada
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista nao contem itens do cliente cujo identificador eh id_cliente
*/
ListaHet* retira_cliente (ListaHet* lista, int id_cliente){
  ListaHet* ant = NULL;
  ListaHet* p;
  for(p = lista; p != NULL; ant = p, p = p->prox){
    if(p->dono->id == id_cliente){
      if(ant == NULL){
        lista = p->prox;
      }
      else{
        ant->prox = p->prox;
        p = ant;
      }
    }
  }
  if(p == NULL){
    printf("Elemento nao encontrado\n");
  }
  return lista;
}

/*Calcula o valor total assegurado de um dado cliente (incluindo moveis e imoveis). Note que o valor assegurado depende da taxa estipulada para o tipo do item. O calculo do valor assegurado para UM dado item deve ser: valor_item*taxa_item
* inputs: a lista, o endereco do cliente, e as taxas para o calculo do valor assegurado. 
* output: valor total assegurado, que deve ser a soma dos valores assegurados de todos os itens do dado cliente
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista inalterada
*/
float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel){
  float valor_assegurado = 0;
  ListaHet* p;
  for(p = lista; p != NULL; p = p->prox){
    if(p->dono->id == dono->id){
      if(p->tipo == MOV){
        Movel* movel = (Movel*) p->item;
        valor_assegurado += (movel->valor*taxa_movel); 
      }
      if(p->tipo == IMOV){
        Imovel* imovel = (Imovel*) p->item;
        valor_assegurado += (imovel->valor*taxa_imovel); 
      }
    }
  }
  return valor_assegurado;
}