#ifndef lista_h
#define lista_h

/* 
LISTA -> representa os pedidos realizados na confeitaria, remove no inicio e insere
no final, para entregar os pedidos na ordem em que foram feitos.
PEDIDO -> composto por 3 char, contendo sabor da massa do bolo, cobertura e enfeite
escolhidos pelo cliente
*/

#include <stdlib.h>

typedef struct {
	char base;
	char cobertura;
	char enfeite;
} Pedido;

struct node {
	Pedido item;
	struct node* ant;
	struct node* prox;
};

typedef struct {
	int maximo; // num max de pedidos por dia -> 50
	int qtd; // num de pedidos q serao realizados
	struct node* sentinela;
} lista;

int inicializaLista(lista* l, int tamMax); //dinâmica, duplamente encadeada, com sentinela e circular

void desalocaLista(lista *l);

int insereLista(lista *l, Pedido pedido); // insere no final

int removeLista(lista *l, Pedido* pedido); //remove no inicio

int vazia(lista *l);

int cheia(lista *l);

#endif